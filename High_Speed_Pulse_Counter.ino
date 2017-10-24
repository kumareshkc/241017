#include <LiquidCrystal_I2C.h>      
LiquidCrystal_I2C lcd(0x3F, 20, 4); 

// initialise the buttons

const int buttonPin1 = 2;           //UP 
const int buttonPin2 = 3;           //DOWN
const int buttonPin3 = 4;           //ENTER
const int buttonPin4 = 5;           //EXIT

const int  pulsePin = 52; 

//initialise the pages

int mainpage = 1;   
int pulsepage = 0;   
int fiftykpage = 0;
int serialpage = 0;
int debugpage = 0;

int Counter1 = 1;
int Counter2 = 0;
int Counter3 = 0;  

int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

int buttonState1 = 0;        
int lastButtonState1 = 0;  

int buttonState2 = 0;       
int lastButtonState2 = 0;    

int buttonState3 = 0;        
int lastButtonState3 = 0;  
  
int buttonState4 = 0;        
int lastButtonState4 = 0;    


void setup()
{
  Serial.begin(115200);   
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP); 

  pinMode(pulsePin, INPUT);

  delay(500);              // a small delay to begin the process
  lcd.begin();             // beginning the lcd mode
  lcd.backlight();         // turn on the backlight for the lcd
  lcd.clear();
  lcd.setCursor(7, 1);
  lcd.print("HELLO");      // printing a hello message  
  delay(500);
  lcd.clear();
  lcd.setCursor(7, 1);
  lcd.print("WELCOME");    //printing a welcome message 
  delay(500);
   lcd.setCursor(0, 1);
  lcd.print(" HIGH SPEED PULSE  ");    //printing a welcome message 
   lcd.setCursor(0, 2);
  lcd.print("       COUNTER     ");
  delay(500);
  lcd.clear();

}
/////////////////////initialise the main page////////////////////////////////////////////////

void MainPage()
{

  if (mainpage == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print(" CHOOSE YOUR OPTION");
    lcd.setCursor(0, 2);
    lcd.print(" 1.PULSE   3.SERIAL ");
    lcd.setCursor(0, 3);
    lcd.print(" 2.50,000  4.DEBUG ");
  }
}
////////////////////////initialise the pulse page /////////////////////////////////////////////


void PulsePage()
{
  if (pulsepage == 1)
  {
   // y=Counter2;
    lcd.setCursor(0, 0);
    lcd.print("TOTAL NO. OF PULSES");
    lcd.setCursor(0, 1);
    lcd.print("    PRODUCED IS     ");
    lcd.setCursor(0, 2);
    lcd.print("                    ");
    lcd.setCursor(0, 3);
    lcd.print("                    ");
    lcd.setCursor(9, 3);
    lcd.print(Counter2);
 
  }
}
///////////////////////initialise the fiftyk page //////////////////////////////////////////////

void FiftykPage()
{
   
  if (fiftykpage == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print("TOTAL NO. OF 50K ");
    lcd.setCursor(0, 1);
    lcd.print("    PRODUCED IS     ");
    lcd.setCursor(0, 2);
    lcd.print("                    ");
    lcd.setCursor(0, 3);
    lcd.print("                    ");
    lcd.setCursor(9, 3);
    lcd.print(Counter3);
    }
 
}
////////////////////////initialise the serial page////////////////////////////////////////////////

void SerialPage()
{
  if (serialpage == 1)
  {
    Serial.print("PULSE VALUE IS ");
    Serial.println(Counter2);
    Serial.print("50,000 COUNT VALUE IS ");
    Serial.println(Counter3);
    lcd.setCursor(0, 0);
    lcd.print(" THE VALUES OF PULSE");
    lcd.setCursor(0, 1);
    lcd.print("  AND FIFTY K ARE");
    lcd.setCursor(0, 2);
    lcd.print(" BEING DISPLAYED IN ");
    lcd.setCursor(0, 3);
    lcd.print(" THE SERIAL TERMINAL ");
  }
}
////////////////////initialise the debug page ///////////////////////////////////////////////////////

void DebugPage()
{
  if (debugpage == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print("     DEBUG MODE     ");

    
    if(Counter2>0)
    {
      lcd.setCursor(0, 1);
      lcd.print("   PULSE IS PROPER  ");
    }
    else
    {
      lcd.setCursor(0, 1);
      lcd.print("PULSE IS NOT PROPER");      
    }

    
     if(Counter3>0)
    {
      lcd.setCursor(0, 2);
      lcd.print("   50K IS PROPER    ");
    }
    else
    {
      lcd.setCursor(0, 2);
      lcd.print("  50K IS NOT PROPER  ");      
    }

    
    if(Serial.available())
    {
    lcd.setCursor(0, 3);
    lcd.print("SERIAL IS AVAILABLE");
    }
    else
    {
    lcd.setCursor(0, 3);
    lcd.print("SERIAL NOT AVAILABLE");
    }    
  }
}
//////////////////////initialise the main counter ///////////////////////////////////////////////////////

