
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 20 , 4);
const int buttonPin1 = 2;
const int buttonPin2 = 4;
const int buttonPin3 = 7;
const int buttonPin4 = 8;
const int motorPin1  = 5;  
const int motorPin2  = 6;  
const int enable1 = 3;
const int enable2 = 9;
const int ledPin = 13;
int buttonPushCounter2 = 0;   // counter for the number of button presses
int buttonState1 = 0;         // current state of the button
int lastButtonState1 = 0;     // previous state of the button
int buttonState2 = 0;         // current state of the button
int lastButtonState2 = 0;    // previous state of the button
int buttonState3 = 0;         // current state of the button
int lastButtonState3 = 0;     // previous state of the button
int buttonState4 = 0;         // current state of the button
int lastButtonState4 = 0;     // previous state of the button
int x = 5;
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are unsigned long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() 
{
  Serial.begin(9600);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(enable1, OUTPUT);
  pinMode(enable2, OUTPUT);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  lcd.begin();// Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print(" HELLO ! WELCOME ");  //Print Message on First Row
  // set initial LED state
  digitalWrite(ledPin, ledState);
}

void loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin1);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState1) {
       
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState1) {
      
      buttonState1 = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState1 == HIGH) {
        
        ledState = !ledState;
      }
    }
  }

  // set the LED:
  digitalWrite(ledPin, ledState);

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState1 = reading;


if(ledState == 0)
{ 
       lcd.setCursor(0, 1); //Set cursor to first column of second row
       lcd.print("                "); //Print blanks to clear the row
       lcd.setCursor(0, 1);  //Set Cursor again to first column of second row
       lcd.print("FAN IS SELECTED ");  //Print your units.
       
 buttonState2 = digitalRead(buttonPin2);
  if (buttonState2 != lastButtonState2)
  {
    if (buttonState2 == LOW)
    {
      if (buttonPushCounter2 < 10)
      {
        x = x + 25;

        analogWrite(enable1, x);
        digitalWrite(motorPin1, HIGH);
        digitalWrite(motorPin2, LOW);
        buttonPushCounter2++;
        Serial.print("number of button pushes:  ");
        Serial.println(buttonPushCounter2);
      }
    }
  }
  buttonState3 = digitalRead(buttonPin3);
  if (buttonState3 != lastButtonState3)
  {
    if (buttonState3 == LOW)
    {
      if (buttonPushCounter2 > 0)
      {
        x = x - 25;
        analogWrite(enable1 , x);
        digitalWrite(motorPin1, HIGH);
        digitalWrite(motorPin2, LOW);
        buttonPushCounter2--;
        Serial.print("number of button pushes:  ");
        Serial.println(buttonPushCounter2);
      }
    }

    else if (buttonPushCounter2 == 0)
    {
      analogWrite(enable1 , 0);
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  buttonState4 = digitalRead(buttonPin4);
  {
    if (buttonState4 == LOW)
    {
      analogWrite(enable1 , 0);
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      Serial.println("off");
      lcd.setCursor(0, 1); //Set cursor to first column of second row
      lcd.print("                "); //Print blanks to clear the row
      lcd.setCursor(0, 1);  //Set Cursor again to first column of second row
      lcd.print("FAN IS OFF NOW ");  //Print your units.
    }
  }
}



if(ledState == 1 )
{ 
         lcd.setCursor(0, 1); //Set cursor to first column of second row
         lcd.print("                "); //Print blanks to clear the row
         lcd.setCursor(0, 1);  //Set Cursor again to first column of second row
         lcd.print("LED IS SELECTED ");  //Print your units.
  
 buttonState2 = digitalRead(buttonPin2);
  if (buttonState2 != lastButtonState2)
  {
    if (buttonState2 == LOW)
    {
      if (buttonPushCounter2 < 10)
      {
        x = x + 25;

        analogWrite(enable2, x);
        buttonPushCounter2++;
        Serial.print("number of button pushes:  ");
        Serial.println(buttonPushCounter2);
      }
    }
  }
  buttonState3 = digitalRead(buttonPin3);
  if (buttonState3 != lastButtonState3)
  {
    if (buttonState3 == LOW)
    {
      if (buttonPushCounter2 > 0)
      {
        x = x - 25;
        analogWrite(enable2 , x);
        buttonPushCounter2--;
        Serial.print("number of button pushes:  ");
        Serial.println(buttonPushCounter2);
      }
    }

    else if (buttonPushCounter2 == 0)
    {
      analogWrite(enable2 , 0);
       }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  buttonState4 = digitalRead(buttonPin4);
  {
    if (buttonState4 == LOW)
    {
      analogWrite(enable2 , 0);
      Serial.println("off");
      lcd.setCursor(0, 1); //Set cursor to first column of second row
      lcd.print("                "); //Print blanks to clear the row
      lcd.setCursor(0, 1);  //Set Cursor again to first column of second row
      lcd.print("LED IS NOW OFF ");  //Print your units.
    }
  }
}

//  lastButtonState1 = buttonState1;
  lastButtonState2 = buttonState2;
  lastButtonState3 = buttonState3;
  lastButtonState4 = buttonState4;
}

