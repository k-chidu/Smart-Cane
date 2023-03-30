int trig=12;
int echo=2;
int feedback=6;
long duration=0;
float interval=0.001;
unsigned long reset_time=0;
float dist;


void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
  pinMode(feedback,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(feedback,LOW);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);

  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  Serial.println("Signal Sent.\n\n");
  duration=pulseIn(echo,HIGH);
  dist=duration*0.034/2;
  Serial.println(dist);
  
  if(dist>10 && dist<15){
    for(int i=0; i<255; i++){
      analogWrite(feedback, i);
      delay(5);
    }
    for(int i=255; i>0; i--){
      analogWrite(feedback, i);
      delay(5);
    }
  }
  if(dist>6 && dist<10){
    for(int i=0; i<255; i++){
      analogWrite(feedback, i);
      delay(1);
    }
    for(int i=255; i>0; i--){
      analogWrite(feedback, i);
      delay(1);
    }
  }
  if(dist<6){
    analogWrite(feedback,255);
  }
 
  
  
}
