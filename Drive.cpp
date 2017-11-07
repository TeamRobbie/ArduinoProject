#include "Arduino.h"
#include "Drive.h"

Drive::Drive(){
	
}

Drive::driveF(){
	currentMillis = millis();
  	digitalWrite(12,HIGH);
  	digitalWrite(13,LOW);
  	while(millis() - currentMillis <= 2000){
  	analogWrite(3,150);
  	analogWrite(11,150);
   }
}
