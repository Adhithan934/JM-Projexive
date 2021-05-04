//Use 2 motor drivers (L298n)
//1st motor driver is for vechile movement (Front wheel)
//1st motor driver is for vechile movement (Rear wheel)
//2nd motor driver is for forklift movement
//Project uses mechanum wheels
  
const int motor1pin1 = 4;
const int motor1pin2 = 5;
const int motor2pin1 = 6;
const int motor2pin2 = 7;
const int motor3pin1 = 8;
const int motor3pin2 = 9;
const int motor4pin1 = 10;
const int motor4pin2 = 11;


const int fork1 = 12;
const int fork2 = 13;

void setup() 
{
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{


if (Serial.available()>0)
{  switch (Serial.read())
{
  case 'S':
    halt();
    Serial.println("Halt");
    break;  
  case 'F':
    forward();
    Serial.println("Forward");
    break;
  case 'L':
    hardleft();
    Serial.println("HardLeft");
    break;
  case 'B':
    backward();
    Serial.println("Backward");
    break;
  case 'R':
    hardright();
    Serial.println("HardRight");
    break;
   case 'G':
    left();
    Serial.println("left");
   case 'H':
    left();
    Serial.println("left");
    break;
   case 'I':
    right();
    Serial.println("right");
   case 'J':
    right();
    Serial.println("right");
  case 'W':
    lift();
    Serial.println("Lift");
    break;
  case 'U':
    drop();
    Serial.println("Drop");
    break;
  default:
    halt();
    Serial.println("Halt");
    break;
}
}

}

void forward()
{
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);
  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, HIGH);
  delay(50);
}
void backward()
{
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);
  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
  delay(50);
}
void halt()
{
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, LOW);
  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, LOW);
  digitalWrite(fork1, LOW);
  digitalWrite(fork2, LOW);
  delay(50);
}
void right()
{
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);
  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, HIGH);
  delay(50);
}
void left()
{
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);
  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
  delay(50);
}
void hardleft()
{
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);
  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, HIGH);
  delay(50);
}
void hardright()
{
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);
  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
  delay(50);
}
void lift ()
{
  digitalWrite(fork1, HIGH);
  digitalWrite(fork2, LOW);
  delay(50);
}
void drop ()
{
  digitalWrite(fork1, LOW);
  digitalWrite(fork2, HIGH);
  delay(50);
}
