//main code hand using 4 servo motors
#include <Servo.h>

Servo myservo1; 
Servo myservo2;
Servo myservo3;
Servo myservo4;

int val1; 
int val2;
int  val3;
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
}


void loop() {
  Serial.println(digitalRead(swt));
//left right control
val1 = analogRead(y);
//Serial.println(val1);
val1 = map(val1, 0, 1023, 0, 180); 
myservo1.write(val1); 
//Serial.println(val1);


//up down control
val2 = analogRead(x);
//Serial.println(val2);
val2 = map(val2, 0, 1023, 0, 90); 
myservo2.write(val2);
//Serial.println(val2);

//up down  gripper control
val3 = analogRead(x);
//Serial.println(val3);
val3 = map(val3, 1023,0, 0, 180); 
myservo3.write(val3);
//Serial.println(val3);

if(digitalRead(swt)==0)
  myservo4.write(180);
else
  myservo4.write( 0);
  
     
}


