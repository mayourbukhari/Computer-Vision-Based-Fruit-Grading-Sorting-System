#include <Nextion.h>


//gate
const int g1upint=23;
const int g1downint=25;
const int g2upint=29;
const int g2downint=31;
const int predefint=33;
const int stopdetectint=35;

//cleaner
const int startfint=37;
const int stopfint = 39;
const int decreasefint = 41;
const int increasefint= 43;
const int fruitpredefint= 45;

//level 1
const int l1startint=22;
const int l1stopint=24;
const int l1increaseint=26;
const int l1decreaseint=28;
const int l1predefint=30;

// level 2
const int l2startint=32;
const int l2stopint=34;
const int l2increaseint=36;
const int l2decreaseint=38;
const int l2predefint=40;

//jetson
const int jetson1=47;
const int jetson2=49;
const int jetson3=51;
const int jetson4=53;

//linear actuator
const int lact1=11;
const int lact2=10;
const int opticalSwitch=9;


NexButton POff1 = NexButton(1, 3, "POff1");
NexButton POff2 = NexButton(3, 2, "POff2");

NexButton startFruit = NexButton(4, 2, "startFruit");
NexButton StopFruit = NexButton(4, 3, "StopFruit");
NexButton DecreaseFruit = NexButton(4, 5, "DecreaseFruit");
NexButton IncreaseFruit = NexButton(4, 6, "IncreaseFruit");


NexButton startLevel1 = NexButton(5, 2, "startLevel1");
NexButton stopLevel1 = NexButton(5, 3, "stopLevel1");
NexButton Level1decrease = NexButton(5, 5, "Level1decrease");
NexButton Level1Increase = NexButton(5, 6, "Level1Increase");

NexButton startLevel2 = NexButton(6, 2, "startLevel2");
NexButton stopLevel2 = NexButton(6, 3, "stopLevel2");
NexButton Level2Decrease = NexButton(6, 5, "Level2Decrease");
NexButton Level2Increase = NexButton(6, 6, "Level2Increase");

NexButton Gate1up = NexButton(7, 2, "Gate1up");
NexButton Gate1Down = NexButton(7, 3, "Gate1Down");

NexButton Gate2Up = NexButton(8, 2, "Gate2Up");
NexButton Gate2Down = NexButton(8, 3, "Gate2Down");

NexButton ColBup = NexButton(9, 2, "ColBup");
NexButton ColBdown = NexButton(9, 3, "ColBdown");

NexButton POff3 = NexButton(10, 3, "POff3");
NexButton AppleDetect = NexButton(10, 5, "AppleDetect");

NexButton StopDetect = NexButton(14, 2, "StopDetect");
// Register a button object to the touch event list.  
NexTouch *nex_listen_list[] = {
  &POff1,
  &POff2,
  &startFruit,
  &StopFruit,
  &DecreaseFruit,
  &IncreaseFruit,
  &startLevel1,
  &stopLevel1,
  &Level1decrease,
  &Level1Increase,
  &startLevel2,
  &stopLevel2,
  &Level2Decrease,
  &Level2Increase,
  &Gate1up,
  &Gate1Down,
  &Gate2Up,
  &Gate2Down,
  &ColBup,
  &ColBdown,
  &POff3,
  &AppleDetect,
  &StopDetect,
  NULL
};

//basket up
void basketup(){
  int statusup=digitalRead(opticalSwitch);
  if(statusup==LOW){
    digitalWrite(lact1, HIGH);
    digitalWrite(lact2, LOW);
    while(1){
       statusup=digitalRead(opticalSwitch);
       if(statusup==HIGH){
        digitalWrite(lact1, LOW);
        digitalWrite(lact2, LOW);
        break;
       }
    }
  }
  return;
}

//basket down
void basketdown(){
  digitalWrite(lact1, LOW);
  digitalWrite(lact2, HIGH); 
}

//power off function
void POffroutine(){
  digitalWrite(stopdetectint, HIGH);
  digitalWrite(stopfint, HIGH);
  digitalWrite(l1stopint, HIGH);
  digitalWrite(l2stopint, HIGH);
  delay(500);
  digitalWrite(stopdetectint, LOW);
  digitalWrite(stopfint, LOW);
  digitalWrite(l1stopint, LOW);
  digitalWrite(l2stopint, LOW);
  basketdown();
}



//PowerOFFButton1
void POff1PopCallback(void *ptr) {
 POffroutine();
}
//PowerOFFButton2
void POff2PopCallback(void *ptr) {
  POffroutine();
}





//FruitCleanerControls
void startFruitPopCallback(void *ptr) {
  digitalWrite(startfint, HIGH);
  delay(100);
  digitalWrite(startfint, LOW);
}

