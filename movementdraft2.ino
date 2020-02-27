 //Aisha Sheriff 

// encoder inputs 
int outA = 10 , outB = 11; // connect encoder inputs to regular digital ports 
// 
int enA = 2;// enableA and B have to into PWM I/O so that we can regulate speed 
int enB = 3; 
int in1 = 38; // in1 and in2, 3, 4 are used to control the rotational direction of the wheels
int in2 = 41; // pin 38 and 41 for motor1 
int in3 = 42; // pin 42 and 45 for motor 2 
int in4 = 45; 
void setup(){
  
  pinMode(outA,INPUT);
  pinMode(outB,INPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  
}
//Function for moving forward // just the motor logic.Open movement_v1 for details 
  void wheelsforward(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  }

  void wheelsback(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  }
  void rightmovement(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
   }
  void leftmovement(){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  }
  int sensordistance(int a);
void loop(){
  Serial.begin(9600);
  //
  int pinNumber1;
  int pinNumber2;
  int pinNumberfront;
  
  int sensetowall;//maximum sensor to wall distance from sides
  int Distance1 ;                                
  int Distance2;
  //int Distancefront;
  
   Distance1 = sensordistance(pinNumber1); //sensordistance() gets the value of the distance from the left or right side of
                                              //the robot to the wall, pinumber is I/O pin reflecting sensor at left**/                                        
   Distance2 = sensordistance(pinNumber2);

   //Distancefront = sensordistance(pinNumberfront);

  if(Distance1==Distance2){
    
    wheelsforward();
    delay(100);
     }
        
  
  else if(Distance1>sensetowall){
    rightmovement();
    delay(100);
  }
  
   else if(Distance2>sensetowall){
    leftmovement();
    delay(100);
  }
  else{
    //selfcorrect()      // adding a self correction function 
  }
  }
  
