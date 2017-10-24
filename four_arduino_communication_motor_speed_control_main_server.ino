#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x3F, 20, 4);
const int buttonPin1 = 5;           //UP
const int buttonPin2 = 4;           //DOWN
const int buttonPin3 = 3;           //ENTER
const int buttonPin4 = 2;           //EXIT

int mainpage = 1;   
int arduino1page = 0;   
int arduino2page = 0;
int arduino3page = 0;
int arduino4page = 0;

int x = 5; 
int volts; 

int Counter1 = 1;  

int Counter2 = 1; 

int Counter3 = 0;  

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
  Wire.begin();
  Serial.begin(115200);    
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  delay(500);            
  lcd.begin();            
  lcd.backlight();        
  lcd.clear();
  lcd.setCursor(7, 1);
  lcd.print("HELLO");     
  delay(500);
  lcd.clear();
  lcd.setCursor(7, 1);
  lcd.print("WELCOME");   
  delay(500);
  lcd.clear();
}

void MainPage()
{
  if (mainpage == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print("  CHOOSE YOUR BOARD ");
    lcd.setCursor(0, 1);
    lcd.print("                    ");
    lcd.setCursor(0, 2);
    lcd.print(" 1.ARD-1    3.ARD-3 ");
    lcd.setCursor(0, 3);
    lcd.print(" 2.ARD-2    4.ARD-4 ");
  }
}

void Arduino1Page()
{
  if (arduino1page == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print(" CHOOSE YOUR OPTION ");
    lcd.setCursor(0,1);
    lcd.print(" 1.MOTOR CONTROL    ");
    lcd.setCursor(0,2);
    lcd.print(" 2.LDR VALUE       ");
    lcd.setCursor(0,3);
    lcd.print(" 3.BACK             ");
  }
}

void Arduino2Page()
{
  if (arduino2page == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print(" CHOOSE YOUR OPTION ");
    lcd.setCursor(0,1);
    lcd.print(" 1.MOTOR CONTROL    ");
    lcd.setCursor(0,2);
    lcd.print(" 2.LDR VALUE       ");
    lcd.setCursor(0,3);
    lcd.print(" 3.BACK             ");
  }
}

void Arduino3Page()
{
  if (arduino3page == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print(" CHOOSE YOUR OPTION ");
    lcd.setCursor(0,1);
    lcd.print(" 1.MOTOR CONTROL    ");
    lcd.setCursor(0,2);
    lcd.print(" 2.LDR VALUE       ");
    lcd.setCursor(0,3);
    lcd.print(" 3.BACK             ");
  }
}


void Arduino4Page()
{
  if (arduino4page == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print(" CHOOSE YOUR OPTION ");
    lcd.setCursor(0,1);
    lcd.print(" 1.MOTOR CONTROL    ");
    lcd.setCursor(0,2);
    lcd.print(" 2.LDR VALUE       ");
    lcd.setCursor(0,3);
    lcd.print(" 3.BACK             ");
  }
}

void MainCounter()
{
  if (Counter1 == 1 && mainpage == 1)
  {
    lcd.setCursor(0, 2);
    lcd.print(">");                 // printing the cursor in the required spot
    lcd.setCursor(0, 3);
    lcd.print(" ");                 // printing a blank space to clear the particular spot
    lcd.setCursor(11, 2);
    lcd.print(" ");                 // printing a blank space to clear the particular spot
    lcd.setCursor(11, 3);
    lcd.print(" ");                 // printing a blank space to clear the particular spot
   
  }
  if (Counter1 == 2 && mainpage == 1)
  {
    lcd.setCursor(0, 2);
    lcd.print(" ");                 // printing a blank space to clear the particular spot
    lcd.setCursor(0, 3);
    lcd.print(">");                 // printing the cursor in the required spot
    lcd.setCursor(11, 2);
    lcd.print(" ");                 // printing a blank space to clear the particular spot
    lcd.setCursor(11, 3);
    lcd.print(" ");                 // printing a blank space to clear the particular spot
  
  }
  if (Counter1 == 3 && mainpage == 1)
  {
    lcd.setCursor(0, 2);
    lcd.print(" ");                 // printing a blank space to clear the particular spot
    lcd.setCursor(0, 3);
    lcd.print(" ");                 // printing a blank space to clear the particular spot
    lcd.setCursor(11, 2);
    lcd.print(">");                 // printing the cursor in the required spot
    lcd.setCursor(11, 3);
    lcd.print(" ");                 // printing a blank space to clear the particular spot

    
  }
  if (Counter1 == 4 && mainpage == 1)
  {
    lcd.setCursor(0, 2);
    lcd.print(" ");              
    lcd.setCursor(0, 3);
    lcd.print(" ");                 
    lcd.setCursor(11, 2);
    lcd.print(" ");                 
    lcd.setCursor(11, 3);
    lcd.print(">");   
  }
}