void StopFruitPopCallback(void *ptr) {
  digitalWrite(stopfint, HIGH);
  delay(100);
  digitalWrite(stopfint, LOW);
}
void DecreaseFruitPopCallback(void *ptr) {
  digitalWrite(decreasefint, HIGH);
  delay(25);
  digitalWrite(decreasefint, LOW);
}
void IncreaseFruitPopCallback(void *ptr) {
  digitalWrite(increasefint, HIGH);
  delay(25);
  digitalWrite(increasefint, LOW);
}






//ConveyerLevel1Control

void startLevel1PopCallback(void *ptr) {
  digitalWrite(l1startint, HIGH);
  delay(100);
  digitalWrite(l1startint, LOW);
}
void stopLevel1PopCallback(void *ptr) {
  digitalWrite(l1stopint, HIGH);
  delay(100);
  digitalWrite(l1stopint, LOW);
}
void Level1decreasePopCallback(void *ptr) {
  digitalWrite(l1decreaseint, HIGH);
  delay(25);
  digitalWrite(l1decreaseint, LOW);
}
void Level1IncreasePopCallback(void *ptr) {
  digitalWrite(l1increaseint, HIGH);
  delay(25);
  digitalWrite(l1increaseint, LOW);
}



//ConveyerLevel2Conntrol

void startLevel2PopCallback(void *ptr) {
  digitalWrite(l2startint, HIGH);
  delay(100);
  digitalWrite(l2startint, LOW);
}
void stopLevel2PopCallback(void *ptr) {
  digitalWrite(l2stopint, HIGH);
  delay(100);
  digitalWrite(l2stopint, LOW);
}
void Level2DecreasePopCallback(void *ptr) {
  digitalWrite(l2decreaseint, HIGH);
  delay(25);
  digitalWrite(l2decreaseint, LOW);
}
void Level2IncreasePopCallback(void *ptr) {
  digitalWrite(l2increaseint, HIGH);
  delay(25);
  digitalWrite(l2increaseint, LOW);
}



//Gate1Control
void Gate1upPopCallback(void *ptr) {
  digitalWrite(g1upint, HIGH);
  delay(100);
  digitalWrite(g1upint, LOW);
}
void Gate1DownPopCallback(void *ptr) {
  digitalWrite(g1downint, HIGH);
  delay(100);
  digitalWrite(g1downint, LOW);
}
//Gate2Control
void Gate2UpPopCallback(void *ptr) {
  digitalWrite(g2upint, HIGH);
  delay(100);
  digitalWrite(g2upint, LOW);
}
void Gate2DownPopCallback(void *ptr) {
  digitalWrite(g2downint, HIGH);
  delay(100);
  digitalWrite(g2downint, LOW);
}


//CollectorBasketControl
void ColBupPopCallback(void *ptr) {
  basketup();
}
void ColBdownPopCallback(void *ptr) {
  basketdown();
}



//OffButton3
void POff3PopCallback(void *ptr) {
    POffroutine();
}



//StartAppleDtect
void AppleDetectPopCallback(void *ptr) {
  basketup();
  digitalWrite(predefint, HIGH);
  digitalWrite(fruitpredefint, HIGH);
  digitalWrite(l1predefint, HIGH);
  digitalWrite(l2predefint, HIGH);
  delay(500);
  digitalWrite(predefint, LOW);
  digitalWrite(fruitpredefint, LOW);
  digitalWrite(l1predefint, LOW);
  digitalWrite(l2predefint, LOW);
}


//StopDetectGeneral
void StopDetectPopCallback(void *ptr) {
  digitalWrite(stopdetectint, HIGH);
  digitalWrite(stopfint, HIGH);
  digitalWrite(l1stopint, HIGH);
  digitalWrite(l2stopint, HIGH);
  delay(500);
  digitalWrite(stopdetectint, LOW);
  digitalWrite(stopfint, LOW);
  digitalWrite(l1stopint, LOW);
  digitalWrite(l2stopint, LOW);
}

