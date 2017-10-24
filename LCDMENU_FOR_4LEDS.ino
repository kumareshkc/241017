/*
 
Hi,

In this Arduino code we have created a simple LCD Menu for controlling 4 leds 

here we are using the i2c module for interfacing with the lcd 

the lcd we use here is a 20 * 4 LCD

the library used is the arduino lcd i2c library 

the buttons are used for selecting the mode and options 

the leds are used as output 

the LCD is used as a human interface module here to get the desired input 

the red green yellow and blue leds are used here 

the brightness, on and off state of the leds can be controlled by using this code 

NOTE: since we are going to control the brightness of the leds make sure you connect them in any one of the pwm ports in the Arduino 

Hope you Enjoy this code 

Regards,
Kumaresh.


CONNECTIONS :

THE ARDUINO USED HERE IS ARDUINO UNO 

BUTTON 1 IS UP AND IS CONNECTED TO PIN 2

BUTTON 2 IS DOWN AND IS CONNECTED TO PIN 4

BUTTON 3 IS ENTER AND IS CONNECTED TO PIN 5

BUTTON 4 IS EXIT AND IS CONNECTED TO PIN 8

BLUE LED IS CONNECTED TO PIN 11

YELLOW LED IS CONNECTED TO PIN 10

GREEN LED IS CONNECTED TO PIN 9

RED LED IS CONNECTED TO PIN 6

CONNECT THE LCD WITH THE I2C MODULE 

THE I2C MODULE IS USED TO REDUCE THE COMPLEXITY OF THE CONNECTIONS AND SIMPLIFY THE CONNECTION 

THE I2C HAS 2 INPUT SDA AND SCL 

SDA alias SERIAL DATA LINE IS CONNECTED TO THE A4 PIN 

SCL aliaS SERIAL CLOCK IS CONNECTED TO A5 PIN 

THE REST OF THE CONNECTIONS ARE THE SUPPLY AND GROUND TO THE COMPONENTS PRESENT 

*/




#include <LiquidCrystal_I2C.h>      //the lcd i2c library is called 
LiquidCrystal_I2C lcd(0x3F, 20, 4); //0X3F is the address of the my i2c and the lcd is 20*4 

// initialise the buttons

const int buttonPin1 = 2;           //UP 
const int buttonPin2 = 4;           //DOWN
const int buttonPin3 = 5;           //ENTER
const int buttonPin4 = 8;           //EXIT

//initialise the outputs

const int enable1 = 11;    //BLUE LED
const int enable2 = 10;    //YELLOW LED 
const int enable3 = 9;     //GREEN LED 
const int enable4 = 6;     //RED LED 

//initialise the pages

int mainpage = 1;    // INITIALISE THE MAIN PAGE AS 1 AND REST OF THEM AS 0 
int bluepage = 0;    // HERE EACH AND EVERY LED HAS ITS OWN DEDICATED PAGE 
int yellowpage = 0;
int greenpage = 0;
int redpage = 0;

int x = 5;   // INITIALISE X AS 5 TO GIVE A RANGE OF 5 TO 255(0 TO 255)

// initialise the main counter

int Counter1 = 1;   //(the button press counter in the mainpage )

// initialise the sub counter

int Counter2 = 1;  //(the couinter used in the rest of the led pages )

// initialise the brightness counter

int Counter3 = 0;  //(counter to determine the required brightness level of the led)

// initialise the status for all the buttons

int buttonState1 = 0;         // current state of the button 1
int lastButtonState1 = 0;     // previous state of the button1

int buttonState2 = 0;         // current state of the button2
int lastButtonState2 = 0;     // previous state of the button2

int buttonState3 = 0;         // current state of the button3
int lastButtonState3 = 0;     // previous state of the button3

int buttonState4 = 0;         // current state of the button4
int lastButtonState4 = 0;     // previous state of the button4

void setup()
{
  Serial.begin(115200);   // Initialize virtual COM port

  // initialise the input pins

  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);

  //initialise the output pins

  pinMode(enable1, OUTPUT);
  pinMode(enable2, OUTPUT);
  pinMode(enable3, OUTPUT);
  pinMode(enable4, OUTPUT);

  // initially all the leds are off

  digitalWrite(enable1 , LOW);
  digitalWrite(enable2 , LOW);
  digitalWrite(enable3 , LOW);
  digitalWrite(enable4 , LOW);

  // initialise the lcd

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
  lcd.clear();


}
/////////////////////initialise the main page////////////////////////////////////////////////

