//----------------PinOut declaration----------------
#define CLK 2
#define DT 3


int LED1 = 4;
int LED2 = A4;
int LED3 = A3;
int LED4 = 12;
int LED5 = 13;
int pump_state = 7;
int pump_speed = 6;
int solenoid1 = 8;
int solenoid4 = 9;
int solenoid3 = 10;
int solenoid2 = 11;
int solenoid5 = 5;



//----------------Variable Declaration----------------
int finger[] = {1, 0, 0, 0, 0};
bool btn1, btn2, btn3, btn4;
int counter = 0;
int currentStateCLK;
int lastStateCLK;
unsigned long lastButtonPress = 0;
int automatic_Mode_Pump_Time = 5000;
int automatic_Mode_Delay_Time = 5000;
int flag = 0;



//----------------Setup----------------
void setup()
{

  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  Serial.begin(9600);
  for (int i = 4; i <= 13; i++)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, INPUT);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  lastStateCLK = digitalRead(CLK);
  Serial.println("Started");
  for (int i = 0; i <= random(7, 16) ; i++) {
    LED_Pass();
  }
}

void loop()
{
  get_Input();
  operate();
}
void LED_Pass()
{

  digitalWrite(LED1, 1);
  delay(15);
  digitalWrite(LED1, 0);
  delay(15);
  digitalWrite(LED2, 1);
  delay(15);
  digitalWrite(LED2, 0);
  delay(15);
  digitalWrite(LED3, 1);
  delay(15);
  digitalWrite(LED3, 0);
  delay(15);
  digitalWrite(LED4, 1);
  delay(15);
  digitalWrite(LED4, 0);
  delay(15);
  digitalWrite(LED5, 1);
  delay(15);
  digitalWrite(LED5, 0);
  delay(100);
}
void get_Input()
{
  currentStateCLK = digitalRead(CLK);
  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1) {
    if (digitalRead(DT) != currentStateCLK) {
      counter ++;
    } else {
      counter --;
    }
    counter = min(9, counter);
    counter = max(0, counter);

    finger[0] = 0;
    finger[1] = 0;
    finger[2] = 0;
    finger[3] = 0;
    finger[4] = 0;
    finger[(counter / 2)] = 1;
    //    Serial.print(counter);
    //    Serial.print("\t\t");
    //    Serial.println(counter / 2);



    digitalWrite(LED1, finger[0]);
    digitalWrite(LED2, finger[1]);
    digitalWrite(LED3, finger[2]);
    digitalWrite(LED4, finger[3]);
    digitalWrite(LED5, finger[4]);

    delay(15);
  }

  lastStateCLK = currentStateCLK;
  btn1 = !(analogRead(A5));
  delay(10);
  btn1 = btn1 && !(analogRead(A5));

  btn2 = !digitalRead(A0);
  btn3 = !digitalRead(A1);
  btn4 = !(analogRead(A2));




  flag = 0;

  if (btn1 && !(btn2 || btn3))
  {
    flag = 1;
  }
  if (btn2 && !(btn1 || btn3))
  {
    flag = 2;
  }
  if (btn3 && !(btn1 || btn2))
  {
    flag = 3;
  }
  if ((btn3 && btn2))
  {
    flag = 4;
  }
  delay(5);
  Serial.println(flag);
}


