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
 
#include <qbcan.h>

//for bmp
#include <SFE_BMP180.h>
#include <Wire.h>
//for sd card
#include <SPI.h>
#include <SD.h>
constexpr int pin_CS = 4;
File plik;
//end sd card

#define IS_RFM69HCW   true

#define temp_zero -300 //punkt zero dla temperatury (wartość w dC)
#define pres_zero 600 //punkt zero dla ciśnienia (wartość w hPa)
#define ilosc_bajtow  255 //ilość bajtów do zapisu

int seria;
int pomiar;

//radio
constexpr int NodeID = 3;
constexpr int NetworkID = 233;
constexpr int TargetID = 1; 
char radiostring[100];
RFM69 radio;

//lfl
const unsigned char PS_32 = (1 << ADPS2) | (1 << ADPS0);
const unsigned char PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

const int pinSI = A1;    // digital out A1
const int pinCLK = A2;   // digital out A2
const int pinAO = A3;   // analog in A3

short int pixels[256];
#define packagesize 166
char data[packagesize];

//bmp
SFE_BMP180 pressure;
double T,P;

void get_bmp(){
 char status = pressure.startTemperature();
 delay(status); 
 pressure.getTemperature(T);
 status = pressure.startPressure(3); //2,1 or 0
 delay(status);
 status = pressure.getPressure(P,T);
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

  delay(500);

  for(int i = 0; i < 260; i++) {
      ClockPulse(); 
  }

  delay(1);
}
void send_to_radio(){
    radio.send(TargetID,data,packagesize);
    
    for(int i=0;i<packagesize;i++) Serial.println((char)data[i]);
    Serial.println("");
    
    delay(50);
}
void sent_to_SD_card(){
  
  plik = SD.open("wyniki.csv", FILE_WRITE);
  plik.println(seria);

};


void kompresja( int *seria, int *pomiar, int *temp, int *pres, int spekt[] )
{
  data[0] = (char) *seria;
  data[1] = (char) ( *pomiar / 256 );
  data[2] = (char) ( *pomiar % 256 );

  int t = *temp - temp_zero;
  int p = *pres - pres_zero;

  pixels[3] = (char) ( t / 4 );

  p = p + ( (t % 4) * 1024 );

  pixels[4] = (char) ( p / 16 );

  int spektrometr = 0, robocza = (p % 16) * 1024 + spekt[spektrometr], reszta = 6;

  pixels[5] = (char) ( robocza / 64 );

  robocza = robocza % 64;

  spektrometr++;

  for ( int i = 6; i < ilosc_bajtow; i++ )
  {
    if ( spektrometr >= 256 )
      break;

    robocza = robocza * 1024 + spekt[spektrometr];

    reszta = reszta + 10 - 8;

    pixels[i] = (char) ( robocza / pow( 2, reszta ) );

//cout << "r" << robocza << "." << pow( 2, reszta ) << "=" << (int) data[i] << " ";

    robocza = robocza % (int) pow( 2, reszta );

    if ( reszta == 8 )
    {
      i++; 

      data[i] = (char) robocza;

      robocza = 0;

      reszta = 0;
    }

    spektrometr += 2;
  } 
}




void setup(){
  Serial.begin(9600);
  Serial.println("boot");
 
  delay(1000);
  //radio rfm
  radio.initialize(FREQUENCY,NodeID,NetworkID);
  radio.setHighPower();
  radio.setPowerLevel(5);                           // from power output ranges from 0 (5dBm) to 31 (20dBm)
  radio.setFrequency(434200000);
  //end radio rfm
  
  //bmp
  if (pressure.begin())  Serial.println("BMP180 init success");
  else Serial.println("BMP180 init fail (disconnected?)\n\n");
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
  
  seria = rand()%256;
  pomiar = 0;
  Serial.println("done");
}
  
void loop(){

  pomiar++;
  
  get_bmp();
  get_lfl();

  kompresja( &seria, &pomiar,(int) &T, (int) &P, pixels );
  send_to_radio();
  
  sent_to_SD_card();
  
}
