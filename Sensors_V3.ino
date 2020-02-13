

int trigPin = 12;    // Trigger
int echoPin = 13;    // Echo
long duration, cm, inches, cm_for_AVG [15], inches_for_AVG[15], cm_for_Mode [15], inches_for_Mode [15];
int sum1 = 0;
int sum2 = 0;

void setup() {
  //Serial Port begin
  
  Serial.begin (9600);
  
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


}

void loop() {


// Filling arrays with 15 distance values to compute mean later
  for (int i = 0; i < 15; i++) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(150);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(150);
    digitalWrite(trigPin, LOW);

    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);
    cm_for_AVG[i] = (duration / 2) / 29.1;
    inches_for_AVG[i] = (duration / 2) / 74;
  }
  
  // Raw, unmodified values
  
  cm = (duration / 2) / 29.1;
  inches = (duration / (2)) / 74;

// Computing mean Value
  for (int i = 0; i < 15; i++) {
    sum1 = sum1 + cm_for_AVG[i];
    sum2 = sum2 + inches_for_AVG[i];
 /* Serial.print(cm_for_AVG [i]);
  Serial.print("    Array: CM   \n "); */
  }
  long AVG_CM = sum1 / 15;
  long AVG_INCH = sum2 / 15;

// Filling array with distance values to later calculate Mode
// Note: cm_for_AVG is not the calculated average, its the raw distance values filled.
for (int i = 0; i<15; i++){
  cm_for_Mode[i] = cm_for_AVG[i];
  inches_for_Mode[i] = inches_for_AVG[i];
}

// Mode for CM:
//Calculating the mode by comparing inputs with other values in array, getting the count of repetition, and displaying value repeated the most
  int maxValueCM = 0, maxCountCM = 0;
  for (int i = 0; i < 15; i++) {
    int countCM =0;
    for (int j=0; j<15; j++){
      if (cm_for_Mode[j] == cm_for_Mode[i]){
        countCM++;
      }
    }
    if (countCM>maxCountCM){
      maxCountCM = countCM;
      maxValueCM = cm_for_Mode[i];
    }
  }

  // Mode for INCHES:
  int maxValueINCHES = 0, maxCountINCHES = 0;
  for (int i = 0; i < 15; i++) {
    int countINCHES =0;
    for (int j=0; j<15; j++){
      if (inches_for_Mode[j] == inches_for_Mode[i]){
        countINCHES++;
      }
    }
    if (countINCHES>maxCountINCHES){
      maxCountINCHES = countINCHES;
      maxValueINCHES = inches_for_Mode[i];
    }
  }

  // Displaying mode, mean, and average distance values.
  
  Serial.print(maxValueINCHES);
  Serial.print("    Mode: inches    ");
  Serial.println();
  Serial.print(maxValueCM);
  Serial.print("    Mode: cm     ");
  Serial.println();
  Serial.println();
  Serial.print(AVG_INCH);
  Serial.print("    Mean: inches    ");
  Serial.println();
  Serial.print(AVG_CM);
  Serial.print("    Mean: cm  ");
  Serial.println();
  Serial.println();
  Serial.print(inches);
  Serial.print("     Raw: inches ");
  Serial.println();
  Serial.print(cm);
  Serial.print("     Raw: cm  ");
  Serial.println();

  sum1=0;
  sum2=0;


  delay(250);
}
