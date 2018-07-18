#include <Servo.h>

Servo myservo1; 
Servo myservo2;
Servo myservo3;
Servo myservo4;

int flag=1;//values for flag
int cons=1;
int del=2;//delay value to controll speed of hand movement

int valy=90;
int valx=90;

int val1; 
int val2;

int swt=2;
int x=0;
int y=1;

void setup() {
// put your setup code here, to run once:
myservo1.attach(6); 
myservo2.attach(9);
myservo3.attach(10);
myservo4.attach(11);
  
pinMode(2,INPUT);
pinMode(0,INPUT);
pinMode(1,INPUT);
digitalWrite(2,HIGH);
Serial.begin(115200);
myservo1.write(90); 
myservo2.write(90);
myservo3.write(90);  
myservo4.write(0);
}

void loop() 
{
Serial.println(digitalRead(swt));
//left right control
val1 = analogRead(y);
if(val1>1020)
{ 
  if(valy<178);
  {
  valy+=cons;
  myservo1.write(valy); 
  delay(del);
  }
}

else
if(val1<10)
{
  if(valy>2);
  {
  valy-=cons;
  myservo1.write(valy); 
  delay(del);
  }
}

//up down control
val2 = analogRead(x);
if(val2>1018)
{ 
  if(valx<178)
  {
  valx+=cons;
  myservo2.write(valx); 
  //myservo3.write(valx); 
  delay(del);
  }
}

else
if(val2<10)
{
  if(val2>2);
  {
  valx-=cons;
  myservo2.write(valx); 
  //myservo3.write(valx); 
  delay(del);
  }
}
//switch grip mechanism

if(digitalRead(swt)==0)
{
  flag=(flag+1)%2;
  if(flag==0)
  myservo4.write(180);
  else
  if(flag==1)
  myservo4.write(0);
  delay(1500);
}
}
