#include <Arduino.h>
#include <TM1637Display.h>
#define CLK 4
#define DIO 5
#define TEST_DELAY 500
TM1637Display display(CLK, DIO);

int x = 5;
int Counter1 = 1;
int Counter2 = 1;

int y;
int z;
int e;
int f;
int l;
int m;
int n;

int c;

int buttonState1 = 0;         // current state of the button 1
int buttonState2 = 0;         // current state of the button 2
int lastButtonState1 = 0;     // previous state of the button 1
int lastButtonState2 = 0;     // previous state of the button 2

int encoder_pin = 2;// The pin the encoder is connected(the IR sensor signal pin)

const int D = 7; // Diameter in cm (include at the top)
const int buttonPin1 = 8;           
const int buttonPin2 = 9;         
const int enable1 = 10;

unsigned int pulsesperturn = 1;
unsigned int rpm;// rpm reading

unsigned long timeold;// The number of pulses per revolution

volatile byte pulses;// number of pulses

#include <Average.h>

Average<unsigned int> ave(30);
Average<unsigned int> ave1(20);
Average<unsigned int> ave2(20);
Average<unsigned int> ave3(10);
Average<unsigned int> ave4(10);
Average<unsigned int> ave5(10);

void counter()
{
   pulses++;
}

void setup()
{
  Serial.begin(9600);
 
   pinMode(buttonPin1, INPUT_PULLUP);
   pinMode(buttonPin2, INPUT_PULLUP);
   pinMode(enable1, OUTPUT);
 
   pinMode(11, OUTPUT);
   pinMode(12, OUTPUT);
    
   digitalWrite(11,HIGH);
   digitalWrite(12,LOW); 
   digitalWrite(10,HIGH);

    pinMode(3,INPUT);

 pinMode(encoder_pin, INPUT);
 attachInterrupt(0, counter, FALLING);
 pulses = 0;
 rpm = 0;
 timeold = 0; 
}

void rev()
{

  if (millis() - timeold >= 1000)
    {
        detachInterrupt(0);
        rpm = (60 * 1000 / pulsesperturn )/ (millis() - timeold)* pulses;
        //speed = 3.14159*(D/100)*(rpm/60) // speed in m/s
        //speed = 3.14159*(D/100000)*(rpm*60) // speed in km/hr
        timeold = millis();
        pulses = 0;        
       // Serial.print("RPM = ");
       // Serial.println(rpm,DEC); 
        y=rpm;      
        attachInterrupt(0, counter, FALLING);        
    }
     ave.push(y);
     z=round(ave.mean());
     delay(50);
     ave1.push(z);
     e=round(ave1.mean());
     delay(50);
     ave2.push(e);
     f=round(ave2.mean());
     delay(50);
      ave3.push(f);
     l=round(ave3.mean());
     delay(50);
      ave4.push(l);
     m=round(ave4.mean());
     ave5.push(m);
     n=round(ave5.mean());
    Serial.println(n);
   // delay(50);
    display.setBrightness(0x0f);
    bool lz = true; 
    display.showNumberDec(m, lz);
    c = analogRead(3);
    Serial.print("current is ");
    Serial.println(c); 
    //delay(TEST_DELAY);
} 
void ButtonState()
{
 buttonState1 = digitalRead(buttonPin1);   
 buttonState2 = digitalRead(buttonPin2);   

 if (buttonState1 != lastButtonState1)
  {
    if (buttonState1 == LOW)
       {       
        Speedinc();
       }
   }

   if (buttonState2 != lastButtonState2)
       {
       if (buttonState2 == LOW)
           {       
           Speeddec();
           }
        }
 lastButtonState1 = buttonState1;    
 lastButtonState2 = buttonState2;   
}

 void Speedinc()
 {
  if (Counter1 < 10)      // the increment value is set to perform 25 counts 
  {
    delay(200);
    x = x + 25;
    Speed();
    Counter2++;
  }
}

void Speeddec()
{
  if (Counter1 > 0)
  {
    delay(200);
    x = x - 25;
    Speed();
    Counter2--;
  }
}

void Speed()
{
 analogWrite(enable1 , x);
}

void loop()
{
 rev();
 ButtonState();
 Speed();     
 }

