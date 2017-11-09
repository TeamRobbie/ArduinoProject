#include <Drive.h>

#define XTREME 255
#define HARD 200
#define MED 150
#define SOFT 100

Drive drive(12,13,3,11);


void setup() {
}

void loop() {
  /* test code voor drive
  drive.drive('F',MED);
  delay(500);
  drive.drive('B',MED);
  delay(500);
  drive.drive('L',MED);
  delay(500);
  drive.drive('R',MED);
  delay(500);
  */

  drive.driveScale(150,0);
  delay(1000);
  drive.driveScale(150,-100);
  delay(1000);
  drive.driveScale(150,100);
  delay(1000);
  drive.driveScale(150,-50);
  delay(1000);
  drive.driveScale(150,50);
  delay(1000);

}
