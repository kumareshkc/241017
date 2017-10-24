#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

long microSecs;
long freq;
int lastBit;
int nowVal;

int x=0;

long secs;
long maxHz;
long minHz;
long minmax;

void setup() 

{
  lcd.begin(16, 2);
  lcd.print("Loading...");
  pinMode(A1,INPUT);
  pinMode(A5,OUTPUT);
  microSecs = micros();
  freq = 0;
  lastBit = 0;
  nowVal =0;
  maxHz=0;
  minHz=0;
  minmax=0;
  secs = millis();
  //Serial.begin(9600);
}


void loop()  
  {

  if ((microSecs+20)<micros())
  {
    nowVal=digitalRead(A1);
    
    if (lastBit!=nowVal) 
        {
          lastBit=nowVal;
          freq=freq+1;
        }
    if (freq>maxHz)
      {
        maxHz=freq;
      }
    if (freq<minHz)
      {
        minHz=freq;
      }
      //lcd.clear();
      //lcd.print();
   microSecs = micros();
  }
  
  if (secs+1000<millis())
  {
  if (minmax+300000<millis())
    {
      minmax=millis();
      minHz=freq;
      maxHz=freq;
      }
      
      lcd.clear();
      lcd.print((freq/2));
      lcd.print("hz");
      lcd.setCursor(0,1);
      lcd.print("+: ");
      lcd.print(maxHz);
      lcd.print(" -: ");
      lcd.print(minHz);
      
      freq=0;
      secs=millis();
     }
     }
