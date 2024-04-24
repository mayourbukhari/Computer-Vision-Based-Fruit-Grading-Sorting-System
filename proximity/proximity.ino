#include <Servo.h>

Servo myservo;
int pos = 110;
void setup() {
  myservo.attach(3); 
    myservo.write(110);
  pinMode(9, INPUT);
  pinMode(13, INPUT);
}
void loop() {
  int detect=digitalRead(9);
  int prox=digitalRead(13);
  if (detect==HIGH && prox==LOW ){
  for (pos = 110; pos >= 0; pos -= 1) { 
    myservo.write(pos);              
   // delay(05);                       
  }
  while(1){
    int prox=digitalRead(13);
    if(prox==HIGH){
      for (pos = 0; pos <= 110; pos += 1) { 
      myservo.write(pos);              
    //  delay(05);                       
      }
      break;
    }
  }
  }
}
