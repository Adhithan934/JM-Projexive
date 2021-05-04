//----------------PinOut declaration----------------
const int motor1pin1 = 3;
const int motor1pin2 = 2;
const int motor1Speed = 5;


//----------------Variable Declaration----------------
int current_Pos=2;
int final_Pos;
int max_val;
float ldr0,ldr1,ldr2,ldr3;
int change_Of_Pos=0;
float list[4];
int cycle=338*0.53;


//----------------Setup----------------
void setup() 
{
  Serial.begin(9600);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor1Speed, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(motor1Speed,1);
  for(float i=0;i<=100;i=i+(random(0,83647)/10000))
  {
    Serial.print("Initilising ");
    Serial.print(i);
    Serial.println(" %");
    digitalWrite(0,0);
    delay(50);
    digitalWrite(0,1);
    delay(50);  
  }
}


//----------------Looping----------------
void loop() 
{
  ldr_Read();
  float list[]={ldr0,ldr1,ldr2,ldr3};

   final_Pos=-1;
   max_val=-1;
   for (int i=0; i<4; i++)
   {
    if(max_val<list[i])
    {
      final_Pos=i;
      max_val=list[i];
    }
   Serial.print(list[i]);
   Serial.print("\t");
   }

   Serial.print("current_Pos: ");
   Serial.print(current_Pos);
   Serial.print("\t");
   Serial.print("final_Pos: ");
   Serial.print(final_Pos);
   Serial.print("\t");  

   
   poschange();

   delay(3000);
   Serial.println("");  
}

//----------------Functions----------------
void ldr_Read()
{
   digitalWrite(LED_BUILTIN,1);
   delay(100);
   digitalWrite(LED_BUILTIN,0);
   ldr0=map(analogRead(A0),1024,0,0,100);
   ldr1=map(analogRead(A1),1024,0,0,100);
   ldr2=map(analogRead(A2),1024,0,0,100);
   ldr3=map(analogRead(A3),1024,0,0,100);
}
   
void clockwise()
{
  delay(2000);
   for(int i=0;i<=100;i=i+10)
  {
    Serial.print("Powering Motor ");
    Serial.print(i);
    Serial.println(" %");
    delay(100);
  } 
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  for(float i=0;i<=cycle; i++)
    {
      delay(1000);
      Serial.println("");
      Serial.print("Rotating Clockwise ");
      float progress=i*100/cycle; 
      Serial.print(progress);
      Serial.print(" %");   
    }
    
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
    
}


void anti_clockwise()
{
 delay(2000);
 for(int i=0;i<=100;i=i+10)
  {
    Serial.print("Powering Motor ");
    Serial.print(i);
    Serial.println(" %");
    delay(100);
  } 
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  for(float i=0;i<=cycle; i++)
    {
      delay(1000);
      Serial.println("");
      Serial.print("Rotating Anti Clockwise ");
      float progress=i*100/cycle; 
      Serial.print(progress);
      Serial.print(" %");   
    }
    
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
    
}


void poschange()
{
  change_Of_Pos=min(final_Pos-current_Pos,current_Pos-final_Pos)*-1;
  Serial.print("change_Of_Pos: ");
  Serial.print(change_Of_Pos);
  Serial.print("\t");
  if(change_Of_Pos<=2)
  {
      if (final_Pos>current_Pos)
      {
          Serial.print("Clockwise * ");
          Serial.print(change_Of_Pos);
        for (int i=1;i<=change_Of_Pos;i++)
        {
          clockwise();
        }
      }
      if (final_Pos<current_Pos)
      {
          Serial.print("Anti Clockwise * ");
          Serial.print(change_Of_Pos);
        for (int i=1;i<=change_Of_Pos;i++)
        {
          anti_clockwise();
        }
                
      }
      if(final_Pos==current_Pos)
      {
       Serial.print("No change");  
      }
  }
  else if (change_Of_Pos==3)
  {
    change_Of_Pos=4-change_Of_Pos;

    if (final_Pos<current_Pos)
      {
          Serial.print("Clockwise * ");
          Serial.print(change_Of_Pos);
        for (int i=1;i<=change_Of_Pos;i++)
        {
            clockwise();
        }
      }
      if (final_Pos>current_Pos)
      {
          Serial.print("Anti Clockwise * ");
          Serial.print(change_Of_Pos);
        for (int i=1;i<=change_Of_Pos;i++)
        {
          anti_clockwise();
        }
  }
  }
  
  current_Pos=final_Pos;
}
