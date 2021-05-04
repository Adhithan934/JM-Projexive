#include <Servo.h> //Servo library
Servo myservo;  //Servo name is myservo

void setup() {
  Serial.begin(9600);
  myservo.attach(6);  // attaches the servo signal pin on pin D6
  myservo.write(90);
  delay(2000);
  pinMode(8, OUTPUT);
  pinMode(7, INPUT);
  digitalWrite(8,1);
  Serial.println("Starting");
}
//int angle=20;
void loop() {
  
int angle = map(analogRead(A0),0,700,20,180);
Serial.print(analogRead(A0));
Serial.print("\t\t");
Serial.println(angle);
    myservo.write(angle);
}
