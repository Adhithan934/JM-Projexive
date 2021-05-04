#include <SFE_BMP180.h>
#include <Wire.h>


SFE_BMP180 pressure;

double baseline; 

void setup()
{
  pinMode(A0,OUTPUT);
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

Serial.println(P);
 
  a = pressure.altitude(P,baseline); 
  delay(5);
  int val= map(P,900,1200,0,1023);
  analogWrite(2,val);
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
