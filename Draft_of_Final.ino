////////////////////PIN DEFINITIONS/////////////////////////////
  
  //right sensor
    int trigPin1 = 12;
    int echoPin1 = 13;
  //left sensor
    int trigPin2 = 12;
    int echoPin2 = 13;
  //front sensor
    int trigPin3 = 12;
    int echoPin3 = 13;

  //Input from JeeNode Encoder
    int blockCounter;
    
////////////////////Go Straight Variables//////////////////////////////////////
float error;
float const tollerence = 1; //TOLLERENCE FOR SELF CORRECTION IN goStraight() METHOD. 

int ESTOP = 7; //Number of cm that stops the car from hitting a wall (front sensor)

////////////////////MAPPING FUNCTIONS///////////////////////////

//mapRight, mapLeft, mapFront
int distance = 10;

///////////////////////GO STRAIGHT FUNCTION////////////////////////

float error;
float const tollerence = 1; //TOLLERENCE FOR SELF CORRECTION IN goStraight() METHOD.

//////////////////////////DISTANCE FUNCTIONS////////////////////////////////////////

//Left Sensor
long durationLeft, cmLeft, cm_for_Mode_Left [5];
int maxCountValueCMLeft, maxCountCMLeft;
//Right Sensor
long durationRight, cmRight, cm_for_Mode_Right [5];
int maxCountValueCMRight, maxCountCMRight;
//Front Sensor
long durationFront, cmFront, cm_for_Mode_Front [5];
int maxCountValueCMFront, maxCountCMFront;



void setup() {

  Serial.begin(9600);  
  
 //ENCODER COUNTER FROM THE JEENODE
 digitalRead(blockCount, INPUT); 

 //MOTOR 1 (RIGHT)
 digitalRead(en1, OUTPUT);  //Direction
 digitalRead(en2, OUTPUT);  //Brake
 analogRead(en3, OUTPUT);   //Speed
 
 //MOTOR 2 (LEFT)
 digitalRead(en4, OUTPUT);  //Direction
 digitalRead(en5, OUTPUT);  //Brake
 analogRead(en6, OUTPUT);   //Speed

}

void loop() {
  

}

void goStraight() {
  
    while(!blockCount && distanceFront() < ESTOP)  {

    //ERROR CALCULATIONS
    if(distanceRight() < 6 && distanceLeft() < 6)//Accounts for the robot being at an intersection
      error = distanceRight() - distanceLeft(); //DIFFERENCE BETWEEN LEFT AND RIDE SIDE OF ROBOT IN CM
    else
        error = error
      
    if((error + tollerence) < 0) {   //GO LEFT TO MAKE ERROR APPROACH ZERO. (TOLLERANCE OF 1CM)

      //RIGHT MOTOR
      digitalWrite(en1, HIGH); //Establishes forward direction of Channel A
      digitalWrite(en2, LOW);   //Disengage the Brake for Channel A
      analogWrite(en3, 160);    //Sets speed fo the individual motor
      
      //LEFT MOTOR
      digitalWrite(en4, HIGH); //Establishes forward direction of Channel A
      digitalWrite(en5, LOW);   //Disengage the Brake for Channel A
      analogWrite(en6, 120);    //Sets speed fo the individual motor
      
      //ADD A DELAY
      
    }else if((error - tollerence) >0) {    //GO RIGHT TO MAKE ERROR APPROACH ZERO. (TOLLERANCE OF 1CM)
      
      //RIGHT MOTOR
      digitalWrite(en1, HIGH);  //Establishes forward direction of Channel A
      digitalWrite(en2, LOW);   //Disengage the Brake for Channel A
      analogWrite(en3, 120);    //Sets speed fo the individual motor
      
      //LEFT MOTOR
      digitalWrite(en4, HIGH);  //Establishes forward direction of Channel A
      digitalWrite(en5, LOW);   //Disengage the Brake for Channel A
      analogWrite(en6, 160);    //Sets speed fo the individual motor
      
      //ADD A DELAY
      
    }else  {    //INSUFFICIENT ERROR CONTINUE GOING STRAIGHT

      //RIGHT MOTOR
      digitalWrite(en1, HIGH);  //Establishes forward direction of Channel A
      digitalWrite(en2, LOW);   //Disengage the Brake for Channel A
      analogWrite(en3, 160);    //Sets speed fo the individual motor
      
      //LEFT MOTOR
      digitalWrite(en4, HIGH);  //Establishes forward direction of Channel A
      digitalWrite(en5, LOW);   //Disengage the Brake for Channel A
      analogWrite(en6, 160);    //Sets speed fo the individual motor
      
      //ADD A DELAY
            
    }
  }
  
  //RIGHT MOTOR
  digitalWrite(en1, HIGH);  //Establishes forward direction of Channel A
  digitalWrite(en2, HIGH);   //Engage the Brake for Channel A
  analogWrite(en3, 0);    //Sets speed fo the individual motor
      
  //LEFT MOTOR
  digitalWrite(en4, HIGH);  //Establishes forward direction of Channel A
  digitalWrite(en5, LOW);   //Engage the Brake for Channel A
  analogWrite(en6, 0);    //Sets speed fo the individual motor
  
}


