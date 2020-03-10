


// encoder inputs 
//int outA = 10 , outB = 11; // connect encoder inputs to regular digital ports 
// 
int en3 = 2;// enableA and B have to into PWM I/O so that we can regulate speed 
int en6 = 3; 

int en1 = 38; // in1 and in2, 3, 4 are used to control the rotational direction of the wheels
int en2 = 41; // pin 38 and 41 for motor1 
int en4 = 42; // pin 42 and 45 for motor 2 
int en5 = 45; 

float error;

float const tollerence = 1; //TOLLERENCE FOR SELF CORRECTION IN goStraight() METHOD. 

digitalRead(blockCount, INPUT); 

int ESTOP = 7; //Number of cm that stops the car from hitting a wall (front sensor) FROM GO STRAIGHT FUNCTION

int distanceofoneblock = 10cm // number of cm per block (assumption)


void setup(){
  
  pinMode(outA,INPUT);
  pinMode(outB,INPUT);
  pinMode(en1,OUTPUT);
  pinMode(en2,OUTPUT);
  pinMode(en3,OUTPUT);
  pinMode(en5,OUTPUT);
  pinMode(en3,OUTPUT);
  pinMode(en6,OUTPUT);
  
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
                     
                      digitalWrite(en1,HIGH);//setting left motorB to move forward
                      digitalWrite(en2,LOW); 
                       analogWrite(en3, 150); // Send PWM signal to motor A
                      //leftmotor 
                      digitalWrite(en4,LOW); 
                      digitalWrite(en5,HIGH);// setting left motor to move in opposite diesction
                      analogWrite(en6, 50); // Speed of motor B very little, might end up making it 0
                      
                      delay(1000)
                        }

               else if(distanceleft()>(Error+distanceright()){ // turn Left
                     //right motor 
                      while(distanceleft()!=distanceright()) // in a loop until left and right sensors are equal, therefore showing theres no wall longer and its in go straight orientation
                      digitalWrite(en1,LOW);
                      digitalWrite(en2,HIGH);
                      analogWrite(en3, 50);

                      //left motor 
                      
                      digitalWrite(en4,HIGH);
                      digitalWrite(en5,LOW);
                      analogWrite(en6, 150);
                      delay(1000)
                       }
               else{
                  
                   //case when FRONT DISTANCE  = ESTOP  i.e theres a wall in front,  and theres ALSO a dead end 
                   
                            //making both motors go back ward until Estop is false  
                            while(distancefront()<(ESTOP+distanceofoneblock)) { //runs until it leaves dead (assuming we make deadends one block deep)
                              
                            digitalWrite(en1,LOW);
                            digitalWrite(en2,HIGH);
                            analogWrite(en3, 150);
                            
                            digitalWrite(en4,LOW);
                            digitalWrite(en5,HIGH);
                            analogWrite(en6, 150);
                             }
                  
                    }
             
             }
         
          else{
            
              Gostraight()   
              
               }

    
    } 
  
  
  
  