void MainCounter()
{
  if (Counter1 == 1 && mainpage == 1)
  {
    lcd.setCursor(0, 2);
    lcd.print(">");                   
    lcd.setCursor(0, 3);
    lcd.print(" ");                  
    lcd.setCursor(10, 2);
    lcd.print(" ");                 
    lcd.setCursor(10, 3);
    lcd.print(" ");                     
   }
  if (Counter1 == 2 && mainpage == 1)
  {
    lcd.setCursor(0, 2);
    lcd.print(" ");                 
    lcd.setCursor(0, 3);
    lcd.print(">");                   
    lcd.setCursor(10, 2);
    lcd.print(" ");                 
    lcd.setCursor(10, 3);
    lcd.print(" ");        
    }
  if (Counter1 == 3 && mainpage == 1)
  {
    lcd.setCursor(0, 2);
    lcd.print(" ");                
    lcd.setCursor(0, 3);
    lcd.print(" ");                
    lcd.setCursor(10, 2);
    lcd.print(">");                   
    lcd.setCursor(10, 3);
    lcd.print(" ");                
  }
  if (Counter1 == 4 && mainpage == 1)
  {
    lcd.setCursor(0, 2);
    lcd.print(" ");                 
    lcd.setCursor(0, 3);
    lcd.print(" ");                 
    lcd.setCursor(10, 2);
    lcd.print(" ");                 
    lcd.setCursor(10, 3);
    lcd.print(">");                  
  }
}

//////////////////////////////initialise the button state ////////////////////////////////////////////////

void ButtonState()
{
  buttonState1 = digitalRead(buttonPin1);   // read the buttonstate1 as input from button1 
  buttonState2 = digitalRead(buttonPin2);   // read the buttonstate2 as input from button2 
  buttonState3 = digitalRead(buttonPin3);   // read the buttonstate3 as input from button3 
  buttonState4 = digitalRead(buttonPin4);   // read the buttonstate4 as input from button4 

  if (buttonState1 != lastButtonState1)
  {
    if (buttonState1 == LOW)       
    {
      if (mainpage == 1)           
      {
        if (Counter1 < 4)
        {
          Counter1++;
        }
        else
        {
          Counter1 = 1;
        }
      }      
    }
  }

  if (buttonState2 != lastButtonState2)
  {
    if (buttonState2 == LOW)     
    {
      if (mainpage == 1)        
      {
        if (Counter1 > 1)
        {
          Counter1--;
        }
        else
        {
          Counter1 = 4;
        }
      }
    }
  }  
   if (buttonState3 != lastButtonState3)
  {
    if (buttonState3 == LOW)      
    {
      if (mainpage == 1)         
      {
        PageSelection();
      }     
    }
  }
  if (buttonState4 == LOW)             
  {
    lcd.clear();
    lcd.setCursor(0, 1); 
    lcd.print("                ");   
    lcd.setCursor(6, 1);  
    lcd.print("THANK YOU");     
    delay(500);
    lcd.clear();
    DefaultSetup();                   
  }
  lastButtonState1 = buttonState1;    //define that the laststate and present state are equal for button 1
  lastButtonState2 = buttonState2;    //define that the laststate and present state are equal for button 2
  lastButtonState3 = buttonState3;    //define that the laststate and present state are equal for button 3
  lastButtonState4 = buttonState4;    //define that the laststate and present state are equal for button 4
}
//////////////initialise the default settings ///////////////////////////////////////

void DefaultSetup()
{
  MainPage();
  mainpage = 1;
  pulsepage = 0;
  fiftykpage = 0;
  serialpage = 0;
  debugpage = 0;
  Counter1 = 1;  
}
//////////////////initialise the page settings //////////////////////////////////

void PageSelection()
{
  if (Counter1 == 1)   
  {
    mainpage = 0;
    pulsepage = 1;
    fiftykpage = 0;
    serialpage = 0;
    debugpage = 0;
    DeterminePage();
  }
  if (Counter1 == 2)   
  {
    mainpage = 0;
    pulsepage = 0;
    fiftykpage = 1;
    serialpage = 0;
    debugpage = 0;
    DeterminePage();
  }
  if (Counter1 == 3)   
  {
    mainpage = 0;
    pulsepage = 0;
    fiftykpage = 0;
    serialpage = 1;
    debugpage = 0;
    DeterminePage();
  }
  if (Counter1 == 4)  
  {
    mainpage = 0;
    pulsepage = 0;
    fiftykpage = 0;
    serialpage = 0;
    debugpage = 1;
    DeterminePage();
  }
}

/////////////////initialise which page is to be determined ///////////////////////////////////
 
void DeterminePage()
{
  if (pulsepage == 1 && mainpage == 0)   
  {
    PulsePage();
     }
  else if (fiftykpage == 1 && mainpage == 0)   
  {
    FiftykPage();    
  }
  else if (serialpage == 1 && mainpage == 0)   
  {
    SerialPage();   
  }
  else if (debugpage == 1 && mainpage == 0)      
  {
    DebugPage();   
  }
  else
  {
    DefaultSetup();                            
  }
}

void Pulse()
{  
  buttonState = digitalRead(pulsePin);
if (buttonState != lastButtonState)
  {
    if (buttonState == HIGH)
    {
    Counter2++;
     if(Counter2%64 == 0)
        {
         Counter3++;
         }
    }     
  }
  lastButtonState = buttonState;   
 
 }

void loop()
{
  Pulse();
  MainPage();
  ButtonState();
  MainCounter();  
 }
//////////////////////////////////////////////////////////////////////

