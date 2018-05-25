void setup() {
  // put your setup code here, to run once:
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(6,INPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
//Serial.println(digitalRead(6));

if(Serial.available())
{
  int ch=Serial.read();
  Serial.println(char(ch));
  //front();
  switch (char(ch))
  {  case'1':case 'F': front();delay(100);ruk();break;
     case'2':case 'B': back();delay(100);ruk();break;
     case'3':case 'R': left();delay(100);ruk(); break;
     case'4':case 'L': right();delay(100);ruk();break;
             case'5'://line follower start with 5 and stop with 0
            while(Serial.read()!='0')
            {  //   Serial.println(digitalRead(6));
                  if( digitalRead(5)==0&&digitalRead(6)==0)
                   { front();delay(10);ruk();delay(10);
                   }
 //                 else
                  if( digitalRead(5)==1&&digitalRead(6)==0)
                    {right();delay(10);ruk();delay(10);
                    }
                  else
                  if( digitalRead(5)==0&&digitalRead(6)==1)
                    {left();delay(10);ruk();delay(10);
                    }  
                  else
                  if( digitalRead(5)==1&&digitalRead(6)==1)
                   {
                    left();delay(10);ruk();delay(10);
                   }
                   
              }  break;
    default: ruk();
  }
}
}
void left()
{digitalWrite(8,1);
digitalWrite(9,0);
digitalWrite(10,1);
digitalWrite(11,0);

  }
void right()
{digitalWrite(8,0);
digitalWrite(9,1);
digitalWrite(10,0);
digitalWrite(11,1);

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
