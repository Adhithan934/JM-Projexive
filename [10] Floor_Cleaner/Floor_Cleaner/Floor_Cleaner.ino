const byte trigPin1 = 6;
const byte echoPin1 = 5;
const byte trigPin2 = 10;
const byte echoPin2 = 9;
const byte relay = 2;
float distance1=0;
float distance2=0;
void setup() 
{
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT); 
  pinMode(relay, OUTPUT);
  Serial.begin(9600);
  Serial.println("Starting");
  delay(1000);

  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);

  digitalWrite(4,0);
  digitalWrite(8,0);
  digitalWrite(7,1);
  digitalWrite(11,1);
  
}

void loop()
{
  dis1();
  dis2();
  Serial.println();
  if(distance2<10 || distance1<10)
  {
    digitalWrite(relay,1);
    delay(2000);
  }
  else
  {
    digitalWrite(relay,0);
    delay(2000);
  }
}
void dis1()
{
  digitalWrite(trigPin1, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin1, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin1, LOW);
  long duration = pulseIn(echoPin1, HIGH);
  distance1= duration / 29 / 2;
  Serial.print(distance1);
  Serial.print("\t\t");
}
void dis2()
{
  digitalWrite(trigPin2, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin2, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin2, LOW);
  long duration = pulseIn(echoPin2, HIGH);
  distance2= duration / 29 / 2;
  Serial.print(distance2);
    Serial.print("\t\t");
}
