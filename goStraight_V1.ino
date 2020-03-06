
float error;
float const tollerence = 1; //TOLLERENCE FOR SELF CORRECTION IN goStraight() METHOD. 

void setup() {
  
 Serial.begin(9600);

 //ENCODER COUNTER FROM THE JEENODE
 digitalRead(blockCount, INPUT); 

 //MOTOR 1 (RIGHT)
 digitalRead(en1, OUTPUT);
 digitalRead(en2, OUTPUT);
 analogRead(en3, OUTPUT);
 
 //MOTOR 2 (LEFT)
 digitalRead(en4, OUTPUT);
 digitalRead(en5, OUTPUT);
 analogRead(en6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void goStraight() {

  while(!blockCount)  {

    //ERROR CALCULATIONS
    if(distanceRight() < 6 && distanceLeft() < 6)//Accounts for the robot being at an intersection
      error = distanceRight() - distanceLeft(); //DIFFERENCE BETWEEN LEFT AND RIDE SIDE OF ROBOT IN CM
    else
        error = error
      
    if((error + tollerence) < 0) {   //GO LEFT TO MAKE ERROR APPROACH ZERO. (TOLLERANCE OF 1CM)

      //RIGHT MOTOR
      digitalWrite(12, HIGH); //Establishes forward direction of Channel A
      digitalWrite(9, LOW);   //Disengage the Brake for Channel A
      analogWrite(3, 160);    //Sets speed fo the individual motor
      
      //LEFT MOTOR
      digitalWrite(12, HIGH); //Establishes forward direction of Channel A
      digitalWrite(9, LOW);   //Disengage the Brake for Channel A
      analogWrite(3, 120);    //Sets speed fo the individual motor
      
    }else if((error - tollerence) >0) {    //GO RIGHT TO MAKE ERROR APPROACH ZERO. (TOLLERANCE OF 1CM)
      
      //RIGHT MOTOR
      digitalWrite(en1, HIGH);  //Establishes forward direction of Channel A
      digitalWrite(en2, LOW);   //Disengage the Brake for Channel A
      analogWrite(en3, 120);    //Sets speed fo the individual motor
      
      //LEFT MOTOR
      digitalWrite(en4, HIGH);  //Establishes forward direction of Channel A
      digitalWrite(en5, LOW);   //Disengage the Brake for Channel A
      analogWrite(en6, 160);    //Sets speed fo the individual motor
      
    }else  {    //INSUFFICIENT ERROR CONTINUE GOING STRAIGHT

      //RIGHT MOTOR
      digitalWrite(en1, HIGH);  //Establishes forward direction of Channel A
      digitalWrite(en2, LOW);   //Disengage the Brake for Channel A
      analogWrite(en3, 160);    //Sets speed fo the individual motor
      
      //LEFT MOTOR
      digitalWrite(en4, HIGH);  //Establishes forward direction of Channel A
      digitalWrite(en5, LOW);   //Disengage the Brake for Channel A
      analogWrite(en6, 160);    //Sets speed fo the individual motor
            
    }
  }
}
