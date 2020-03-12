int b=0; //the number of blocks needing to be traveled
int e=3; // the output pin number for the enable signal
int count=4; // The output pin number for the counter signal
int F=5; //input for the reading when the encoder is done 
void setup() {
  // put your setup code here, to run once:
pinMode(e,OUTPUT);
pinMode(count,OUTPUT);
pinMode(F,INPUT);
}

void loop() {
  
digitalWrite(e,HIGH); // This is used to indicate to the Jeenode to indicate to start looking for input readings 
for(int u; u<=b; u++){ //used to ensure the needed number of pulses are sent out indicated by the variable b
  digitalWrite(count,HIGH);
  delayMicroseconds(100); //The two digitlWrite statements and delay statements are used to generate the pulse waveform
  digitalWrite(count,LOW);
  if(u==b){
    digitalWrite(e,LOW);
    
  }else{
    delayMicroseconds(100);
  }
}

}
