//We communiceren aan de hand van I2C, daarvoor zijn volgende bibliotheken nodig:
#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>

PN532_I2C pn532i2c(Wire);
PN532 nfc(pn532i2c);

boolean success;
uint16_t timeout = 20;
boolean nieuweKaart = true;
uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
uint8_t uidLength;                        // Length of the UID (4 or 7 bytes depending on ISO14443A card type)
  
void setup() {
  Serial.begin(9600);
  Serial.println("Hello!");

  nfc.begin();
  Serial.println("nfc begonnen");
  uint32_t versiondata = nfc.getFirmwareVersion();
  Serial.println("versie opgehaald");
  if (! versiondata) {
    Serial.print("Didn't find PN53x board");
    while (1); // halt
  }
  
  // Got ok data, print it out!
  Serial.print("Found chip PN5"); Serial.println((versiondata>>24) & 0xFF, HEX); 
  Serial.print("Firmware ver. "); Serial.print((versiondata>>16) & 0xFF, DEC); 
  Serial.print('.'); Serial.println((versiondata>>8) & 0xFF, DEC);
  
  // Set the max number of retry attempts to read from a card
  // This prevents us from waiting forever for a card, which is
  // the default behaviour of the PN532.
  nfc.setPassiveActivationRetries(0xFF);
  
  // configure board to read RFID tags
  nfc.SAMConfig();
    
  Serial.println("Waiting for an ISO14443A card");
}

void loop() {
  // Wait for an ISO14443A type cards (Mifare, etc.).  When one is found
  // 'uid' will be populated with the UID, and uidLength will indicate
  // if the uid is 4 bytes (Mifare Classic) or 7 bytes (Mifare Ultralight)
  Serial.println(millis());
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, &uid[0], &uidLength, timeout);
  Serial.println(millis());
  if (success && nieuweKaart) {
    nieuweKaart = false;
    Serial.println("Found a card!");
    Serial.print("UID Length: ");Serial.print(uidLength, DEC);Serial.println(" bytes");
    Serial.print("UID Value: ");
    for (uint8_t i=0; i < uidLength; i++) 
    {
      Serial.print(uid[i], HEX);Serial.print(" "); 
    }
    Serial.println("");
  }
  else if(!success && !nieuweKaart){
    nieuweKaart = true;
  }
}
