/* QBCAN nadajnik
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
#define IS_RFM69HCW   true

constexpr int NodeID = 3;
constexpr int NetworkID = 233;
constexpr int TargetID = 1; 
char radiostring[100];
int licznik = 0;

RFM69 radio;

void setup(){
  Serial.begin(9600);
  Serial.println("boot");
  delay(1000);
  radio.initialize(FREQUENCY,NodeID,NetworkID);
  radio.setHighPower();
  radio.setPowerLevel(5);                           // from power output ranges from 0 (5dBm) to 31 (20dBm)
  radio.setFrequency(434200000);
  Serial.println("done");
}

void loop(){
  licznik++;
  // put your main code here, to run repeatedly:
  sprintf(radiostring,"%04u,%09u,Test string represents data",licznik,millis());
  radio.send(TargetID,radiostring,100);
  //Serial.println(radiostring);
  delay(50);
}
