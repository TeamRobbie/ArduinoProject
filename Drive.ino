#define SNA 3
#define RA 12
#define SNB 11
#define RB 13
unsigned long currentMillis;

void driveR(int factor){ //factor moet tussen .8 en 1 liggen omdat de standaarwaarde 200 gekozen is (anders zou hij naar verkeerde richting draaien)
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

void loop() { //testen van de factor van .8 naar 1 (trail and error)
  driveL(0.8);
  delay(1000);
  driveL(0.85);
  delay(1000);
  driveL(0.9);
  delay(1000);
  driveL(1);

  delay(1000);

  driveR(0.8);
  delay(1000);
  driveR(0.85);
  delay(1000);
  driveR(0.9);
  delay(1000);
  driveR(1);

}
