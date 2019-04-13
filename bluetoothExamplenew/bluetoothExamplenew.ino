#include <SoftwareSerial.h>// import the serial library
SoftwareSerial Aisha(11, 12); // TX, RX
int ledPin = 13, reading1, reading2, oread1, oread2, BluetoothData;
char val;

void setup() {
  Aisha.begin(9600);
  pinMode(3, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(ledPin , OUTPUT);
  reading1 = 1;
  reading2 = 1;
}

void loop() {
  if (Aisha.available()) //if data is sent from laptop
    BluetoothData = Aisha.read(); //read it and store it in BluetoothData
  //delay(500);
  oread1 = reading1;
  oread2 = reading2;
  reading1 = digitalRead(3);
  reading2 = digitalRead(5);
  if (oread1 != reading1 || oread2 != reading2) //Check if new keys are pressed
  {
    if (reading1 == 0 && reading2 == 0) {
      Aisha.write(1);
      Serial.println("both key pressed");
    }
    else if (reading1 == 1 && reading2 == 0) {
      Aisha.write(2);
      Serial.println("key2 pressed");
    }
    else if (reading1 == 0 && reading2 == 1) {
      Serial.println("Key1 pressed");
      Aisha.write(3);
    }
    else {
      Serial.println("no key pressed");
      Aisha.write(4);

    }
  }
  if ( val == 'h') {
    digitalWrite(ledPin , HIGH);
  }
  else if (val == 'l') {
    digitalWrite(ledPin , LOW);
  }

  delay(100);
}

