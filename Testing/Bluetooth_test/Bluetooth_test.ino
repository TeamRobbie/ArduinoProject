#include<SoftwareSerial.h>

#define RXpin 7
#define TXpin 8

int data = 0;

SoftwareSerial BluetoothSerial(RXpin,TXpin);

void setup() {
  BluetoothSerial.begin(9600);
  Serial.begin(9600);
  BluetoothSerial.println("Opgestart");
  
}

void loop(){
  data++; 
  BluetoothSerial.println(data);
  Serial.print(data);Serial.println(" is verzonden");
  delay(2000);
}