void setup(void) {    
  Serial.begin(9600);
    
  nexInit();

  // Register the pop event callback function of the components
  POff1.attachPop(POff1PopCallback, &POff1);
  POff2.attachPop(POff2PopCallback, &POff2);
  startFruit.attachPop(startFruitPopCallback, &startFruit);
  StopFruit.attachPop(StopFruitPopCallback, &StopFruit);
  DecreaseFruit.attachPop(DecreaseFruitPopCallback, &DecreaseFruit); 
  IncreaseFruit.attachPop(IncreaseFruitPopCallback, &IncreaseFruit); 
  startLevel1.attachPop(startLevel1PopCallback, &startLevel1);
  stopLevel1.attachPop(stopLevel1PopCallback, &stopLevel1);
  Level1decrease.attachPop(Level1decreasePopCallback, &Level1decrease); 
  Level1Increase.attachPop(Level1IncreasePopCallback, &Level1Increase); 
  startLevel2.attachPop(startLevel2PopCallback, &startLevel2);
  stopLevel2.attachPop(stopLevel2PopCallback, &stopLevel2);
  Level2Decrease.attachPop(Level2DecreasePopCallback, &Level2Decrease); 
  Level2Increase.attachPop(Level2IncreasePopCallback, &Level2Increase); 
  Gate1up.attachPop(Gate1upPopCallback, &Gate1up);
  Gate1Down.attachPop(Gate1DownPopCallback, &Gate1Down);
  Gate2Up.attachPop(Gate2UpPopCallback, &Gate2Up);
  Gate2Down.attachPop(Gate2DownPopCallback, &Gate2Down);
  ColBup.attachPop(ColBupPopCallback, &ColBup);
  ColBdown.attachPop(ColBdownPopCallback, &ColBdown);
  POff3.attachPop(POff3PopCallback, &POff3);
  AppleDetect.attachPop(AppleDetectPopCallback, &AppleDetect);
  StopDetect.attachPop(StopDetectPopCallback, &StopDetect);
  pinMode(g1upint, OUTPUT);
  pinMode(g1downint, OUTPUT);
  pinMode(g2upint, OUTPUT);
  pinMode(g2downint, OUTPUT);
  pinMode(predefint, OUTPUT);
  pinMode(stopdetectint, OUTPUT);
  pinMode(startfint, OUTPUT);
  pinMode(stopfint, OUTPUT);
  pinMode(decreasefint, OUTPUT);
  pinMode(increasefint, OUTPUT);
  pinMode(fruitpredefint, OUTPUT);
  pinMode(l1startint, OUTPUT);
  pinMode(l1stopint, OUTPUT);
  pinMode(l1increaseint, OUTPUT);
  pinMode(l1decreaseint, OUTPUT);
  pinMode(l1predefint, OUTPUT);
  pinMode(l2startint, OUTPUT);
  pinMode(l2stopint, OUTPUT);
  pinMode(l2increaseint, OUTPUT);
  pinMode(l2decreaseint, OUTPUT);
  pinMode(l2predefint, OUTPUT);
  pinMode(jetson1, OUTPUT);
  pinMode(jetson2, OUTPUT);
  pinMode(jetson3, OUTPUT);
  pinMode(jetson4, OUTPUT);
  pinMode(lact1, OUTPUT);
  pinMode(lact2, OUTPUT);
  pinMode(opticalSwitch, INPUT);
  digitalWrite(g1upint, LOW);
  digitalWrite(g1downint, LOW);
  digitalWrite(g2upint, LOW);
  digitalWrite(g2downint, LOW);
  digitalWrite(predefint, LOW);
  digitalWrite(stopdetectint, LOW);
  digitalWrite(startfint, LOW);
  digitalWrite(stopfint, LOW);
  digitalWrite(decreasefint, LOW);
  digitalWrite(increasefint, LOW);
  digitalWrite(fruitpredefint, LOW);
  digitalWrite(l1startint, LOW);
  digitalWrite(l1stopint, LOW);
  digitalWrite(l1increaseint, LOW);
  digitalWrite(l1decreaseint, LOW);
  digitalWrite(l1predefint, LOW);
  digitalWrite(l2startint, LOW);
  digitalWrite(l2stopint, LOW);
  digitalWrite(l2increaseint, LOW);
  digitalWrite(l2decreaseint, LOW);
  digitalWrite(l2predefint, LOW);
  digitalWrite(jetson1, LOW);
  digitalWrite(jetson2, LOW);
  digitalWrite(jetson3, LOW);
  digitalWrite(jetson4, LOW);
  digitalWrite(lact1, LOW);
  digitalWrite(lact2, LOW); 
  basketup();
}

void loop(void) {
  digitalWrite(g1upint, LOW);
  digitalWrite(g1downint, LOW);
  digitalWrite(g2upint, LOW);
  digitalWrite(g2downint, LOW);
  digitalWrite(predefint, LOW);
  digitalWrite(stopdetectint, LOW);
  digitalWrite(startfint, LOW);
  digitalWrite(stopfint, LOW);
  digitalWrite(decreasefint, LOW);
  digitalWrite(increasefint, LOW);
  digitalWrite(fruitpredefint, LOW);
  digitalWrite(l1startint, LOW);
  digitalWrite(l1stopint, LOW);
  digitalWrite(l1increaseint, LOW);
  digitalWrite(l1decreaseint, LOW);
  digitalWrite(l1predefint, LOW);
  digitalWrite(l2startint, LOW);
  digitalWrite(l2stopint, LOW);
  digitalWrite(l2increaseint, LOW);
  digitalWrite(l2decreaseint, LOW);
  digitalWrite(l2predefint, LOW);
  digitalWrite(jetson1, LOW);
  digitalWrite(jetson2, LOW);
  digitalWrite(jetson3, LOW);
  digitalWrite(jetson4, LOW);
  nexLoop(nex_listen_list);
}
