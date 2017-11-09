#define SNA 3
#define RA 12
#define SNB 11
#define RB 13
#define XTREME 255
#define HARD 200
#define MED 150
#define SOFT 100
unsigned long currentMillis;
int factorA, factorB;
char sel;


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

void drive(char sel, int factor){
  currentMillis = millis();
  switch(sel){
    
    case 'F':
      factorA = factor;
      factorB = factor - 20;
      digitalWrite(RA,HIGH);
      digitalWrite(RB,LOW);
      while(millis() - currentMillis <= 700 && factorB >=0){
        analogWrite(SNB,factorB);
        //delay(10); //linkerwiel startte steeds iets sneller dan rechterwiel
        analogWrite(SNA,factorA);
      }
      break;

    case 'L': //factor moet hier minstents 50 zijn
      factorA = factor - (factor/4);
      factorB = factor;
      digitalWrite(RA,HIGH);
      digitalWrite(RB,LOW);
      while(millis() - currentMillis <= 700){
        analogWrite(SNA,factorA);
        analogWrite(SNB,factorB);
      }
      break;

    case 'R': //factor moet hier minstens 50 zijn
      factorA = factor;
      factorB = factor - (factor/4);
      digitalWrite(RA,HIGH);
      digitalWrite(RB,LOW);
      while(millis() - currentMillis <= 700){
        analogWrite(SNA,factorA);
        analogWrite(SNB,factorB);
      }
      break;

    case 'B':
      factorA = factor;
      factorB = factor - 20;
      digitalWrite(RA,LOW);
      digitalWrite(RB,HIGH);
      while(millis() - currentMillis <= 700 && factorB >=0){
        analogWrite(SNB,factorB);
        //delay(10); //linkerwiel startte steeds iets sneller dan rechterwiel
        analogWrite(SNA,factorA);
      }
      break;
    }
  analogWrite(SNA,0);
  analogWrite(SNB,0);
  
 
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
drive('F',SOFT);
delay(800);
drive('L',SOFT);
delay(800);
drive('R',SOFT);
delay(800);
drive('B',SOFT);
delay(800);



}
