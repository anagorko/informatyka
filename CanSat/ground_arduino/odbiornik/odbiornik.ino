/* QBCAN odbiornik
 * 
 * 
 * 
 * 
 * RFM-69HCW <---> arduino
 *       SCK       13
 *      MISO       12
 *      MOSI       11
 *       NSS       10
 *      DIOo       2
 *      3,3V       3,3V
 *       GND       GND
 */
#include <qbcan.h>

#define temp_zero -300 //punkt zero dla temperatury (wartość w dC)
#define pres_zero 600 //punkt zero dla ciśnienia (wartość w hPa)
#define ilosc_bajtow 166

constexpr int NodeID = 1;
constexpr int NetworkID = 233;

RFM69 radio;

char data[ilosc_bajtow];

unsigned int id_serii, id_measure, temperature, pressure, lfl[256];

void dekompresja( int *seria, int *pomiar, int *temp, int *pres, int spekt[] )
{
  *seria = (unsigned int) data[0];
  *pomiar = ( (int) data[1] ) * 256 + (int) data[2];

  *temp = (int) data[3] * 4 + ( (int) data[4] / 64 );
  *pres = ( (int) data[4] % 64 * 16 ) + ( (int) data[5] / 16 );

  *temp = *temp + temp_zero;
  *pres = *pres + pres_zero;

  int spektrometr = 0, robocza = ( (int) data[5] % 16), reszta = 4;

//cout << (int) data[5] << " test " << robocza << endl;

  for ( int i = 6; i < ilosc_bajtow; i++ )
  {
    if ( spektrometr >= 256 )
      break;

    robocza = robocza * 256 + (int) data[i];  

//cout << (int) data[i] << " test " << robocza << endl;

    reszta = reszta + 8 - 10;

    if ( reszta < 0 )
    {
      i++; 

      robocza = robocza * 256 + (int) data[i];

      reszta = reszta + 8;
    }

    spekt[spektrometr] = robocza / (int) pow( 2, reszta );
    spekt[spektrometr + 1] = robocza / (int) pow( 2, reszta );

    robocza = robocza % (int) pow( 2, reszta );

    spektrometr += 2;
  }
}


void setup() {
  Serial.begin(9600);
  //Serial.println("boot");
  delay(1000);

  radio.initialize(FREQUENCY,NodeID,NetworkID);
  radio.setHighPower();
  radio.setFrequency(434200000);
  
 Serial.println("Listening on frequency");
}

void loop() {
  if(radio.receiveDone()){
//Serial.print("Incoming packet: ");
    for(byte i = 0; i < radio.DATALEN; i++){
      data[i] = (char)radio.DATA[i];
    }
//Serial.print(" end message. ");
//Serial.println("RSSI: " + String(radio.RSSI));

    dekompresja( &id_serii, &id_measure, &temperature, &pressure, &lfl[0]);

    Serial.print( id_serii ); Serial.print( ";" );
    Serial.print( id_measure ); Serial.print( ";" );
    Serial.print( temperature ); Serial.print( ";" );
    Serial.print( pressure );

    for ( int i = 0; i < 256; i++ )
    {
      Serial.print( ";" ); Serial.print( lfl[i] );
    }
  
    Serial.println( ";" );
  }
  //Serial.println( "rotate" );
}
