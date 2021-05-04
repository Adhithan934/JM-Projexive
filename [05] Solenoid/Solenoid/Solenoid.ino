const int motor1pin1 = 11;
const int motor1pin2 = 12;


void setup() 
{
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  halt();
}

void loop()
{
  forward();
  halt();
}


void forward()
{
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  delay(200);
}
void halt()
{
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  delay(200);
}
