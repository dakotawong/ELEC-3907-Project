
//Encoder
int outA = 1 , outB = 2;
int STOP;

//goStraight
int counter = 0;
int state, lastState;
double wheelDiameter = 5;//in cm (ESTIMATE)

//mapRight, mapLeft, mapFront
int distance = 10;

//General
const double blockDistance = 20.32; //Block distance in cm (assumed 8")
int ESTOP = 6; //Number of cm to emergency stop TBD

void setup() {

  //encoder inputs
  pinMode(outA, INPUT);
  pinMode(outB, INPUT);

  Serial.begin(9600);

  lastState = digitalRead(outA);

}

void loop() {
  

}

void goStraight(double numBlocks)  {

  STOP = (numBlocks*blockDistance)/(wheelDiameter*3.14);
  counter =0;

  //set motor pins high

    while(counter < STOP)  {
      state = digitalRead(outA);
  
      if(state != lastState)  {
        if(digitalRead(outB)!= state){
          counter++;
        } else {
          counter--;
        }
        Serial.print("Number of Rotations:  ");
        Serial.print(counter);
  
        lastState = state;
  
      }
      if(distanceFront() < ESTOP)
      return;
    }
    //set motor pins Low 
}

bool mapRight() {

  if(distanceRight() <distance) {
    return true; //Wall
  }

 return false; //no wall
  
}

bool mapFront() {

  if(distanceFront() < distance)  {
    return true; //wall
  }

  return false; //no wall
  
}

bool mapLeft()  {

  if(distanceLeft() < distance) {
    return true; //wall
  }

  return false; //no wall
  
}

int distanceRight()  {
  return -1;
};

int distanceLeft() {
  return -1;
};

int distanceFront() {
  return -1;
}
