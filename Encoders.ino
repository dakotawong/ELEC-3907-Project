


int encoderA = 2;
int encoderB = 3;
int in1 = 38;
int in2 = 41;
unsigned long volatile encodercount;
unsigned long encoder_previous;
//boolean first;

unsigned long lastRead = 0;
unsigned long interval = 100;

long ang_speed;
long linear_speed;

void setup() {
  // put your setup code here, to run once:
  encodercount = 0;
  encoder_previous = 0;
  Serial.begin(9600);

  pinMode(encoderA, INPUT);
  pinMode(encoderB, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(encoderA), speed, FALLING);
 // first = true; 

 digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

  delay(100);

  if(millis() - lastRead >= interval)
  {
    lastRead+=interval;
    noInterrupts();
    encoder_previous = encodercount;
    encodercount = 0;
    interrupts();
  }

//  Serial.println(encoder_previous);

  ang_speed = (4 * (22/7) *encoder_previous)/ (120 * 16 * 0.1);
  Serial.print(ang_speed);
  Serial.println(" rad/s");

  linear_speed = ang_speed * 0.0087;
  Serial.print(linear_speed);
  Serial.println("m/s");

  if (lastRead >= 10000)
  {
    digitalWrite(in1,HIGH);
    digitalWrite (in2,HIGH);
  }
}


void speed() {
  encodercount++;
}
