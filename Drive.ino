#define SNA 3
#define RA 12
#define SNB 11
#define RB 13
#define UTURN 128
#define HARD 153
#define MED 179
#define SOFT 230
unsigned long currentMillis;
int factorB;


void donut(int factor){
  currentMillis = millis();
  digitalWrite(RA,HIGH);
  digitalWrite(RB,HIGH);
  while(millis() - currentMillis <= 2000){
  analogWrite(SNA,factor);
  analogWrite(SNB,factor);
  }
  analogWrite(SNA,0);
  analogWrite(SNB,0);
  } 

void driveR(int factor){
  currentMillis = millis();
  digitalWrite(RA,HIGH);
  digitalWrite(RB,LOW);
  while(millis() - currentMillis <= 2000){
    analogWrite(SNA,100);
    analogWrite(SNB,factor);
   }
  analogWrite(SNA,0);
  analogWrite(SNB,0);
  }

void driveL(int factor){
  currentMillis = millis();
  digitalWrite(RA,HIGH);
  digitalWrite(RB,LOW);
  while(millis() - currentMillis <= 2000){
    analogWrite(SNA,factor);
    analogWrite(SNB,100);
   }
  analogWrite(SNA,0);
  analogWrite(SNB,0);
  }

void driveF(int factorA){
  currentMillis = millis();
  factorB = factorA - 10;
  digitalWrite(RA,HIGH);
  digitalWrite(RB,LOW);
  while(millis() - currentMillis <= 10 && factorB >=0){
  analogWrite(SNB,factorB);
  delay(10); //linkerwiel startte steeds iets sneller dan rechterwiel
  analogWrite(SNA,factorA);
   }
  }

void driveB(int factor){
  currentMillis = millis();
  digitalWrite(RA,LOW);
  digitalWrite(RB,HIGH);
  while(millis() - currentMillis <= 1000){
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
 /* for(int i=0;i<100;i++){ //versnelling maken
    driveF(i);
    delay(50);
    } */
donut(UTURN);
delay(500);

}
