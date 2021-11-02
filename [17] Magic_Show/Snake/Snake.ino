void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available())
  {
    char temp = Serial.read();
    if (temp == 'F')
    {
      digitalWrite(13, 1);
      delay(10);
    }
    if (temp == 'B')
    {
      digitalWrite(13, 0);
      delay(10);
    }
    if (temp == 'L')
    {
      digitalWrite(12, 1);
      delay(1000);
      digitalWrite(12, 0);
    }
  }
}