bool mapRight() {

  if(distanceRight() < distance) {
    return true; //Wall
  }

 return false; //no wall
  
}

bool mapFront() {

  if(distanceFront() < distance) {
    return true; //Wall
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
  for (int i = 0; i < 5; i++) {

    digitalWrite(trigPin1, LOW);

    delayMicroseconds(100);

    digitalWrite(trigPin1, HIGH);

    delayMicroseconds(100);

    digitalWrite(trigPin1, LOW);

    pinMode(echoPin1, INPUT);

    durationRight = pulseIn(echoPin1, HIGH);

    cm_for_Mode_Right[i] = (durationRight / 2) / 29.1;

  }

// Mode for CM:

//Calculating the mode by comparing inputs with other values in array, getting the count of repetition, and displaying value repeated the most

   maxCountValueCMRight = 0;
   maxCountCMRight = 0;
  
    for (int i = 0; i < 5; i++) {
  
      int countCM =0;
  
      for (int j=0; j<5; j++){
  
        if (cm_for_Mode_Right[j] == cm_for_Mode_Right[i]){
  
          countCM++;
  
        }
  
      }
  
      if (countCM>maxCountCMRight){
  
        maxCountCMRight = countCM;
  
        maxCountValueCMRight = cm_for_Mode_Right[i];
  
      }
  
    }
  
    return maxCountValueCMRight;
  
  }


int distanceLeft() {
  for (int i = 0; i < 5; i++) {

    digitalWrite(trigPin2, LOW);

    delayMicroseconds(100);

    digitalWrite(trigPin2, HIGH);

    delayMicroseconds(100);

    digitalWrite(trigPin2, LOW);

    pinMode(echoPin2, INPUT);

    durationLeft = pulseIn(echoPin2, HIGH);

    cm_for_Mode_Left[i] = (durationLeft / 2) / 29.1;

  }

// Mode for CM:

//Calculating the mode by comparing inputs with other values in array, getting the count of repetition, and displaying value repeated the most

   maxCountValueCMLeft = 0;
   maxCountCMLeft = 0;
  
    for (int i = 0; i < 5; i++) {
  
      int countCM =0;
  
      for (int j=0; j<5; j++){
  
        if (cm_for_Mode_Left[j] == cm_for_Mode_Left[i]){
  
          countCM++;
  
        }
  
      }
  
      if (countCM>maxCountCMLeft){
  
        maxCountCMLeft = countCM;
  
        maxCountValueCMLeft = cm_for_Mode_Left[i];
  
      }
  
    }
  
    return maxCountValueCMLeft;
  
  }


int distanceFront() {
  for (int i = 0; i < 5; i++) {

    digitalWrite(trigPin3, LOW);

    delayMicroseconds(100);

    digitalWrite(trigPin3, HIGH);

    delayMicroseconds(100);

    digitalWrite(trigPin3, LOW);

    pinMode(echoPin3, INPUT);

    durationRight = pulseIn(echoPin3, HIGH);

    cm_for_Mode_Front[i] = (durationFront / 2) / 29.1;

  }

// Mode for CM:

//Calculating the mode by comparing inputs with other values in array, getting the count of repetition, and displaying value repeated the most

   maxCountValueCMFront = 0;
   maxCountCMFront = 0;
  
    for (int i = 0; i < 5; i++) {
  
      int countCM =0;
  
      for (int j=0; j<5; j++){
  
        if (cm_for_Mode_Front[j] == cm_for_Mode_Front[i]){
  
          countCM++;
  
        }
  
      }
  
      if (countCM>maxCountCMFront){
  
        maxCountCMFront = countCM;
  
        maxCountValueCMFront = cm_for_Mode_Front[i];
  
      }
  
    }
  
    return maxCountValueCMFront;
  
  }
