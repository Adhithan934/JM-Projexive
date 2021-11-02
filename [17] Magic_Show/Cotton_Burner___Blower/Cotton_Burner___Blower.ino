void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {

  if (Serial.available())
  {
    char temp = Serial.read();
    if (temp == 'F')
    {
      digitalWrite(2, 1);
      delay(1000);
    }
    if (temp == 'B')
    {
      digitalWrite(3, 1);
      delay(1000);
    }
    if (temp == 'L')
    {
      digitalWrite(4, 1);
      delay(1000);
    }
    if (temp == 'R')
    {
      digitalWrite(5, 1);
      delay(1000);
    }
    if (temp == 'W')
    {
      digitalWrite(6, 1);
      delay(1000);
    }
    if (temp == 'U')
    {
      digitalWrite(7, 1);
      delay(1000);
    }
    if (temp == 'V')
    {
      digitalWrite(8, 1);
      digitalWrite(9, 1);
      delay(1000);
    }

    if (temp == 'v')
    {
      digitalWrite(8, 0);
      digitalWrite(9, 0);
      delay(1000);
    }
    for (int i = 2; i <= 7; i++)
    {
      digitalWrite(i, 0);

    }
  }

}
