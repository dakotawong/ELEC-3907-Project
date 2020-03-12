int inp=2;
int p=3;
int o=4;
int c=0; //  blocks to travel
int last=0;
int goal=0; // The number of rotations needed to reach a set distance
int a=1; // encoder output A
void setup() {
pinMode(inp,INPUT); //enable signal input pin
pinMode(p,INPUT);// counter signal input pin
pinMode(o,OUTPUT); // output signal pin


}

void loop() {
  if(digitalRead(inp)==HIGH){
   while (digitalRead(inp)==HIGH){ // While loop used to wait keep counting, as long as the enable signal is high
  if(digitalRead(p)==HIGH){
    if(digitalRead(p)==LOW){
      c=c+1; // After the the counter signal gives both a high and low signal, the counter adds 1 to the counter
    }
  }
}
    goal=16*c;
  for(int i=0; i<=goal; i++){
    last=digitalRead(a);
    if(digitalRead(a)!=last){
      
    }
    
  }
digitalWrite(o,HIGH); // indicates to the Due to stop the motors
delay(5);
digitalWrite(o,LOW);
c=0;
}}
