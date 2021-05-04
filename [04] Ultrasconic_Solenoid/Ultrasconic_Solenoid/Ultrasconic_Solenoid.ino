const byte trigPin = 12;
const byte echoPin = 13;
const byte relay = 7;
void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(11, OUTPUT);
  digitalWrite(11,1);
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  float distance= duration / 29 / 2;
  Serial.println(distance);
  if(distance>8)
  {
  digitalWrite(relay,HIGH);
  delay(1000);
  }
  if(distance<8)
  {digitalWrite(relay,LOW);
  delay(1000);
  }
}
