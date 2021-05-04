const int motor1pin1 = 2;
const int motor1pin2 = 3;
const int motor2pin1 = 4;
const int motor2pin2 = 5;

int fwd_delay = 5000;
int turn_delay = 5000;

void setup() 
{
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  halt();
}

void loop()
{
  forward();
  halt();
  right();
  halt();
  forward();
  halt();
  left();
  
}


void forward()
{
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(fwd_delay);
}
void halt()
{
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
  delay(2000);
}
void right()
{
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  delay(turn_delay);
}
void left()
{
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(turn_delay);
}
