#define SNA 3
#define RA 12
#define SNB 11
#define RB 13
unsigned long currentMillis;

void driveR(){
  currentMillis = millis();
  digitalWrite(RA,HIGH);
  digitalWrite(RB,LOW);
  while(millis() - currentMillis <= 2000){
  analogWrite(SNA,100);
  analogWrite(SNB,70);
   }
  }

void driveL(){
  currentMillis = millis();
  digitalWrite(RA,HIGH);
  digitalWrite(RB,LOW);
  while(millis() - currentMillis <= 2000){
  analogWrite(SNA,70);
  analogWrite(SNB,100);
   }
  }

void driveF(){
  currentMillis = millis();
  digitalWrite(RA,HIGH);
  digitalWrite(RB,LOW);
  while(millis() - currentMillis <= 2000){
  analogWrite(SNA,100);
  analogWrite(SNB,100);
   }
  }

void driveB(){
  currentMillis = millis();
  digitalWrite(RA,LOW);
  digitalWrite(RB,HIGH);
  while(millis() - currentMillis <= 2000){
  analogWrite(SNA,100);
  analogWrite(SNB,100);
   }
  }

void setup() {
  pinMode(SNA,OUTPUT);
  pinMode(RA,OUTPUT);
  pinMode(SNB,OUTPUT);
  pinMode(RB,OUTPUT);

}

void loop() {
  driveL();
  delay(500);
  driveR();
  delay(500);
  driveF();
  delay(500);
  driveB();
  delay(500);

}
