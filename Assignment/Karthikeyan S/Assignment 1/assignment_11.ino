int temperature_sensor=A0;
int ultra_in=3,PIR=4,photo_diode=5;
int ultra_out = 2,led_r=13,sound1=12,bulb=9,sound2=11,led_b=10,led_g=8;


void setup()
{
  Serial.begin(9600);
  pinMode(ultra_in,INPUT);
  pinMode(ultra_out,OUTPUT);
  pinMode(led_r,OUTPUT);
  pinMode(sound1,OUTPUT);
  pinMode(temperature_sensor,INPUT);
  pinMode(PIR,INPUT);
  pinMode(bulb,OUTPUT);
  pinMode(photo_diode,INPUT_PULLUP);
  pinMode(sound2,OUTPUT);
  pinMode(led_b,OUTPUT);
  pinMode(led_g,OUTPUT);
}
void loop()
{
    //PIR for motion detection and alerting
 double x=digitalRead(PIR);
  if(x)
  {
    
    tone(sound1,30);
    delay(10);
  }

  else
  {
    
    noTone(sound1);
    delay(10);
  }
  
  //temperature sensor to indicate the temperature 
  double a = analogRead(temperature_sensor);
  double value = (((a/1024)*5)-0.5)*100;
 if(value>90)
 {
   Serial.println("High");
   analogWrite(led_r,255);
   analogWrite(led_b,0);
   analogWrite(led_g,0);
 }
  else if(value>30&&value<90)
  {
Serial.println("Moderate");
    analogWrite(led_r,0);
    analogWrite(led_b,0);
    analogWrite(led_g,153);
  }
  else 
  {
    Serial.println("Cold");
    analogWrite(led_r,0);
    analogWrite(led_b,153);
    analogWrite(led_g,0);
  }
  
  //Ultrasonic detection 
  digitalWrite(ultra_out,LOW);
  digitalWrite(ultra_out,HIGH);
  delayMicroseconds(10);
  digitalWrite(ultra_out,LOW);

  float duration =pulseIn(ultra_in,HIGH);
  float distance=(duration*0.0343)/2;
  if(distance<100)
  {
   
    delay(10);
    tone(sound2,20);
    delay(1000);
  }
  else
  {
    
    noTone(sound2);
  }
  //photodiode for turning on and off of bulb
  if(digitalRead(photo_diode)==HIGH)
  {
    digitalWrite(bulb,HIGH);
  }
  else{
    digitalWrite(bulb,LOW);
  }

}