/*Things to include :
1.distace sensing and make wall following and maze solving,
2.line following using infrared sensors 
3.,infrared detecting so that bot can turn 180 degree if goes on wrong path */

int val=1000;// set value for 90 degree rotation
int echoPin1=2,trigPin1=3,j;
int echoPin2=4,trigPin2=5;
int duration1,duration2,distance1,distance2;

void setup() {
      //PIN DECLARATION FOR 2 ULTRASONIC SENSOR
      pinMode(echoPin1,INPUT);
      pinMode(trigPin1,OUTPUT);
      pinMode(echoPin2,INPUT);
      pinMode(trigPin2,OUTPUT);
      
      //pin 8,9,10,11 goes to the 4 INPUT POINTS OF THE MOTOR DRIVER
      pinMode(8,OUTPUT);
      pinMode(9,OUTPUT);
      pinMode(10,OUTPUT);
      pinMode(11,OUTPUT);
      
      //PIN DECLARATION FOR 3 INFRARED SENSORS
      pinMode(6,INPUT);
      pinMode(7,INPUT);
      pinMode(12,INPUT);
      
      pinMode(13,OUTPUT);// connect an led to this pin for flashing
      Serial.begin(9600);

}
void loop() {
      //LETS BEGIN WITH DISTANCE CALCULATION
      //FOR BOTH THE ULTRA SONIC SENSORS 1 AND 2
           digitalWrite(trigPin1,LOW);   digitalWrite(trigPin2,LOW);
           delayMicroseconds(2); 
           digitalWrite(trigPin1,HIGH);  digitalWrite(trigPin1,HIGH);
           delayMicroseconds(10); 
           digitalWrite(trigPin1,LOW);   digitalWrite(trigPin1,LOW);
           duration1= pulseIn(echoPin1,HIGH);duration2= pulseIn(echoPin2,HIGH);
           distance1= (duration1/2)/29.1; distance1= (duration2/2)/29.1;
           Serial.println(distance1);Serial.println(distance1);
           
      //till now we know the distace of the bot from front and one side 
      
      //now lets  decide what to do on black line #LINE FOLLOWER PART BELOW
        if( digitalRead(12)==1&&digitalRead(7)==0&&digitalRead(6)==1)                 //normal condition
          { front();      
          
          }
        else if( digitalRead(12)==0&&digitalRead(7)==0&&digitalRead(6)==1)             //left turn required
          {
              left();
          }
      
        else if( digitalRead(12)==1&&digitalRead(7)==0&&digitalRead(6)==0)            // right turn required
          {
              right();
          }
      
        else if( digitalRead(12)==1&&digitalRead(7)==1&&digitalRead(6)==0)           //right turn withboth wheels  a little faster
          {
              ruk();
              fright();
          }
          
        else if( digitalRead(12)==0&&digitalRead(7)==1&&digitalRead(6)==1)          //left turn with both wheels a little faster
          {
              ruk();
              fleft();
          }
      
        else if( digitalRead(12)==0&&digitalRead(7)==0&&digitalRead(6)==0)            //if all black lets move right by default
          {
            for(j=0;j<3;j++)
            {
                digitalWrite(13,1);
                delay(500);
                digitalWrite(13,0);
                delay(500);   
            }
              right();
          
          }
        else if( digitalRead(12)==0&&digitalRead(7)==1&&digitalRead(6)==0)
          {
                  right();          
          }
        //now if all the sensors are on white surface or other than black.....we need to activate maze solving mode
        
        else if( digitalRead(12)==1&&digitalRead(7)==1&&digitalRead(6)==1)
          {   
             while(digitalRead(12)==1&&digitalRead(7)==1&&digitalRead(6)==1)
             {          front();
                        if(distance1<7)
                        {
                              if(distance2>3)
                                {  right();
                                  delay(val);
                                }
                               else
                               if(distance2<3)
                               {
                                  left();
                                  delay(val);
                               }
                               else
                               fright();
                               delay(2*val);
                        }
                      else
                       if(distance1>7 )
                       {                             
                                            front();
                                            
                                            if(distance2>3)
                                             {
                                              right();delay(val);
                                             }

                                             
                       }       
                
             }
              
          
          }
    
}
//outside the loop 
//code block for movement of bot

void left()
{digitalWrite(8,0);
digitalWrite(9,1);
digitalWrite(10,0);
digitalWrite(11,0);

  }
void right()
{digitalWrite(8,0);
digitalWrite(9,0);
digitalWrite(10,1);
digitalWrite(11,0);

}
void front()
{
  
digitalWrite(8,0);
digitalWrite(9,1);
digitalWrite(10,1);
digitalWrite(11,0);
}

void back()
{//back
digitalWrite(8,1);
digitalWrite(9,0);
digitalWrite(10,0);
digitalWrite(11,1);

  }
void ruk()
{
  digitalWrite(8,0);
digitalWrite(9,0);
digitalWrite(10,0);
digitalWrite(11,0);

  }  

void fleft()
{digitalWrite(8,0);
digitalWrite(9,1);
digitalWrite(10,0);
digitalWrite(11,1);

  }
void fright()
{digitalWrite(8,1);
digitalWrite(9,0);
digitalWrite(10,1);
digitalWrite(11,0);

}
