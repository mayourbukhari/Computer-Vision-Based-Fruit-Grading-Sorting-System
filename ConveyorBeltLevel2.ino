int dirPin= 2;
int stepPin= 3;
int increaseS = 8; 
int decreaseS = 9; 
int stopbtn = 10; 
int startbtn=11;
int predef=12;
void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(increaseS, INPUT);
  pinMode(decreaseS, INPUT);
  pinMode(startbtn, INPUT);
  pinMode(stopbtn, INPUT);
  pinMode(predef, INPUT);
  delay(500);

  digitalWrite(dirPin, HIGH);
  
}

void loop() {
int btnState = digitalRead(startbtn);
int apple= digitalRead(predef);
int StopState;
int newdelay=350;
int stepUp;
int stepDown;
if(btnState==HIGH){
  //digitalWrite(dirPin, HIGH);
  while(1){
      StopState=digitalRead(stopbtn);
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(newdelay);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(newdelay);
      stepUp=digitalRead(increaseS);
      stepDown=digitalRead(decreaseS);
      if(stepUp==HIGH){
        if(newdelay >350){
          newdelay=newdelay-2;
        }         
      }
      if(stepDown==HIGH){
        if(newdelay<1000){
          newdelay=newdelay+2;
        }
      }
      if(StopState==HIGH){
        break;
      }
  }

}
if(apple==HIGH){
 // digitalWrite(dirPin, HIGH);
  newdelay=1000;
  while(1){
      StopState=digitalRead(stopbtn);
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(newdelay);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(newdelay);
      if(StopState==HIGH){
        break;
      }
  }
} 
}
