const int motor1pin1 = 7;
const int motor1pin2 = 8;
const byte trigPin = 3;
const byte echoPin = 4;
const byte relay = 6;
float distance =0;
bool flag=0;

void setup() 
{
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(relay, OUTPUT);
  Serial.begin(9600);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(relay, LOW);
  Serial.println("Starting");
  delay(3000);
  }


void loop()
{
  dis();
  if (distance<10 && distance>5)
  { 
    if (flag ==0)
    {
        digitalWrite(relay, HIGH);
        digitalWrite(motor1pin1, LOW);
        digitalWrite(motor1pin2, HIGH);
        delay(4000);
        digitalWrite(motor1pin1, LOW);
        digitalWrite(motor1pin2, LOW);
        delay(2000);
        flag=1;
    }
  }
  dis();
  if (distance<10 && distance>5)
  { 
    if (flag==1)
    {
      digitalWrite(relay, LOW);
      digitalWrite(motor1pin1, HIGH);
      digitalWrite(motor1pin2, LOW);
      delay(4000);
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, LOW);
      flag=0;
    }
delay(100);
}
}

void dis()
{
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  distance= duration / 29 / 2;
  Serial.println(distance);
}
