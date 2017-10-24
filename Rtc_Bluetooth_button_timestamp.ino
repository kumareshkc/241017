#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
int buttonState1 = 0;


void setup() 
{
  Serial.begin(9600);
  while (!Serial) ; // wait for serial
  delay(200);
  pinMode(7,INPUT_PULLUP);
}

void loop()
{
   buttonState1 = digitalRead(7);
   tmElements_t tm;
 
   if (RTC.read(tm)) 
  {
     if (buttonState1 == LOW)      
    {
    print2digits(tm.Hour);
    Serial.write(':');
    print2digits(tm.Minute);
    Serial.write(':');
    print2digits(tm.Second);
    
    }    
  } 
  else 
  {
    if (RTC.chipPresent()) 
    {
      Serial.println("The DS1307 is stopped.  Please run the SetTime");
      Serial.println("example to initialize the time and begin running.");
      Serial.println();
    } 
    else
    {
      Serial.println("DS1307 read error!  Please check the circuitry.");
      Serial.println();
      delay(1000);
      }
      }
  delay(1000);
 }


void print2digits(int number) 
{
  if (number >= 0 && number < 10) 
  {
  Serial.write('0');
  }
  Serial.print(number);
}

