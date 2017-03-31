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

constexpr int NodeID = 1;
constexpr int NetworkID = 233;

RFM69 radio;

void setup() {
  Serial.begin(9600);
  Serial.println("boot");
  delay(1000);

  radio.initialize(FREQUENCY,NodeID,NetworkID);
  radio.setHighPower();
  radio.setFrequency(434200000);
  
 Serial.println("Listening on frequency");
}

void loop() {
  if(radio.receiveDone()){
    Serial.print("Incoming packet: ");
    for(byte i = 0; i < radio.DATALEN; i++){
      Serial.print((char)radio.DATA[i]);
    }
    Serial.print(" end message. ");
    Serial.println("RSSI: " + String(radio.RSSI));
  }
}
