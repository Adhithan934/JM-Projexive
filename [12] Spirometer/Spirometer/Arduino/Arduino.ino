#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#include <SFE_BMP180.h>
#include <Wire.h>


SFE_BMP180 pressure;

double baseline; 


void setup() {
  lcd.begin(16, 2);
  lcd.print("Pressure Diff:");
  pinMode(8,OUTPUT);
  digitalWrite(8,1);




  Serial.begin(9600);
  Serial.println("REBOOT");

  if (pressure.begin())
    Serial.println("BMP180 init success");
  else
  {

    Serial.println("BMP180 init fail (disconnected?)\n\n");
 
  }

  
  baseline = getPressure();
  
  Serial.print("baseline pressure: ");
  Serial.print(baseline);
  Serial.println(" mb");  




  
}

void loop() 
{
 double a,P;
  
 
  P = getPressure();


 
  a = pressure.altitude(P,baseline); 
  delay(5);
  int val=analogRead(2);
  if (val<10)
  {
//  Serial.print(P);
//  Serial.print("\t\t");
  float val=map(val,1023,0,900,1200);
  val=val-190.5;
//  Serial.print(val);
//  Serial.print("\t\t");
  float diff=P-val;
  Serial.print(diff);
  Serial.println("");
  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print(diff);
  delay(500);  

  
  }
}


double getPressure()
{
  char status;
  double T,P,p0,a;

  status = pressure.startTemperature();
  if (status != 0)
  {

    delay(status);

    status = pressure.getTemperature(T);
    if (status != 0)
    {
   
      status = pressure.startPressure(3);
      if (status != 0)
      {
        delay(status);

   
        status = pressure.getPressure(P,T);
        if (status != 0)
        {
          return(P);
        }
        else Serial.println("error retrieving pressure measurement\n");
      }
      else Serial.println("error starting pressure measurement\n");
    }
    else Serial.println("error retrieving temperature measurement\n");
  }
  else Serial.println("error starting temperature measurement\n");
}
