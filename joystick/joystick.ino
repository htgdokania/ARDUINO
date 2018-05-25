int swt=2;
int x=0;
int y=1;

void setup() {
  // put your setup code here, to run once:
pinMode(2,INPUT);
pinMode(0,INPUT);
pinMode(1,INPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("switch:");
Serial.print(digitalRead(swt));
Serial.print("\n x:");
Serial.print(analogRead(x));
Serial.print("\n y:");
Serial.print(analogRead(y));
delay(500);

}
