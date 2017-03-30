// Sparkfun Pro Micro, procesor: ATmega32U4 (5V, 16 Mhz)

const unsigned char PS_32 = (1 << ADPS2) | (1 << ADPS0);
const unsigned char PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

const int pinSI = 7;    // digital out
const int pinCLK = 8;   // digital out
const int pinAO = 14;   // analog in

short int pixels[256];

void ClockPulse()
{
    delayMicroseconds(60);
    digitalWrite(pinCLK, HIGH);
    digitalWrite(pinCLK, LOW);
  }

void setup() 
{
    pinMode(pinCLK, OUTPUT);
    pinMode(pinSI, OUTPUT);

ADCSRA &= ~PS_128;  
    ADCSRA |= PS_32;

analogReference(DEFAULT);

for (int i = 0; i < 14; i++) {
      digitalWrite(i, LOW);
    }

for (int i = 0; i < 260; i ++) {
      ClockPulse();
    }

digitalWrite(pinSI, HIGH);
    ClockPulse(); 
    digitalWrite(pinSI, LOW);

for(int i=0;i< 260;i++) {
        ClockPulse(); 
    }

Serial.begin(115200);
  }

void loop()
{
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

for(int i = 0; i < 256; i += 1)
{
      Serial.print((int) pixels[i]); Serial.print(";");
    }
    Serial.println("");

delay(500);

for(int i = 0; i < 260; i++) {
      ClockPulse(); 
    }

delay(1);
  }