// print all the contents which are required in the main page 

void MainPage()
{

  if (mainpage == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print("CHOOSE YOUR COLOUR");
    lcd.setCursor(0, 2);
    lcd.print(" 1.BLUE     3.GREEN ");
    lcd.setCursor(0, 3);
    lcd.print(" 2.YELLOW   4.RED  ");
  }
}
////////////////////////initialise the blue page /////////////////////////////////////////////

// print all the contents which are required in the blue led page 

void BluePage()
{
  if (bluepage == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print("CHOOSE YOUR OPTION");
    lcd.setCursor(0, 2);
    lcd.print(" 1.BRIGHTNESS 3.OFF ");
    lcd.setCursor(0, 3);
    lcd.print(" 2.ON    4.MAINPAGE ");
  }
}
///////////////////////initialise the yellow page //////////////////////////////////////////////

// print all the contents which are required in the yellow led page 


void YellowPage()
{
  if (yellowpage == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print("CHOOSE YOUR OPTION");
    lcd.setCursor(0, 2);
    lcd.print(" 1.BRIGHTNESS 3.OFF ");
    lcd.setCursor(0, 3);
    lcd.print(" 2.ON    4.MAINPAGE ");
  }
}
////////////////////////initialise the green page////////////////////////////////////////////////

// print all the contents which are required in the green led page 


void GreenPage()
{
  if (greenpage == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print("CHOOSE YOUR OPTION");
    lcd.setCursor(0, 2);
    lcd.print(" 1.BRIGHTNESS 3.OFF ");
    lcd.setCursor(0, 3);
    lcd.print(" 2.ON    4.MAINPAGE ");
  }
}
////////////////////initialise the red page ///////////////////////////////////////////////////////

// print all the contents which are required in the red led page 

void RedPage()
{
  if (redpage == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print("CHOOSE YOUR OPTION");
    lcd.setCursor(0, 2);
    lcd.print(" 1.BRIGHTNESS 3.OFF ");
    lcd.setCursor(0, 3);
    lcd.print(" 2.ON    4.MAINPAGE ");
  }
}
//////////////////////initialise the main counter ///////////////////////////////////////////////////////

// used to print the cursor in the required spot in the main page 

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
    digitalWrite(enable1 , HIGH);   // turn on the blue led to show it is selected and turn off the rest of the leds  
    digitalWrite(enable2 , LOW);
    digitalWrite(enable3 , LOW);
    digitalWrite(enable4 , LOW);
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
    digitalWrite(enable1 , LOW);
    digitalWrite(enable2 , HIGH);   // turn on the yellow led to show it is selected and turn off the rest of the leds  
    digitalWrite(enable3 , LOW);
    digitalWrite(enable4 , LOW);
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
    
    digitalWrite(enable1 , LOW);
    digitalWrite(enable2 , LOW);
    digitalWrite(enable3 , HIGH);   // turn on the green led to show it is selected and turn off the rest of the leds 
    digitalWrite(enable4 , LOW);
  }
  if (Counter1 == 4 && mainpage == 1)
  {
    lcd.setCursor(0, 2);
    lcd.print(" ");                 // printing a blank space to clear the particular spot
    lcd.setCursor(0, 3);
    lcd.print(" ");                 // printing a blank space to clear the particular spot
    lcd.setCursor(11, 2);
    lcd.print(" ");                 // printing a blank space to clear the particular spot
    lcd.setCursor(11, 3);
    lcd.print(">");                 // printing the cursor in the required spot  
    digitalWrite(enable1 , LOW);
    digitalWrite(enable2 , LOW);
    digitalWrite(enable3 , LOW);
    digitalWrite(enable4 , HIGH);   // turn on the red led to show it is selected and turn off the rest of the leds 
  }
}
///////////////////////initialise the sub counter //////////////////////////////////////////

// used to print the cursor in the required spot in the led pages 

