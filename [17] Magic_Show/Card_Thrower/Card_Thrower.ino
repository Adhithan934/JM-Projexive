void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  digitalWrite(2, 1);

  digitalWrite(13, 0);
}

void loop() {

  int ir = analogRead(A0);
    Serial.println(ir);

  if (Serial.available())
  {
    char temp = Serial.read();
    if (temp == 'F')
    {
      digitalWrite(13, 1);
      delay(100);
    }

  }
  else if (ir < 500)
  {
    digitalWrite(13, 0);
    delay(100);
  }
}
