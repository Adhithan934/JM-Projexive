#include <dht.h>
#define dht_apin A1 
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
dht DHT;

byte customChar[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};


int count = 0;
void setup(){
 
  Serial.begin(9600);
  lcd.begin(16, 2);  
  lcd.createChar(0, customChar);
  lcd.setCursor(0, 0);
  lcd.print("Booting system");
  for (int i=0; i<16;i++)
  {
    lcd.setCursor(i, 1);
    lcd.write(byte(0));
    delay(50);
    count ++;
    if(i==15&&count<16*5)
    {
      i=-1;
      lcd.setCursor(0, 1);
      lcd.print("                ");
    }
    
  }
      clean();
}
float a=0,b=0,c=0,d=0,e=0;
void loop(){
    DHT.read11(dht_apin);
//    a=DHT.humidity;
//    b=DHT.temperature;
//    c=analogRead(A3);
//    d=analogRead(A4);
//    e=analogRead(A5);
//    Serial.print(a);
//    Serial.print("\t");
//    Serial.print(b); 
//    Serial.print("\t");
//    Serial.print(c);
//    Serial.print("\t");
//    Serial.print(d);
//    Serial.print("\t");
//    Serial.println(e);


    


    
    lcd.setCursor(0,0);
    lcd.print("Humidity: ");
    lcd.print(DHT.humidity);
    delay(2000);
    clean();
    
    lcd.setCursor(0,0);
    lcd.print("Temp: ");
    lcd.print(DHT.temperature);
    lcd.print(" C");
    delay(2000);
    clean();    

    lcd.setCursor(0,0);
    lcd.print("Methane: ");
    lcd.print(analogRead(A3));
    delay(2000);
    clean();
    
    lcd.setCursor(0,0);
    lcd.print("MQ135 : ");
    lcd.print(analogRead(A4));
    delay(2000);
    clean();
    
    lcd.setCursor(0,0);
    lcd.print("MQ7 : ");
    lcd.print(analogRead(A5));
    delay(2000);
    clean();


}
void clean()
{
    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print("                ");
}
