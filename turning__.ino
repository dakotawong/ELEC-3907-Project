


// encoder inputs 
//int outA = 10 , outB = 11; // connect encoder inputs to regular digital ports 
// 
int enA = 2;// enableA and B have to into PWM I/O so that we can regulate speed 
int enB = 3; 
int in1 = 38; // in1 and in2, 3, 4 are used to control the rotational direction of the wheels
int in2 = 41; // pin 38 and 41 for motor1 
int in3 = 42; // pin 42 and 45 for motor 2 
int in4 = 45; 

float error;

float const tollerence = 1; //TOLLERENCE FOR SELF CORRECTION IN goStraight() METHOD. 

digitalRead(blockCount, INPUT); 

int ESTOP = 7; //Number of cm that stops the car from hitting a wall (front sensor) FROM GO STRAIGHT FUNCTION

int distanceofoneblock = 10cm // number of cm per block (assumption)


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
//Function for moving forward 
  /*void wheelsforward(){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  }
  */


  
void loop(){
}


 void turning(){
  
       if(distancefront()==ESTOP){
      
            if(distanceright()>(Error+distanceleft())){ //turn right 

                     while(distanceright()!=distanceleft())  //in a loop until left and right sensors are equal, therfore showing  theres no wall longer and its in go straight orientation
                       //right motor 
                      analogWrite(enA, 150); // Send PWM signal to motor A
                      digitalWrite(in1,HIGH);//setting left motorB to move forward
                      digitalWrite(in2,LOW); 

                      //leftmotor 
                      digitalWrite(in3,LOW); 
                      digitalWrite(in4,HIGH);// setting left motor to move in opposite diesction
                      analogWrite(enB, 50); // Speed of motor B very little, might end up making it 0
                      
                      delay(1000)
                        }

               else if(distanceleft()>(Error+distanceright()){ // turn Left
                     //right motor 
                      while(distanceleft()!=distanceright()) // in a loop until left and right sensors are equal, therefore showing theres no wall longer and its in go straight orientation
                      digitalWrite(in1,LOW);
                      digitalWrite(in2,HIGH);
                      analogWrite(enA, 50);

                      //left motor 
                      
                      digitalWrite(in3,HIGH);
                      digitalWrite(in4,LOW);
                      analogWrite(enB, 150);
                      delay(1000)
                       }
               else{
                  
                   //case when FRONT DISTANCE  = ESTOP  i.e theres a wall in front,  and theres ALSO a dead end 
                   
                            //making both motors go back ward until Estop is false  
                            while(frontdistance()<(ESTOP+distanceofoneblock)) { //runs until it leaves dead (assuming we make deadends one block deep)
                              
                            digitalWrite(in1,LOW);
                            digitalWrite(in2,HIGH);
                            analogWrite(enA, 150);
                            
                            digitalWrite(in3,LOW);
                            digitalWrite(in4,HIGH);
                            analogWrite(enB, 150);
                             }
                  
                    }
             
             }
         
          else{
            
              Gostraight()   
              
               }

    
    } 
  
  
  
  