void SubCounter()
{
  if (Counter2 == 1 && mainpage == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print(">");   
    lcd.setCursor(0, 2);
    lcd.print(" ");                
    lcd.setCursor(0, 3);
    lcd.print(" ");   
    }
  if (Counter2 == 2 && mainpage == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print(" ");   
    lcd.setCursor(0, 2);
    lcd.print(">");                
    lcd.setCursor(0, 3);
    lcd.print(" ");   
    }

  if (Counter2 == 3 && mainpage == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print(" ");   
    lcd.setCursor(0, 2);
    lcd.print(" ");                
    lcd.setCursor(0, 3);
    lcd.print(">");   
    }
}

void ButtonState()
{
  buttonState1 = digitalRead(buttonPin1);   
  buttonState2 = digitalRead(buttonPin2);   
  buttonState3 = digitalRead(buttonPin3);   
  buttonState4 = digitalRead(buttonPin4);  

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

      if (mainpage == 0)          
      {
        if (Counter2 < 4)
        {
          Counter2++;
          delay(200);
        }
        else
        {
          Counter2 = 1;
        }
      }
      if (mainpage == 2)        
      {
        Speedinc();
      }
       if (mainpage == 3)        
      {
         DefaultSetup();
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
      if (mainpage == 0)         
      {
        if (Counter2 > 1)
        {
          Counter2--;
          delay(200);
        }
        else
        {
          Counter2 = 3;
        }
      }
      if (mainpage == 2)        
      {
        Speeddec();
      }
       if (mainpage == 3)        
      {
         DefaultSetup();
      }
    }
  }

  buttonState3 = digitalRead(buttonPin3);
  {
    if (buttonState3 == LOW)      
    {
      delay(200);
      if (mainpage == 1)          
      {
        PageSelection();
      }
      else if (mainpage == 0)     
      {
        OptionSelection();
      }
      else if (mainpage == 2)     
      {
        DefaultSetup();
      }
       else if (mainpage == 3)        
      {
         DefaultSetup();
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
    delay(1000);         
    lcd.clear();
    DefaultSetup();                   
  }
  lastButtonState1 = buttonState1;    
  lastButtonState2 = buttonState2;    
  lastButtonState3 = buttonState3;   
  lastButtonState4 = buttonState4;    
}

void DefaultSetup()
{
  MainPage();
  mainpage = 1;
  arduino1page = 0;
  arduino2page = 0;
  arduino3page = 0;
  arduino4page = 0;
  Counter1 = 1;
  Counter2 = 1;
  Counter3 = 0;
  x = 5;
  Wire.beginTransmission(1);
  Wire.write('L');
  Wire.write(0);
  Wire.endTransmission();
  Wire.beginTransmission(2);
  Wire.write('L');
  Wire.write(0);
  Wire.endTransmission();
  Wire.beginTransmission(3);
  Wire.write('L');
  Wire.write(0);
  Wire.endTransmission(); 
  Wire.beginTransmission(4);
  Wire.write('L');
  Wire.write(0);
  Wire.endTransmission();
}

void PageSelection()
{

  if (Counter1 == 1)    
  {
    mainpage = 0;
    arduino1page = 1;
    arduino2page = 0;
    arduino3page = 0;
    arduino4page = 0;
    DeterminePage();
  }
  if (Counter1 == 2)    
  {
    mainpage = 0;
    arduino1page = 0;
    arduino2page = 1;
    arduino3page = 0;
    arduino4page = 0;
    DeterminePage();
  }
  if (Counter1 == 3)   
  {
    mainpage = 0;
    arduino1page = 0;
    arduino2page = 0;
    arduino3page = 1;
    arduino4page = 0;
    DeterminePage();
  }
  if (Counter1 == 4)    
  {
    mainpage = 0;
    arduino1page = 0;
    arduino2page = 0;
    arduino3page = 0;
    arduino4page = 1;
    DeterminePage();
  }
}

void DeterminePage()
{
  if (arduino1page == 1 && mainpage == 0)           
  {
    Arduino1Page();
  }
  else if (arduino2page == 1 && mainpage == 0)    
  {
    Arduino2Page();
     }
  else if (arduino3page == 1 && mainpage == 0)    
  {
    Arduino3Page();
      }
  else if (arduino4page == 1 && mainpage == 0)    
  {
    Arduino4Page();
     }
  else
  {
    DefaultSetup();                            
  }
}

void OptionSelection()
{
  if (Counter2 == 1)   
  {
    mainpage = 2;
    Speedinc();
  }
  if (Counter2 == 2)    
  {
    mainpage = 3;
    LdrPage();
   
  }
  if (Counter2 == 3)
  {
    DefaultSetup();     
  }
}


void Speedinc()
{ lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("   CHOOSE SPEED     ");
  lcd.setCursor(3, 1);
  lcd.print(" FROM 5 TO 255");
  lcd.setCursor(8, 3);
  lcd.print(x);
  if (Counter3 < 25)      
  {
    delay(200);
    x = x + 10;
    Speed();
    Counter3++;
  }
}


void Speeddec()
{
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("   CHOOSE SPEED     ");
  lcd.setCursor(3, 1);
  lcd.print(" FROM 5 TO 255");
  lcd.setCursor(8, 3);
  lcd.print(x);
  
  if (Counter3 > 0)
  {
    delay(200);
    x = x - 10;
    Speed();
    Counter3--;
  }
}

void Speed()
{

  if (arduino1page == 1)         
  {
   Wire.beginTransmission(1);
   Wire.write('H');
   Wire.write(x);
   Wire.endTransmission();    
   delay(500);    
  }
  if (arduino2page == 1)         
  {
  Wire.beginTransmission(2);
  Wire.write('H');
  Wire.write(x);
  Wire.endTransmission();  
  delay(500);    
  }
  if (arduino3page == 1)         
  {  
  Wire.beginTransmission(3);
  Wire.write('H');
  Wire.write(x); 
  Wire.endTransmission();  
  delay(500);    
  }
  if (arduino4page == 1)         
  {
  Wire.beginTransmission(4);
  Wire.write('H');
  Wire.write(x);
  Wire.endTransmission();  
  delay(500);   
  }
}


void LdrPage()
{
  if (arduino1page == 1 && mainpage == 3)         
  {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" THE LDR VALUE FROM ");
  lcd.setCursor(0, 1);
  lcd.print(" ARDUINO BOARD NO.1 ");
  lcd.setCursor(0, 2);
  lcd.print("         is     ");  
  lcd.setCursor(8, 3);
  lcd.print(volts);
  LdrRead();  
  }
  if (arduino2page == 1 && mainpage == 3)         
  {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" THE LDR VALUE FROM ");
  lcd.setCursor(0, 1);
  lcd.print(" ARDUINO BOARD NO.2 ");
  lcd.setCursor(0, 2);
  lcd.print("         is     ");  
  lcd.setCursor(8, 3);
  lcd.print(volts);
  LdrRead();
  }
  if (arduino3page == 1 && mainpage == 3)         
  { 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" THE LDR VALUE FROM ");
  lcd.setCursor(0, 1);
  lcd.print(" ARDUINO BOARD NO.3 ");
  lcd.setCursor(0, 2);
  lcd.print("         is     ");  
  lcd.setCursor(8, 3);
  lcd.print(volts);
  LdrRead();  
  }
  if (arduino4page == 1 && mainpage == 3)         
  {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" THE LDR VALUE FROM ");
  lcd.setCursor(0, 1);
  lcd.print(" ARDUINO BOARD NO.4 ");
  lcd.setCursor(0, 2);
  lcd.print("         is     ");  
  lcd.setCursor(8, 3);
  lcd.print(volts);
  LdrRead();
  }
}

