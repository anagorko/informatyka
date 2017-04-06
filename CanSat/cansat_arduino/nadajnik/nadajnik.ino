/* QBCAN nadajnik
 * 
 * RFM-69HCW <---> arduino Pro Micro
 * MISO <--------> 14
 * MOSI <--------> 16
 * SCK <---------> 15
 * CS <----------> 10
 *
 * BMP <----------> arduino Pro Micro
 * SDA <----------> 2
 * SCL <----------> 3
 * + <------------> 3.3V
 * 
 * 
 * LFL <---------> arduino Pro Micro
 *  A0 <--------->A3 - pin analogowy
 *  SI<---------->A1 - pin cyfrowy 
 *  CLK<--------->A2
 * 
 * SD <----------> arduino Pro Micro
 * MISO <--------> 14
 * MOSI <--------> 16
 * SCK <---------> 15
 * CS <----------> 18
 * 
 */

//#define NO_SERIAL

#include <qbcan.h>

//for bmp
#include <BMP180.h>
#include <Wire.h>
//for sd card
#include <SPI.h>
#include <SD.h>
const int pin_CS = A0;
File plik;
//end sd card

#define IS_RFM69HCW   true

#define temp_zero -300 //punkt zero dla temperatury (wartość w dC)
#define pres_zero 600 //punkt zero dla ciśnienia (wartość w hPa)
#define ilosc_bajtow  255 //ilość bajtów do zapisu

unsigned int seria;
unsigned int pomiar;


const int skiprate = 8;
struct datagram
{
  unsigned char seria;
  unsigned short int pomiar;
  unsigned int temperature, pressure;
  unsigned short int lfl[256 / skiprate];
} data;



//radio
const int NodeID = 3;
const int NetworkID = 233;
const int TargetID = 1; 
//char radiostring[100];
RFM69 radio;

//lfl
const unsigned char PS_32 = (1 << ADPS2) | (1 << ADPS0);
const unsigned char PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

const int pinSI = A1;    // digital out A1
const int pinCLK = A2;   // digital out A2
const int pinAO = A3;   // analog in A3

unsigned short int pixels[256];
#define packagesize 166
//unsigned char data[packagesize];


//bmp
BMP180 pressure;
int T,P;

void get_bmp(){
  double _T,_P;
 char status = pressure.startTemperature();
 delay(status); 
 pressure.getTemperature(_T);
 T = _T * 10;
 status = pressure.startPressure(3); //2,1 or 0
 delay(status);
 status = pressure.getPressure(_P,_T);
 P = _P;
}
void ClockPulse()
{
    delayMicroseconds(60);
    digitalWrite(pinCLK, HIGH);
    digitalWrite(pinCLK, LOW);
}
  
void get_lfl(){
   digitalWrite(pinSI, HIGH);
   ClockPulse();
   digitalWrite(pinSI, LOW);  

  for (int i = 0; i < 256; i++) {
      delayMicroseconds(20);
      pixels[i] = analogRead(pinAO);
      ClockPulse();
  }

  digitalWrite(pinSI, HIGH);
  ClockPulse(); 
  digitalWrite(pinSI, LOW);

  //delay(500);

  for(int i = 0; i < 260; i++) {
      ClockPulse(); 
  }

  delay(1);
}
void send_to_radio(){
//    radio.send(TargetID,data,packagesize);
    radio.send(TargetID,(char *) &data,sizeof(datagram));
    Serial.print("datagram size ");Serial.println(sizeof(datagram));
    
//    for(int i=0;i<packagesize;i++) Serial.print((char)data[i]);
    #ifndef NO_SERIAL
    Serial.print("seria = ");Serial.print(seria);Serial.print("pomiar = ");Serial.print(pomiar);Serial.print("temperatura = ");Serial.print(T);
    Serial.print("cisnienie = ");Serial.print(P);Serial.println("#package sent");
    #endif
        
    delay(50);
}
void send_to_SD_card(){
  plik = SD.open("wyniki.csv", FILE_WRITE);
  plik.println(" ");
  plik.print(seria);    //dopisywanie numeru serii od nowej linii
  plik.print(" ");
  plik.print(pomiar);   //wpisywanie numeru pomiaru po spacji
  plik.print(" ");
  plik.print(T);   //wpisywanie temperatury po spacji
  plik.print(" ");
  plik.print(P);   //wpisywanie ciśnienia po spaji
  plik.print(" ");
  for(int i=0; i<256; i++){
    plik.print(pixels[i]);
    plik.print(" ");
  };    //wpisywanie odczytów (x256) ze spektrometru
  plik.close();

};

void kompresja( unsigned int *seria, unsigned int *pomiar, unsigned int *temp, unsigned int *pres, unsigned short int spekt[] )
{
  data.seria=*seria;
  data.pomiar=*pomiar;
  data.temperature=*temp;
  data.pressure=*pres;
  for (int i = 0; i < 256/skiprate;i++){
    data.lfl[i] = spekt[i*skiprate];
  }
}

void setup(){
  #ifndef NO_SERIAL
  Serial.begin(9600);
  #endif
  
  //tylko do testow przy komputerze
//  while(!Serial);
  delay(1000);
//  Serial.println("boot");
 
  //radio rfm
  radio.initialize(FREQUENCY,NodeID,NetworkID);
  radio.setHighPower();
//  radio.setPowerLevel(5);                           // from power output ranges from 0 (5dBm) to 31 (20dBm)
  radio.setFrequency(434600000);
  //end radio rfm
  
  //bmp
  if (pressure.begin()) {
    #ifndef NO_SERIAL
     Serial.println("BMP180 init success");
    #endif
  } else {
    #ifndef NO_SERIAL
    Serial.println("BMP180 init fail (disconnected?)\n\n");
    #endif
  }
  //endbmp
    
  //lfl
  pinMode(pinCLK, OUTPUT);
  pinMode(pinSI, OUTPUT);

  ADCSRA &= ~PS_128;  
  ADCSRA |= PS_32;

  analogReference(DEFAULT);

  for (int i = 0; i < 14; i++) digitalWrite(i, LOW);

  for (int i = 0; i < 260; i ++) ClockPulse();

  digitalWrite(pinSI, HIGH);
  ClockPulse(); 
  digitalWrite(pinSI, LOW);

  for(int i=0;i< 260;i++) ClockPulse();
  //end lfl

  //SD card
  if (!SD.begin(pin_CS)  )                                       //sprawdź czy nie ma karty na pinie ChipSelect 4
  {
     #ifndef NO_SERIAL
     Serial.println("Nie wykryto karty(ERR)");            //błąd wykrycia karty
     #endif
//     return;                                              //przerwij program
  }
  //end SD card
  
  seria = rand()%256;
  pomiar = 0;
}
  
void loop()
{
  #ifndef NO_SERIAL
  Serial.println("loop");
  #endif
  
  pomiar++;

  get_bmp();
  get_lfl();

  kompresja( &seria, &pomiar,&T, &P, pixels );
  send_to_radio();
  send_to_SD_card();
  delay(500);  
}

