void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(13, 0);
  digitalWrite(3, 0);
  delay(100);
}

void loop() {
  if (Serial.available())
  {
    char temp = Serial.read();
    if (temp == 'F')
    {
      digitalWrite(13, 1);
      delay(1000);
      digitalWrite(13, 0);
    }
    if (temp == 'B')
    {
      digitalWrite(3, 1);
      delay(1000);
      digitalWrite(3, 0);
    }
  }
}
