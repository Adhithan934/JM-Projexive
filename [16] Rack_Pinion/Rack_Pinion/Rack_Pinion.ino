// <> on 13/11/2021
//----GENERIC INFO----
//Programmed for Rack and pinion, motor has high speed fluctuation with load.
//The gear box provides high inertia, so calibration needs to be done in run time envroinment
//Motor also has different forward and reverse speed
//
//----FEATURES----
//This pgm has the ability to restore to start(precisly) even when the handle is placed while while the rack is moving forward
//
//----MODES----
//MCU is operated in 2 modes
//1. Working mode - Regular working
//2. Calibrating mode - MCU gets input from the calibration pot, shouldn't be made to run on this mode
//
//----PINOUTS----
//A1 - toggle switch from the handle
//A2- toggle switch to switch operating modes
//A3 - Pot for calibrating
//8,9 - Motor connection

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}


int temp = 1;
float calibration = 1;
bool flag ;
float static_range = 0;
int static_duration = 375;//Decides the min range
int counter = 0;
float range;
float duration = static_duration;
void loop() {
  float calib;
  flag = 0 ;
  if (analogRead(A1) > 500)
  {
    flag = 1;
  }

  if (flag) {
    range = analogRead(A3);
    calib = analogRead(A2);


    calibration = map(calib, 1, 1024, 75, 125);
    calibration = calibration/100;

    range = map(range, 1, 1024, 0, 150);//Decides the max range, max range = static_duration + 150
    duration = static_duration + range;
  }
  int sensor = analogRead(A0);

  if ((sensor  < 300) && (temp < duration))
  {
    Serial.print("Fowd");
    fwd();
    temp = temp + (10 * calibration);
  }
  else if ((sensor  > 300) && (temp > 1))
  {
    back();
    Serial.print("Back");
    temp = temp - 10;
  }
  else
  {
    halt();
    Serial.print("Halt");
  }

  display();
  Serial.println();
}
void fwd()
{
  digitalWrite(8, 0);
  digitalWrite(9, 1);
  delay(1);
}
void back()
{
  digitalWrite(8, 1);
  digitalWrite(9, 0);
  delay(1);

}
void halt()
{
  digitalWrite(8, 0);
  digitalWrite(9, 0);
  delay(1);
}
void display()
{
  Serial.print("\t");
  Serial.print("Calibration : ");
  Serial.print(calibration);
  Serial.print("\t");
  Serial.print("flag : ");
  Serial.print(flag);
  Serial.print("\t");
  Serial.print("range : ");
  Serial.print(duration);
}
