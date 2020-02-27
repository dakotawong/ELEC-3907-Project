
float error;
float const tollerence = 1; //TOLLERENCE FOR SELF CORRECTION IN goStraight() METHOD. 

void setup() {
  
 Serial.begin(9600);

 //ENCODER COUNTER FROM THE JEENODE
 digitalRead(blockCount, INPUT); 

 //MOTOR 1
 digitalRead(en1, OUTPUT);
 digitalRead(en2, OUTPUT);
 
 //MOTOR 2
 digitalRead(en3, OUTPUT);
 digitalRead(en4, OUTPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:

}

void goStraight() {

  while(!blockCount)  {

    //ERROR CALCULATIONS
    error = distanceRight() - distanceLeft(); //DIFFERENCE BETWEEN LEFT AND RIDE SIDE OF ROBOT IN CM

    if((error + tollerence) < 0) {   //GO LEFT TO MAKE ERROR APPROACH ZERO. (TOLLERANCE OF 1CM)

      //ADD CODE TO SLIGHTLY LEAD LEFT
      
    }else if((error - tollerence) >0) {    //GO RIGHT TO MAKE ERROR APPROACH ZERO. (TOLLERANCE OF 1CM)

      //ADD CODE TO SLIGHTLY LEAD RIGHT
      
    }else  {    //INSUFFICIENT ERROR CONTINUE GOING STRAIGHT

      digitalWrite(en1, LOW);   //MOTOR 1 FORWARD
      digitalWrite(en2, HIGH);
      digitalWrite(en3, LOW);   //MOTOR 2 FORWARD
      digitalWrite(en4, HIGH);
            
    }
  }
}
