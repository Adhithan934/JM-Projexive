const int S0 = 7;
const int S1 = 6;
const int outPut= 5;
const int S2 = 4;
const int S3 = 3;
unsigned int frequency1 = 0;
unsigned int frequency2 = 0;
unsigned int frequency3 = 0;
const int voice = 13;


#include <Servo.h>
Servo myservo;
int pos = 0;

void setup()
{

myservo.attach(10);

Serial.begin(9600);
 
pinMode(S0, OUTPUT);
pinMode(S1, OUTPUT);
pinMode(S2, OUTPUT);
pinMode(S3, OUTPUT);

pinMode(outPut, INPUT);
pinMode(voice, OUTPUT);

digitalWrite(S0,HIGH);
digitalWrite(S1,HIGH);
digitalWrite(voice,LOW);



}


void loop()
{



digitalWrite(S2,LOW);
digitalWrite(S3,LOW);
frequency1 = pulseIn(outPut, LOW);
Serial.print(frequency1);
Serial.print("\t");




digitalWrite(S2,LOW);
digitalWrite(S3,HIGH);
frequency2 = pulseIn(outPut, LOW);
Serial.print(frequency2);
Serial.print("\t");


digitalWrite(S2,HIGH);
digitalWrite(S3,HIGH);
frequency3 = pulseIn(outPut, LOW);
Serial.print(frequency3);
Serial.print("\t");
delay(100);
int flag=0;

if (frequency1>50)
{
if(frequency2>40)
{
if(frequency3>50) 
{
  flag=1;  
}
}

}



if(flag==0)
{
  Serial.print("Dedected");
  digitalWrite(voice,HIGH);
  delay(2500);
  digitalWrite(voice,LOW);
}
else
{  Serial.print("Not Dedected");
}
Serial.println();





  for (pos = 0; pos <= 180; pos += 1)
    {
    myservo.write(pos);              
    delay(15);
    if (pos%20==0)
      {
        delay(500);
      }
     }
  for (pos = 180; pos >= 0; pos -= 1) 
    {
    myservo.write(pos);              
    delay(15);
    if (pos%20==0)
      {
        delay(500);
      }
    }

}   
