

#define enA 9
#define in1 4
#define in2 5
#define enB 10
#define in3 6
#define in4 7

int motorSpeedA = 0;
int motorSpeedB = 0;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
  
 
  //analogWrite(enA, 255); // Send PWM signal to motor A
  //analogWrite(enB, 255); // Send PWM signal to motor B


  //delay(10000);

  if(adjustleft)
  
  analogWrite(enA, 150); // Send PWM signal to motor A
  analogWrite(enB, 70); // Send PWM signal to motor B


delay(10000);

  if (adjustright)
  analogWrite(enA, 70); // Send PWM signal to motor A
  analogWrite(enB, 150); // Send PWM signal to motor B


  delay(10000);
  
}
