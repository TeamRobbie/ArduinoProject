#define SNA 3
#define RA 12
#define SNB 11
#define RB 13
#define UTURN 0.5
#define HARD 0.6
#define MED 0.7
#define SOFT 0.9
unsigned long currentMillis;

 

void driveR(int factor){
  currentMillis = millis();
  digitalWrite(RA,HIGH);
  digitalWrite(RB,LOW);
  while(millis() - currentMillis <= 2000){
  analogWrite(SNA,255);
  analogWrite(SNB,255*factor);
   }
  }

void driveL(int factor){
  currentMillis = millis();
  digitalWrite(RA,HIGH);
  digitalWrite(RB,LOW);
  while(millis() - currentMillis <= 2000){
  analogWrite(SNA,255*factor);
  analogWrite(SNB,255);
   }
  }

void driveF(int factor){
  currentMillis = millis();
  digitalWrite(RA,HIGH);
  digitalWrite(RB,LOW);
  while(millis() - currentMillis <= 2000){
  analogWrite(SNA,255*factor);
  analogWrite(SNB,255*factor);
   }
  }

void driveB(int factor){
  currentMillis = millis();
  digitalWrite(RA,LOW);
  digitalWrite(RB,HIGH);
  while(millis() - currentMillis <= 2000){
  analogWrite(SNA,255*factor);
  analogWrite(SNB,255*factor);
   }
  }

void setup() {
  pinMode(SNA,OUTPUT);
  pinMode(RA,OUTPUT);
  pinMode(SNB,OUTPUT);
  pinMode(RB,OUTPUT);

}

void loop() { //testen van de factor (trail and error, aan te passen bovenaan bestand)
  driveL(UTURN);
  delay(1000);
  driveL(HARD);
  delay(1000);
  driveL(MED);
  delay(1000);
  driveL(SOFT);

  delay(2000);

  driveR(UTURN);
  delay(1000);
  driveR(HARD);
  delay(1000);
  driveR(MED);
  delay(1000);
  driveR(SOFT);

  delay(2000);

  driveF(UTURN);
  delay(1000);
  driveF(HARD);
  delay(1000);
  driveF(MED);
  delay(1000);
  driveF(SOFT);

}
