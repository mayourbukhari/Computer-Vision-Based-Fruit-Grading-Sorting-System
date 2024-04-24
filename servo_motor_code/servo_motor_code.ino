/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

   // variable to store the servo position
int pos = 110;
void setup() {
  myservo.attach(9); 
    myservo.write(110);// attaches the servo on pin 9 to the servo object
  pinMode(13, INPUT);
}

void loop() {
  if (digitalRead(13)){
  for (pos = 110; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(05);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 0; pos <= 110; pos += 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  }
}
