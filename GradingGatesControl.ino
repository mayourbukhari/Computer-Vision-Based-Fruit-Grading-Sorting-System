const int stepPin = 12;
const int dirPin = 11;
const int stepPin2 = 9;
const int dirPin2 = 10;
const int buttonPin1 = 8;
const int buttonPin2 = 7;
const int buttonPin3 = 6;
const int buttonPin4 = 5;
const int limitswitch1 = 0;
const int limitswitch2 = 1;
const int predef = 4;
const int start_off = 3;
const int buzzer=13;
int speed = 400;


//power on and reset function
void pandr(){
  int switchState1 = digitalRead(limitswitch1); // limit switch for gate1
  int switchState2 = digitalRead(limitswitch2); //limit switch for gate2
  if(switchState1 == HIGH && switchState2 == LOW){
     digitalWrite(dirPin2, HIGH); // Don't know direction
    while(digitalRead(limitswitch2) == LOW){ // Don't know output
      digitalWrite(stepPin2, HIGH);
      delayMicroseconds(speed);
      digitalWrite(stepPin2, LOW);
      delayMicroseconds(speed);
    } 
  }
  else if(switchState1 == LOW && switchState2 == HIGH){
    digitalWrite(dirPin, HIGH); // Don't know direction
    while(digitalRead(limitswitch1) == LOW){
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(speed);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(speed);
    }
  }

  else if(switchState1 == LOW && switchState2 == LOW){
    
    digitalWrite(dirPin, HIGH);
    digitalWrite(dirPin2, HIGH);
    while((digitalRead(limitswitch1) == LOW) && (digitalRead(limitswitch2) == LOW)){
      digitalWrite(stepPin, HIGH);
      digitalWrite(stepPin2,HIGH);
      delayMicroseconds(speed);
      digitalWrite(stepPin, LOW);
      digitalWrite(stepPin2,LOW);
      delayMicroseconds(speed);
    }
    // rechecking the conditions of gate internally for g1 low and g2 low
    switchState1 = digitalRead(limitswitch1);
    switchState2 = digitalRead(limitswitch2);
    if(switchState1 == HIGH && switchState2 == LOW){
     digitalWrite(dirPin2, HIGH); // Don't know direction
    while(digitalRead(limitswitch2) == LOW){ // Don't know output
      digitalWrite(stepPin2, HIGH);
      delayMicroseconds(speed);
      digitalWrite(stepPin2, LOW);
      delayMicroseconds(speed);
    } 
  }
  else if(switchState1 == LOW && switchState2 == HIGH){
    digitalWrite(dirPin, HIGH); // Don't know direction
    while(digitalRead(limitswitch1) == LOW){
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(speed);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(speed);
    }
  }
  
 }

//END P&R 
return;
}

void setup() {
 pinMode(stepPin, OUTPUT);
 pinMode(dirPin, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
 pinMode(buttonPin1, INPUT);
pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(limitswitch1, INPUT);
 pinMode(limitswitch2, INPUT);
 pinMode(predef, INPUT);
  pinMode(start_off, INPUT);
  digitalWrite(buttonPin1, LOW);
 digitalWrite(buttonPin2, LOW);
  digitalWrite(buttonPin3, LOW);
  digitalWrite(buttonPin4, LOW);
 digitalWrite(limitswitch1, LOW);
digitalWrite(limitswitch2, LOW);
digitalWrite(predef, LOW);
digitalWrite(start_off, LOW);
digitalWrite(buzzer, LOW);

  
  //power on check to set position to null
 pandr();
}


void loop() {

  int btnState1 = digitalRead(buttonPin1); //gate1up
  int btnState2 = digitalRead(buttonPin2); //gate1down
  int btnState3 = digitalRead(buttonPin3); //gate2up
  int btnState4 = digitalRead(buttonPin4); //gate2down
  int appleDetect = digitalRead(predef);  //predefined_fruit
  int reset = digitalRead(start_off); //power off or stop detection is pressed
  
  // when power off or stop detection is pressed
if(reset == HIGH){
 pandr();
 }

  //moving gate1 up
  if (btnState1 == HIGH) {
    digitalWrite(dirPin, HIGH);
    while (digitalRead(buttonPin1) == HIGH) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(speed);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(speed);
    }
  }

  //moving gate1 down
  if (btnState2 == HIGH) {
    digitalWrite(dirPin, LOW);
    while (digitalRead(buttonPin2) == HIGH) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(speed);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(speed);
    }
  }
 
  // moving gate2 up
  if (btnState3 == HIGH) {
    digitalWrite(dirPin2, HIGH);
    while (btnState3 == HIGH) {
      digitalWrite(stepPin2, HIGH);
      delayMicroseconds(speed);
      digitalWrite(stepPin2, LOW);
      delayMicroseconds(speed);
      btnState3=digitalRead(buttonPin3);
    }
  }

  //moving gate2 down
  if (btnState4 == HIGH) {
    digitalWrite(dirPin2, LOW);
    while (digitalRead(buttonPin4) == HIGH) {
    
      
      digitalWrite(stepPin2, HIGH);
      delayMicroseconds(speed);
      digitalWrite(stepPin2, LOW);
      delayMicroseconds(speed);
      btnState3=digitalRead(buttonPin3);
    }
  }

// If predefined fruit is selected (here apple)
if(appleDetect == HIGH){
    pandr(); // reset gates to null position
 digitalWrite(dirPin, LOW);
    digitalWrite(dirPin2, LOW);
    int g1pos=10000; // define the position at which both gates should be set
    int g2pos=16000;
    // adjust the gates to position using the controlled loops
    for(int i=0; i<=g1pos; i++){ //setting gate 1
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(speed);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(speed);
    }
    for(int i=0; i<=g2pos; i++){ //setting gate 2
      digitalWrite(stepPin2, HIGH);
      delayMicroseconds(speed);
      digitalWrite(stepPin2, LOW);
      delayMicroseconds(speed);
    }
  }

}
  