void SubCounter()
{
  if (Counter2 == 1 && mainpage == 0)
  {
    lcd.setCursor(0, 2);
    lcd.print(">");                 // printing the cursor in the required spot 
    lcd.setCursor(0, 3);
    lcd.print(" ");                 // printing a blank space to clear the particular spot
    lcd.setCursor(13, 2);
    lcd.print(" ");                 // printing a blank space to clear the particular spot
    lcd.setCursor(8, 3);
    lcd.print(" ");                 // printing a blank space to clear the particular spot
    
  }
  if (Counter2 == 2 && mainpage == 0)
  {
    lcd.setCursor(0, 2);
    lcd.print(" ");                 // printing a blank space to clear the particular spot
    lcd.setCursor(0, 3);
    lcd.print(">");                 // printing the cursor in the required spot  
    lcd.setCursor(13, 2);
    lcd.print(" ");                 // printing a blank space to clear the particular spot
    lcd.setCursor(8, 3);
    lcd.print(" ");                 // printing a blank space to clear the particular spot
    
  }
  if (Counter2 == 3 && mainpage == 0)
  {
    lcd.setCursor(0, 2);
    lcd.print(" ");                 // printing a blank space to clear the particular spot
    lcd.setCursor(0, 3);
    lcd.print(" ");                 // printing a blank space to clear the particular spot
    lcd.setCursor(13, 2);
    lcd.print(">");                 // printing the cursor in the required spot
    lcd.setCursor(8, 3);
    lcd.print(" ");                 // printing a blank space to clear the particular spot  
  }

  if (Counter2 == 4 && mainpage == 0)
  {
    lcd.setCursor(0, 2);
    lcd.print(" ");                 // printing a blank space to clear the particular spot
    lcd.setCursor(0, 3);
    lcd.print(" ");                 // printing a blank space to clear the particular spot
    lcd.setCursor(13, 2);
    lcd.print(" ");                 // printing a blank space to clear the particular spot
    lcd.setCursor(8, 3);
    lcd.print(">");                 // printing the cursor in the required spot  
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
    if (buttonState1 == LOW)        // if button1 is pressed execute the following action 
    {
      if (mainpage == 1)            // conditon for incrementing in main page
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

      if (mainpage == 0)           // conditon for incrementing in led pages
      {
        if (Counter2 < 4)
        {
          Counter2++;
          Serial.println(Counter2);
          delay(200);
        }
        else
        {
          Counter2 = 1;
        }
      }
      if (mainpage == 2)          // conditon for incrementing brightness
      {
        Brightnessinc();
      }
    }
  }

  if (buttonState2 != lastButtonState2)
  {
    if (buttonState2 == LOW)      // if button2 is pressed execute the following action 
    {
      if (mainpage == 1)          // conditon for decrementing in main page
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
      if (mainpage == 0)          // conditon for decrementing in led pages
      {
        if (Counter2 > 1)
        {
          Counter2--;
          Serial.println(Counter2);
          delay(200);
        }
        else
        {
          Counter2 = 4;
        }
      }
      if (mainpage == 2)           // conditon for decrementing brightness
      {
        Brightnessdec();

      }
    }

  }

  buttonState3 = digitalRead(buttonPin3);
  {
    if (buttonState3 == LOW)      // if button3 is pressed execute the following action 
    {
      delay(200);
      if (mainpage == 1)          //if the cursor is in main page enter into the page selection
      {
        PageSelection();
      }
      else if (mainpage == 0)     //if the cursor is in led pages enter into the option selection
      {
        OptionSelection();
      }

    }
  }

  if (buttonState4 == LOW)             // if button4 is pressed execute the following action 
  {
    lcd.clear();
    lcd.setCursor(0, 1); 
    lcd.print("                ");    //Print blanks to clear the row
    lcd.setCursor(6, 1);  
    lcd.print("THANK YOU");           //Print the exit message

    // we are simply turning on and off the leds in a small interval to show that the current program has been finished and we are exiting out from it 
    
    digitalWrite(enable1 , HIGH);
    digitalWrite(enable2 , HIGH);
    digitalWrite(enable3 , HIGH);
    digitalWrite(enable4 , HIGH);
    delay(700);
    digitalWrite(enable1 , LOW);
    digitalWrite(enable2 , LOW);
    digitalWrite(enable3 , LOW);
    digitalWrite(enable4 , LOW);
    delay(100);
    digitalWrite(enable1 , HIGH);
    digitalWrite(enable2 , HIGH);
    digitalWrite(enable3 , HIGH);
    digitalWrite(enable4 , HIGH);
    delay(100);
    digitalWrite(enable1 , LOW);
    digitalWrite(enable2 , LOW);
    digitalWrite(enable3 , LOW);
    digitalWrite(enable4 , LOW);
    delay(100);
    digitalWrite(enable1 , HIGH);
    digitalWrite(enable2 , HIGH);
    digitalWrite(enable3 , HIGH);
    digitalWrite(enable4 , HIGH);
    delay(100);
    digitalWrite(enable1 , LOW);
    digitalWrite(enable2 , LOW);
    digitalWrite(enable3 , LOW);
    digitalWrite(enable4 , LOW);
    delay(100);
    digitalWrite(enable1 , HIGH);
    digitalWrite(enable2 , HIGH);
    digitalWrite(enable3 , HIGH);
    digitalWrite(enable4 , HIGH);
    delay(100);
    digitalWrite(enable1 , LOW);
    digitalWrite(enable2 , LOW);
    digitalWrite(enable3 , LOW);
    digitalWrite(enable4 , LOW);
    delay(500);
    lcd.clear();
    DefaultSetup();                   // go back to the deafult page (main page or the initial starting condition)
  }
  lastButtonState1 = buttonState1;    //define that the laststate and present state are equal for button 1
  lastButtonState2 = buttonState2;    //define that the laststate and present state are equal for button 2
  lastButtonState3 = buttonState3;    //define that the laststate and present state are equal for button 3
  lastButtonState4 = buttonState4;    //define that the laststate and present state are equal for button 4
}
//////////////initialise the default settings ///////////////////////////////////////

