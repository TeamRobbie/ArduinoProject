//Library voor motorsturing
#include <Drive.h>
//Libraries voor sensoren
#include <IRSensoren.h>
#include <HallSensoren.h>
//Library voor RFID-reader met I2C
#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>
//Library voor seriële Bluetooth-communicatie
#include<SoftwareSerial.h>

//Motorsturing-pinnen
#define richtingA 5
#define richtingB 6
#define snelheidA 3
#define snelheidB 9

//IR-sensoren-pinnen
#define IRSensorSelect0 2
#define IRSensorSelect1 1
#define IRSensorSelect2 0
#define IRSensorOutMidden A1
#define IRSensorOutZij A0

//Hall-Sensor-pinnen
#define hallSensorRead 4

//RFID lezer gebruikt pinnen A4 SDA en A5 SCL

//Bluetooth
#define BTRXpin 7
#define BTTXpin 8
int data = 0;


//Objecten
//Drive
Drive drive(richtingA,richtingB,snelheidA,snelheidB);
int speed;

//Sensoren
IRSensoren IRsensors(IRSensorSelect0, IRSensorSelect1, IRSensorSelect2, IRSensorOutMidden, IRSensorOutZij);
HallSensoren hallSensor(hallSensorRead);
int KP;
int KI;
int KD;

//RFID-reader
PN532_I2C pn532i2c(Wire);
PN532 nfc(pn532i2c);
boolean success;
uint16_t timeout = 20;
boolean nieuweKaart = true;
uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
uint8_t uidLength;                        // Length of the UID (4 or 7 bytes depending on ISO14443A card type)

//Bluetooth
SoftwareSerial BluetoothSerial(BTRXpin,BTTXpin);

void setup() {
  BluetoothSerial.begin(9600);
  BluetoothSerial.println("--------------------------------------------------");
  BluetoothSerial.println("Bluetooth-communicatie opgestart; setup uitvoeren...");
  
  digitalWrite(richtingA,LOW);
  digitalWrite(richtingB,HIGH);


  nfc.begin();

  uint32_t versiondata = nfc.getFirmwareVersion();
  if (! versiondata) {
    BluetoothSerial.println("PN53x-RFID-lezer niet gevonden");
  }

  // Got ok data, print it out!
  BluetoothSerial.print("RFID-lezer gevonden: PN5"); BluetoothSerial.println((versiondata>>24) & 0xFF, HEX); 
  BluetoothSerial.print("Firmware ver. "); BluetoothSerial.print((versiondata>>16) & 0xFF, DEC); 
  BluetoothSerial.print('.'); BluetoothSerial.println((versiondata>>8) & 0xFF, DEC);
  
  // Set the max number of retry attempts to read from a card
  // This prevents us from waiting forever for a card, which is
  // the default behaviour of the PN532.
  nfc.setPassiveActivationRetries(0xFF);
  
  // configure board to read RFID tags
  nfc.SAMConfig();

  BluetoothSerial.println(-1); //token naar RPi om prompt te starten
  
  BluetoothSerial.println("Wachten op snelheid...");
  while(BluetoothSerial.available()<=0);
  speed = BluetoothSerial.parseInt();

  BluetoothSerial.println("Wachten op KP-waarde...");
  while(BluetoothSerial.available()<=0);
  KP = BluetoothSerial.parseInt();
  
  BluetoothSerial.println("Wachten op KI-waarde...");
  while(BluetoothSerial.available()<=0);
  KI = BluetoothSerial.parseInt();
  
  BluetoothSerial.println("Wachten op KD-waarde...");
  while(BluetoothSerial.available()<=0);
  KD = BluetoothSerial.parseInt();

  BluetoothSerial.print("We vertrekken met snelheid = ");BluetoothSerial.print(speed);
  BluetoothSerial.print("; KP = ");BluetoothSerial.print(KP);
  BluetoothSerial.print("; KI = ");BluetoothSerial.print(KI);
  BluetoothSerial.print(" en KD = ");BluetoothSerial.println(KD);    
  
}

void loop() {
  IRsensors.readSensors();
  IRsensors.digitaliseer(300);
  //IRsensors.printWaardes(BluetoothSerial);
  int factor = IRsensors.berekenPID(KP,KI,KD);
  //drive.driveCorrectieLR(speed,speed*factor/100);
  drive.driveScale(speed,factor);
  hallSensor.readSensors();
  hallSensor.printSpeed(BluetoothSerial);
  
  if(millis() % 100 < 2) {
    success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, &uid[0], &uidLength, timeout);
    if (success && nieuweKaart) {
      nieuweKaart = false;
      BluetoothSerial.println("RFID-tag gevonden!");
      BluetoothSerial.print("UID Lengte: ");BluetoothSerial.print(uidLength, DEC);BluetoothSerial.println(" bytes");
      BluetoothSerial.print("UID waarde: ");
      for (uint8_t i=0; i < uidLength; i++) 
      {
        BluetoothSerial.print(uid[i], HEX);BluetoothSerial.print(" "); 
      }
      BluetoothSerial.println("");
    }
    else if(!success && !nieuweKaart){
      nieuweKaart = true;
    }
  }
}
