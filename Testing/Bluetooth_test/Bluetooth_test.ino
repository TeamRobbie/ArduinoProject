#include<SoftwareSerial.h>

#define RXpin 7
#define TXpin 8

SoftwareSerial BluetoothSerial(RXpin,TXpin);

void setup() {
  BluetoothSerial.begin(9600);
  Serial.begin(9600);
  BluetoothSerial.println("Opgestart");
  
  BluetoothSerial.println("Wachten op KP-waarde");
  while(BluetoothSerial.available()<=0);
  int KP = BluetoothSerial.parseInt();
  
  BluetoothSerial.println("Wachten op KI-waarde");
  while(BluetoothSerial.available()<=0);
  int KI = BluetoothSerial.parseInt();
  
  BluetoothSerial.println("Wachten op KD-waarde");
  while(BluetoothSerial.available()<=0);
  int KD = BluetoothSerial.parseInt();

  BluetoothSerial.print("We vertrekken met KP= ");BluetoothSerial.print(KP);BluetoothSerial.print("; KI = ");BluetoothSerial.print(KI);BluetoothSerial.print(" en KD = ");BluetoothSerial.println(KD);

  
}

void loop(){

}