// initalise to go back to the previous or starting state 

void DefaultSetup()
{
  MainPage();
  mainpage = 1;
  bluepage = 0;
  yellowpage = 0;
  greenpage = 0;
  redpage = 0;
  Counter1 = 1;
  Counter2 = 1;
  Counter3 = 0;
  x=5;
}
//////////////////initialise the page settings //////////////////////////////////

// used to assign which page is to be visited 

void PageSelection()
{

  if (Counter1 == 1)    // assigning the blue led page 
  {
    mainpage = 0;
    bluepage = 1;
    yellowpage = 0;
    greenpage = 0;
    redpage = 0;
    DeterminePage();
  }
  if (Counter1 == 2)    // assigning the yellow led page 
  {
    mainpage = 0;
    bluepage = 0;
    yellowpage = 1;
    greenpage = 0;
    redpage = 0;
    DeterminePage();
  }
  if (Counter1 == 3)    // assigning the green led page 
  {
    mainpage = 0;
    bluepage = 0;
    yellowpage = 0;
    greenpage = 1;
    redpage = 0;
    DeterminePage();
  }
  if (Counter1 == 4)    // assigning the red led page 
  {
    mainpage = 0;
    bluepage = 0;
    yellowpage = 0;
    greenpage = 0;
    redpage = 1;
    DeterminePage();
  }
}

/////////////////initialise which page is to be determined ///////////////////////////////////

// using the following condition so that the arduino goes to the required page based on the assignments made in the pageselection() function 
 
void DeterminePage()
{
  if (bluepage == 1 && mainpage == 0)           // direct the arduino to go to the blue page
  {
    BluePage();
    analogWrite(enable1 , 25);                  // writing a small analog value to indicate which page we are currently present 
  }
  else if (yellowpage == 1 && mainpage == 0)    // direct the arduino to go to the yellow page
  {
    YellowPage();
    analogWrite(enable2 , 25);                  // writing a small analog value to indicate which page we are currently present 
  }
  else if (greenpage == 1 && mainpage == 0)     // direct the arduino to go to the green page
  {
    GreenPage();
    analogWrite(enable3 , 25);                  // writing a small analog value to indicate which page we are currently present 
  }
  else if (redpage == 1 && mainpage == 0)       // direct the arduino to go to the red page
  {
    RedPage();
    analogWrite(enable4 , 25);                  // writing a small analog value to indicate which page we are currently present 
  }
  else
  {
    DefaultSetup();                             //if the above conditions doesnt meet go back to the default condition 
  }
}
//////////////////////choosing the preferred option //////////////////////////////

void OptionSelection()
{
  if (Counter2 == 1)    // select the brightness condition
  {
    mainpage = 2;
    Brightnessinc();
  }
  if (Counter2 == 2)    // select the on condition 
  {
    On();
  }
  if (Counter2 == 3)    //select the off condition
  {
    Off();
  }
  if (Counter2 == 4)
  {
    DefaultSetup();     //go back to the mainpage
  }
}

//////////////////condition for brightness increment  //////////////////////////////////

// condition to increment the brightness value 

