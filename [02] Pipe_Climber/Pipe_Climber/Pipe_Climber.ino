#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  pinMode(28, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(53, OUTPUT);
  digitalWrite(28,0);
  digitalWrite(32,0);
  analogWrite(30,512);//LED
  digitalWrite(34,1);
  
  Serial.begin(9600);
}
int i=0;
int Sensor;
int threshold=350;
void loop() {
  Sensor=analogRead(A0);
  Serial.println(Sensor);
  analogWrite(46,100);//Contrast
  if (i==0)
  {
    lcd.setCursor(0,0);
    lcd.print("Please Wait    ");
    lcd.setCursor(0,1);
    lcd.print("Starting Sensor ");
    i=1;
    delay(3000);
  }
  if (Sensor>threshold)
  {
    lcd.setCursor(0,0);
    lcd.print("Attention!      ");
    lcd.setCursor(0,1);
    lcd.print("Gas Dedected    ");
    digitalWrite(53,1);
  }
  if(Sensor<threshold)
  {
    lcd.setCursor(0,0);
    lcd.print("No Gas Dedected ");
    lcd.setCursor(0,1);
    lcd.print("                ");
    digitalWrite(53,0);
  }
}