void print_LED()
{
  digitalWrite(LED1, finger[0]);
  digitalWrite(LED2, finger[1]);
  digitalWrite(LED3, finger[2]);
  digitalWrite(LED4, finger[3]);
  digitalWrite(LED5, finger[4]);
}
void operate()
{
  pump_Speed();


  switch (flag) {
    case 1:
      {
        print_LED();



        digitalWrite(pump_state, 0);

        digitalWrite(solenoid1, finger[0]);
        digitalWrite(solenoid2, finger[1]);
        digitalWrite(solenoid3, finger[2]);
        digitalWrite(solenoid4, finger[3]);
        digitalWrite(solenoid5, !finger[4]);

        delay(100);
        for (int i = 0; i <= 4; i++)
        {
          if (finger[i])
          {
            Serial.print("Pumping ");
            Serial.print(i + 1);
            Serial.print(" Finger");
            Serial.print("\t\t Pump Speed = ");
            Serial.print(btn4);
          }
        }

      }
      break;

    case 2:
      {
        digitalWrite(LED1, 1);
        digitalWrite(LED2, 1);
        digitalWrite(LED3, 1);
        digitalWrite(LED4, 1);
        digitalWrite(LED5, 1);

        digitalWrite(pump_state, 0);

        digitalWrite(solenoid1, 1);
        digitalWrite(solenoid2, 1);
        digitalWrite(solenoid3, 1);
        digitalWrite(solenoid4, 1);
        digitalWrite(solenoid5, 0);

        delay(100);
        Serial.print("Pumping all finger");
        Serial.print("\t\t Pump Speed = ");
        Serial.print(btn4);
      }
      break;


    case 3:
      {
        digitalWrite(pump_state, 1);

        digitalWrite(solenoid1, 1);
        digitalWrite(solenoid2, 1);
        digitalWrite(solenoid3, 1);
        digitalWrite(solenoid4, 1);
        digitalWrite(solenoid5, 0);

        delay(100);
        Serial.print("Releasing all finger");
      }
      break;

    case 4:
      {
        digitalWrite(pump_state, 0);

        digitalWrite(solenoid1, 1);
        digitalWrite(solenoid2, 1);
        digitalWrite(solenoid3, 1);
        digitalWrite(solenoid4, 1);
        digitalWrite(solenoid5, 0);

        for (int i = 0; i < (automatic_Mode_Pump_Time / 100); i++)
        {
          Serial.print("Automatic mode in progress -- Pumpming \t\t");
          Serial.print("Progress level : ");
          Serial.print(i * 100 / (automatic_Mode_Pump_Time / 100));
          Serial.println(" %");
          digitalWrite(LED1, (i % 2));
          digitalWrite(LED2, (i % 2));
          digitalWrite(LED3, (i % 2));
          digitalWrite(LED4, (i % 2));
          digitalWrite(LED5, (i % 2));
          delay(100);
        }

        digitalWrite(pump_state, 1);

        digitalWrite(solenoid1, 0);
        digitalWrite(solenoid2, 0);
        digitalWrite(solenoid3, 0);
        digitalWrite(solenoid4, 0);
        digitalWrite(solenoid5, 1);



        for (int i = 0; i < (automatic_Mode_Delay_Time / 235); i++)
        {

          Serial.print("Automatic mode in progress -- Holding \t\t");
          Serial.print("Progress level : ");
          Serial.print(i * 100 / (automatic_Mode_Delay_Time / 235));
          Serial.println(" %");
          LED_Pass();
        }



        digitalWrite(pump_state, 1);

        digitalWrite(solenoid1, 1);
        digitalWrite(solenoid2, 1);
        digitalWrite(solenoid3, 1);
        digitalWrite(solenoid4, 1);
        digitalWrite(solenoid5, 0);


        for (int i = 0; i < (automatic_Mode_Pump_Time / 100); i++)
        {

          Serial.print("Automatic mode in progress -- Releasing \t\t");
          Serial.print("Progress level : ");
          Serial.print(i * 100 / (automatic_Mode_Pump_Time / 100));
          Serial.println(" %");
          digitalWrite(LED1, (i % 2));
          digitalWrite(LED2, (i % 2));
          digitalWrite(LED3, (i % 2));
          digitalWrite(LED4, (i % 2));
          digitalWrite(LED5, (i % 2));
          delay(100);
        }
      }
      break;
    default:
      {
        digitalWrite(LED1, 0);
        digitalWrite(LED2, 0);
        digitalWrite(LED3, 0);
        digitalWrite(LED4, 0);
        digitalWrite(LED5, 0);

        digitalWrite(pump_state, 1);

        digitalWrite(solenoid1, 0);
        digitalWrite(solenoid2, 0);
        digitalWrite(solenoid3, 0);
        digitalWrite(solenoid4, 0);
        digitalWrite(solenoid5, 1);

        Serial.print("Idle State");
        delay(5);
      }
      break;

  }
  Serial.println("");
}

void pump_Speed()
{
  if (btn4)
  {
    digitalWrite(pump_speed, 0);
  } else
  {
    digitalWrite(pump_speed, 1);
  }
}
