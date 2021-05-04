const int motor1pin1 = 3;
const int motor1pin2 = 4;
const int motor2pin1 = 5;
const int motor2pin2 = 6;

int fwd_delay = 30000;
int turn_delay = 20000;

void setup()
{
  Serial.begin(9600);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  delay(2000);
  Serial.println("Started");
  halt();
}

void loop()
{
  forward();
  right();
  left();
  halt();
  Serial.println("Stop");
  while (1);
}


void forward()
{
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  Serial.println("Fwd");
  delay(fwd_delay);

}
void halt()
{
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
  Serial.println("Halt");
  delay(3000);

}
void right()
{
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  Serial.println("Right");
  delay(turn_delay);
  forward();
}
void left()
{
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  Serial.println("Left");
  delay(turn_delay);
  forward();
}