void LdrRead()
{
   if (arduino1page == 1)        
  { 
    Wire.beginTransmission(1);
    int available = Wire.requestFrom(1,2);
    if(available == 2)
    {
     volts =(Wire.read()  << 8)| (Wire.read());
     Serial.println(volts);
     }
       Wire.endTransmission();
       delay(500);
      }
     if (arduino2page == 1)       
  {
     Wire.beginTransmission(2);
    int available = Wire.requestFrom(2,2);
    if(available == 2)
    {
     volts =(Wire.read()  << 8)| (Wire.read());
     Serial.println(volts);
     }
       Wire.endTransmission();
       delay(500);
  }
  
  if (arduino3page == 1)         
  {
    Wire.beginTransmission(3);
    int available = Wire.requestFrom(3,2);
    if(available == 2)
    {
     volts =(Wire.read()  << 8)| (Wire.read());
     Serial.println(volts);
     }
       Wire.endTransmission();
       delay(500);
  }
  
  if (arduino4page == 1)          
  {  
     Wire.beginTransmission(4);
    int available = Wire.requestFrom(4,2);
    if(available == 2)
    {
     volts =(Wire.read()  << 8)| (Wire.read());
     Serial.println(volts);
     }
       Wire.endTransmission();
       delay(500);
  }
}

void loop()
{
  MainPage();
  ButtonState();
  MainCounter();
  SubCounter();
  LdrRead();
}



