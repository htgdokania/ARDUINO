#include <Servo.h>

Servo myservo1; 
Servo myservo2;
Servo myservo3;
Servo myservo4;

int val1=0; 
//int val2=0; 
//int val3=0; 
//int val4=0; 

void setup()
{
myservo1.attach(6); 
myservo2.attach(9);
myservo3.attach(10);
myservo4.attach(11);
Serial.begin(9600);
}


void loop() {
 
      val1+=60;
    myservo1.write(val1); 
    myservo2.write(val1); 
    myservo3.write(val1); 
    myservo4.write(val1); 
    delay(1000);
    if(val1==180)
    {
      val1=0;
      myservo1.write(val1); 
      myservo2.write(val1); 
      myservo3.write(val1); 
      myservo4.write(val1); 
      delay(1000);

    }
     
     
}


