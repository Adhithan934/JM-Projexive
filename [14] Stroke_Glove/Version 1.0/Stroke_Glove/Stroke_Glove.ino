#define CLK 2
#define DT 3
#define SW 4
int LED1 = 7;
int LED2 = 5;
int LED3 = 6;
int pump_state=11;
int pump_speed=12;
int solenoid1=9;
int solenoid2=10;


int LED_Stats[]={1,0,0};
bool btn1,btn2,btn3;
int counter = 0;
int currentStateCLK;
int lastStateCLK;
unsigned long lastButtonPress = 0;

void setup() 
{
  
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
  pinMode(SW, INPUT_PULLUP);
  Serial.begin(9600);
  for (int i=5;i<=12;i++)
  {
    pinMode(i,OUTPUT);
  }
  for (int i=9; i<=12; i++){
  digitalWrite(i, HIGH);
  delay(1);
  }  
  lastStateCLK = digitalRead(CLK);
  Serial.println("Started");
  
}

void loop() 
{
    encoder();
    operate();   
}
void operate()
{
    btn1=!digitalRead(SW);
  if(btn1&&500>analogRead(A0)&&500>analogRead(A0))
    {
    digitalWrite(LED1,LED_Stats[0]);
    digitalWrite(LED2,LED_Stats[1]);
    digitalWrite(LED3,LED_Stats[2]);

    digitalWrite(pump_state,(LED_Stats[0]&&LED_Stats[1]));
    digitalWrite(pump_speed,!LED_Stats[0]);
    digitalWrite(solenoid1,0);
    digitalWrite(solenoid2,!LED_Stats[2]);
    delay(150);
    
    }
    if((!btn1)&&(500<analogRead(A0)))
   {
    digitalWrite(pump_state,1);
    digitalWrite(pump_speed,1);
    digitalWrite(solenoid1,0);
    delay(150);
   }
    if((!btn1)&&(500<analogRead(A1)))
   {
    digitalWrite(pump_state,1);
    digitalWrite(pump_speed,1);
    digitalWrite(solenoid2,0);
    delay(150);
   }
    if(!btn1&&500>analogRead(A0)&&500>analogRead(A1))
    {
      for (int i=9; i<=12; i++){
      digitalWrite(i, HIGH);
      delay(1);
      }
    }
  
  for (int i=5;i<=8;i++)
  {
    digitalWrite(i,0);
  }
  
    delay(10);
}

void encoder()
{ 
  currentStateCLK = digitalRead(CLK);
  if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){
    if (digitalRead(DT) != currentStateCLK) {
      counter --;
    } else {
      counter ++;
    }
    counter=min(15,counter);
    counter=max(0,counter);
    if(counter>10)
    {
      LED_Stats[0]=1;
      LED_Stats[1]=1;
      LED_Stats[2]=1;
    }
    else if (counter>5&&counter<=10)
    {
      LED_Stats[0]=1;
      LED_Stats[1]=1;
      LED_Stats[2]=0;
    }
    else if (counter>=0&&counter<=5)
    {      
      LED_Stats[0]=1;
      LED_Stats[1]=0;
      LED_Stats[2]=0;
    }
    digitalWrite(LED1,LED_Stats[0]);
    digitalWrite(LED2,LED_Stats[1]);
    digitalWrite(LED3,LED_Stats[2]);
    delay(150);
    Serial.println(counter);  
  }
  lastStateCLK = currentStateCLK;
}