void Brightnessinc()
{ lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("CHOOSE BRIGHTNESS");
  lcd.setCursor(3, 1);
  lcd.print("FROM 5 TO 255");
  lcd.setCursor(8, 3);
  lcd.print(x);
  if (Counter3 < 25)      // the increment value is set to perform 25 counts 
  {
    delay(200);
    x = x + 10;
    Brightness();
    Counter3++;
  }
}
//////////////////condition for brightness decrement  //////////////////////////////////

// condition to decrement the brightness value 

void Brightnessdec()
{
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("CHOOSE BRIGHTNESS");
  lcd.setCursor(3, 1);
  lcd.print("FROM 5 TO 255");
  lcd.setCursor(8, 3);
  lcd.print(x);
  if (Counter3 > 0)
  {
    delay(200);
    x = x - 10;
    Brightness();
    Counter3--;
  }
}
///////////////////// condition for brightness //////////////////////////////////////////

// select the defined brightness value and implement in the proper led which is required 

void Brightness()
{

  if (bluepage == 1)          // implement the brightness condition on the blue led 
  {
    analogWrite(enable1 , x);
    digitalWrite(enable2 , LOW);
    digitalWrite(enable3 , LOW);
    digitalWrite(enable4 , LOW);
  }
  if (yellowpage == 1)          // implement the brightness condition on the yellow led 
  {
    digitalWrite(enable1 , LOW);
    analogWrite(enable2 , x);
    digitalWrite(enable3 , LOW);
    digitalWrite(enable4 , LOW);
  }
  if (greenpage == 1)         // implement the brightness condition on the green led 
  {
    digitalWrite(enable1 , LOW);
    digitalWrite(enable2 , LOW);
    analogWrite(enable3 , x);
    digitalWrite(enable4 , LOW);
  }
  if (redpage == 1)         // implement the brightness condition on the red led 
  {
    digitalWrite(enable1 , LOW);
    digitalWrite(enable2 , LOW);
    digitalWrite(enable3 , LOW);
    analogWrite(enable4 , x);
  }
}
////////////////////////condition for on /////////////////////////////////

void On()
{
  if (bluepage == 1)          // turn on the blue led  
  {
    digitalWrite(enable1 , HIGH);
    digitalWrite(enable2 , LOW);
    digitalWrite(enable3 , LOW);
    digitalWrite(enable4 , LOW);
  }
  if (yellowpage == 1)        // turn on the yellow led  
  {
    digitalWrite(enable1 , LOW);
    digitalWrite(enable2 , HIGH);
    digitalWrite(enable3 , LOW);
    digitalWrite(enable4 , LOW);
  }
  if (greenpage == 1)         // turn on the green led  
  {
    digitalWrite(enable1 , LOW);
    digitalWrite(enable2 , LOW);
    digitalWrite(enable3 , HIGH);
    digitalWrite(enable4 , LOW);
  }
  if (redpage == 1)           // turn on the red led  
  {
    digitalWrite(enable1 , LOW);
    digitalWrite(enable2 , LOW);
    digitalWrite(enable3 , LOW);
    digitalWrite(enable4 , HIGH);
  }
}
/////////////////condition for off ///////////////////////////////////

void Off()
{
  if (bluepage == 1)        // turn off the leds 
  {
    digitalWrite(enable1 , LOW);
    digitalWrite(enable2 , LOW);
    digitalWrite(enable3 , LOW);
    digitalWrite(enable4 , LOW);
  }
  if (yellowpage == 1)      // turn off the leds
  {
    digitalWrite(enable1 , LOW);
    digitalWrite(enable2 , LOW);
    digitalWrite(enable3 , LOW);
    digitalWrite(enable4 , LOW);
  }
  if (greenpage == 1)       // turn off the leds
  {
    digitalWrite(enable1 , LOW);
    digitalWrite(enable2 , LOW);
    digitalWrite(enable3 , LOW);
    digitalWrite(enable4 , LOW);
  }
  if (redpage == 1)         // turn off the leds
  {
    digitalWrite(enable1 , LOW);
    digitalWrite(enable2 , LOW);
    digitalWrite(enable3 , LOW);
    digitalWrite(enable4 , LOW);
  }
}
//////////////////loop cconditions //////////////////////////////////

// initialise the loop conditions 

void loop()
{
  MainPage();
  ButtonState();
  MainCounter();
  SubCounter();
}
//////////////////////////////////////////////////////////////////////

