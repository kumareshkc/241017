#include <TimeLib.h>
#include <DS1307RTC.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x38, 20, 4);
tmElements_t tm;
#define buz 13
int Hour;
int Min;
int Sec;
int Day;
int Month;
int Year;
int H;
int M;
int Al = 1;

// initialise the buttons

const int buttonPin1 = 22;           //UP
const int buttonPin2 = 24;           //DOWN
const int buttonPin3 = 26;           //ENTER
const int buttonPin4 = 28;           //EXIT

//initialise the pages

int mainpage = 0;
int subpage = 0;
int hourpage = 0;
int minutepage = 0;
int onoffpage = 0;
int statspage = 0;
int alarmpage = 0;

// initialise the main counter

int Counter1 = 0;
int Counter2 = 1;
int Counter3 = 0;
int Counter4 = 0;
int Counter5 = 0;

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
  Wire.begin();
  Serial.begin(115200);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buz, OUTPUT);

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
  lcd.setCursor(3, 1);
  lcd.print(" ARDUINO ALARM ");
  delay(500);
  lcd.clear();
}
void MainPage()
{
  if (mainpage == 0)
  {
    GetValue();
  }
  if (mainpage == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print("CHOOSE YOUR OPTION");
    lcd.setCursor(0, 1);
    lcd.print("                  ");
    lcd.setCursor(0, 2);
    lcd.print(" 1.STATUS   3.HOME ");
    lcd.setCursor(0, 3);
    lcd.print(" 2.SET ALARM 4.EXIT");
  }
  if (mainpage == 2)
  {
    SubPage();
  }
  if (mainpage == 3)
  {
    HourPage();
  }
  if (mainpage == 4)
  {
    MinutePage();
  }
  if (mainpage == 5)
  {
    OnoffPage();
  }
  if (mainpage == 6)
  {
    StatusPage();
  }
  if (mainpage == 7)
  {
    chkalarm();
  }
}
void SubPage()
{
  subpage = 1;
  hourpage = 0;
  minutepage = 0;
  onoffpage = 0;
  statspage = 0;
  alarmpage = 0;

  if (subpage == 1)
  {
    lcd.setCursor(0, 0);
    lcd.print(" CHOOSE YOUR OPTION ");
    lcd.setCursor(0, 1);
    lcd.print("                    ");
    lcd.setCursor(0, 2);
    lcd.print(" 1.HOUR   3.ON/OFF ");
    lcd.setCursor(0, 3);
    lcd.print(" 2.MINUTES  4.MAIN ");
  }
}
void HourPage()
{
  subpage = 0;
  hourpage = 1;
  minutepage = 0;
  onoffpage = 0;
  statspage = 0;
  alarmpage = 0;

  if (hourpage == 1)
  {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("CHOOSE HOUR");
    lcd.setCursor(3, 1);
    lcd.print("FROM 0 TO 23");
    lcd.setCursor(0, 2);
    lcd.print("                  ");
    lcd.setCursor(8, 3);
    lcd.print(H);
  }
}
void MinutePage()
{
  subpage = 0;
  hourpage = 0;
  minutepage = 1;
  onoffpage = 0;
  statspage = 0;
  alarmpage = 0;

  if (minutepage == 1)
  {
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("CHOOSE MINUTE");
    lcd.setCursor(3, 1);
    lcd.print("FROM 0 TO 59");
    lcd.setCursor(0, 2);
    lcd.print("                  ");
    lcd.setCursor(8, 3);
    lcd.print(M);
  }
}
void OnoffPage()
{
  subpage = 0;
  hourpage = 0;
  minutepage = 0;
  onoffpage = 1;
  statspage = 0;
  alarmpage = 0;

  if (onoffpage == 1)
  {
    if(Counter5 == 0)
    {
      Al=1;
      }
    if(Counter5 == 1)
    {
      Al=0;
    }
    if (Al == 0)
    {
      lcd.setCursor(0, 0);
      lcd.print("CHOOSE YOUR OPTION");
      lcd.setCursor(0, 1);
      lcd.print("CURRENTLY ALARM OFF");
      lcd.setCursor(0, 2);
      lcd.print(" 1.ALARM ON        ");
      lcd.setCursor(0, 3);
      lcd.print(" 2.ALARM OFF       ");
    }
    if (Al == 1)
    {
      lcd.setCursor(0, 0);
      lcd.print("CHOOSE YOUR OPTION");
      lcd.setCursor(0, 1);
      lcd.print("CURRENTLY ALARM ON ");
      lcd.setCursor(0, 2);
      lcd.print(" 1.ALARM ON        ");
      lcd.setCursor(0, 3);
      lcd.print(" 2.ALARM OFF       ");
    }
  }
}
void StatusPage()
{
  subpage = 0;
  hourpage = 0;
  minutepage = 0;
  onoffpage = 0;
  statspage = 1;
  alarmpage = 0;

  if (statspage == 1)
  {
    if (Al == 1)
    {
      delay(500);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" THE ALARM IS ON  ");
      lcd.setCursor(0, 1);
      lcd.print("                  ");
      lcd.setCursor(0, 2);
      lcd.print("THE ALARM IS SET AT");
      lcd.setCursor(8, 3);
      print2digits6();
      lcd.setCursor(10, 3);
      lcd.print(":");
      lcd.setCursor(11, 3);
      print2digits7();
    }
    if (Al == 0)
    {
      delay(500);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("                  ");
      lcd.setCursor(0, 1);
      lcd.print("                  ");
      lcd.setCursor(0, 2);
      lcd.print("  THE ALARM IS OFF ");      
      lcd.setCursor(0, 3);
      lcd.print("                  ");
    }
  }
}
void AlarmPage()
{
        //Buzzer();
       // Buzzer();
       // lcd.clear();
       lcd.setCursor(0,0);
        lcd.print("Alarm Ringing");
        //lcd.setCursor(0, 1);
        //lcd.print("Ringing");
        Buzzer();
        //Buzzer();
      }

void MainCounter()
{
  if (Counter1 == 1 && mainpage == 1)
  {
    lcd.setCursor(0, 2);
    lcd.print(">");
    lcd.setCursor(0, 3);
    lcd.print(" ");
    lcd.setCursor(11, 2);
    lcd.print(" ");
    lcd.setCursor(12, 3);
    lcd.print(" ");
  }
  if (Counter1 == 2 && mainpage == 1)
  {
    lcd.setCursor(0, 2);
    lcd.print(" ");
    lcd.setCursor(0, 3);
    lcd.print(">");
    lcd.setCursor(11, 2);
    lcd.print(" ");
    lcd.setCursor(12, 3);
    lcd.print(" ");
  }
  if (Counter1 == 3 && mainpage == 1)
  {
    lcd.setCursor(0, 2);
    lcd.print(" ");
    lcd.setCursor(0, 3);
    lcd.print(" ");
    lcd.setCursor(11, 2);
    lcd.print(">");
    lcd.setCursor(12, 3);
    lcd.print(" ");
  }
  if (Counter1 == 4 && mainpage == 1)
  {
    lcd.setCursor(0, 2);
    lcd.print(" ");
    lcd.setCursor(0, 3);
    lcd.print(" ");
    lcd.setCursor(11, 2);
    lcd.print(" ");
    lcd.setCursor(12, 3);
    lcd.print(">");
  }
}
void SubCounter1()
{
  if (Counter2 == 1 && mainpage == 2)
  {
    lcd.setCursor(0, 2);
    lcd.print(">");
    lcd.setCursor(0, 3);
    lcd.print(" ");
    lcd.setCursor(9, 2);
    lcd.print(" ");
    lcd.setCursor(11, 3);
    lcd.print(" ");
  }
  if (Counter2 == 2 && mainpage == 2)
  {
    lcd.setCursor(0, 2);
    lcd.print(" ");
    lcd.setCursor(0, 3);
    lcd.print(">");
    lcd.setCursor(9, 2);
    lcd.print(" ");
    lcd.setCursor(11, 3);
    lcd.print(" ");
  }
  if (Counter2 == 3 && mainpage == 2)
  {
    lcd.setCursor(0, 2);
    lcd.print(" ");
    lcd.setCursor(0, 3);
    lcd.print(" ");
    lcd.setCursor(9, 2);
    lcd.print(">");
    lcd.setCursor(11, 3);
    lcd.print(" ");
  }
  if (Counter2 == 4 && mainpage == 2)
  {
    lcd.setCursor(0, 2);
    lcd.print(" ");
    lcd.setCursor(0, 3);
    lcd.print(" ");
    lcd.setCursor(9, 2);
    lcd.print(" ");
    lcd.setCursor(11, 3);
    lcd.print(">");
  }
}
void SubCounter2()
{
  if (mainpage == 5)
  {
    if (Counter5 == 0)
    {
      lcd.setCursor(0, 2);
      lcd.print(">");
      lcd.setCursor(0, 3);
      lcd.print(" ");
    }
    if (Counter5 == 1)
    {
      lcd.setCursor(0, 2);
      lcd.print(" ");
      lcd.setCursor(0, 3);
      lcd.print(">");
      
    }
  }
}
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
      if (mainpage == 0)
      {
        mainpage = 1;
      }
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

      if (mainpage == 2)
      {
        if (Counter2 < 4)
        {
          Counter2++;
        }
        else
        {
          Counter2 = 1;
        }
      }
      if (mainpage == 3)
      {
        Hourinc();
      }
      if (mainpage == 4)
      {
        Minuteinc();
      }
      if (mainpage == 5)
      {
        if (Counter5 < 1)
        {
          Counter5++;
        }
        else
        {
          Counter5 = 0;
        }
      }
    }
  }
  if (buttonState2 != lastButtonState2)
  {
    if (buttonState2 == LOW)
    {
      if (mainpage == 0)
      {
        mainpage = 1;
        Counter1 = 2;

      }
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
      if (mainpage == 2)
      {
        if (Counter2 > 1)
        {
          Counter2--;
        }
        else
        {
          Counter2 = 4;
        }
      }
      if (mainpage == 3)
      {
        Hourdec();
      }
      if (mainpage == 4)
      {
        Minutedec();
      }
      if (mainpage == 5)
      {
        if (Counter5 > 0)
        {
          Counter5--;
        }
        else
        {
          Counter5 = 1;
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
      else if (mainpage == 2)
      {
        OptionSelection();
      }
      else if (mainpage == 3)
      {
        mainpage = 2;
      }
      else if (mainpage == 4)
      {
        mainpage = 2;
      }
      else if (mainpage == 5)
      {
        mainpage = 2;
      }
      else if (mainpage == 6)
      {
        mainpage = 0;
      }
  /*    else if (mainpage == 7)
      {
        mainpage = 0;
      }*/
    }
  }
  if (buttonState4 != lastButtonState4)
  {
    if (buttonState4 == LOW)
    {
      if (Al==1)
      {
        Al = 0;
        digitalWrite(buz, LOW);
        lcd.clear();
        lcd.setCursor(6, 1);
        lcd.print("THANK YOU");
        delay(500);
        lcd.clear();
        DefaultSetup();
      }
      else
      {
        lcd.clear();
        DefaultSetup();
      }
    }
  }
  lastButtonState1 = buttonState1;    //define that the laststate and present state are equal for button 1
  lastButtonState2 = buttonState2;    //define that the laststate and present state are equal for button 2
  lastButtonState3 = buttonState3;    //define that the laststate and present state are equal for button 3
  lastButtonState4 = buttonState4;    //define that the laststate and present state are equal for button 4

}
void DefaultSetup()
{
  lcd.clear();
  mainpage = 0;
  subpage = 0;
  hourpage = 0;
  minutepage = 0;
  onoffpage = 0;
  statspage = 0;
  alarmpage = 0;
  Counter1 = 0;
  Counter2 = 1;
  Counter3 = 0;
  Counter4 = 0;
  Counter5 = 0;
}
void PageSelection()
{
  if (Counter1 == 1)
  {
    mainpage = 6;
    subpage = 0;
    hourpage = 0;
    minutepage = 0;
    onoffpage = 0;
    statspage = 1;
    alarmpage = 0;
    DeterminePage();
  }
  if (Counter1 == 2)
  {
    mainpage = 2;
    subpage = 1;
    hourpage = 0;
    minutepage = 0;
    onoffpage = 0;
    statspage = 0;
    alarmpage = 0;
    DeterminePage();
  }
  if (Counter1 == 3)
  {
    mainpage = 1;
    subpage = 0;
    hourpage = 0;
    minutepage = 0;
    onoffpage = 0;
    statspage = 0;
    alarmpage = 0;
    DeterminePage();
  }
  if (Counter1 == 4)
  {
    mainpage = 1;
    subpage = 0;
    hourpage = 0;
    minutepage = 0;
    onoffpage = 0;
    statspage = 0;
    alarmpage = 0;
    DeterminePage();
  }
}
void DeterminePage()
{
  if (Counter1 == 1)
  {
    mainpage = 6;
  }
  else if (Counter1 == 2)
  {
    mainpage = 2;
  }
  else if (Counter1 == 3)
  {
    DefaultSetup();
  }
  else if (Counter1 == 4)
  {
    DefaultSetup();
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
    mainpage = 3;
  }
  if (Counter2 == 2)
  {
    mainpage = 4;
  }
  if (Counter2 == 3)
  {
    mainpage = 5;
  }
  if (Counter2 == 4)
  {
    DefaultSetup();
  }
}
void Hourinc()
{
  if (Counter3 >= 0 && Counter3 < 23)
  {
    delay(200);
    H = H + 1;
    Counter3++;
  }
  else if (Counter3 == 23)
  {
    Counter3 = 0;
    H = 0;
  }
}
void Hourdec()
{
  if (Counter3 > 0)
  {
    delay(200);
    H = H - 1;
    Counter3--;
  }
  else
  {
    Counter3 = 23;
    H = 23;
  }
}
void Minuteinc()
{
  if (Counter4 >= 0 && Counter4 < 59)
  {
    delay(200);
    M = M + 1;
    Counter4++;
  }
  else if (Counter4 == 59)
  {
    Counter4 = 0;
    M = 0;
  }
}
void Minutedec()
{
  if (Counter4 > 0)
  {
    delay(200);
    M = M - 1;
    Counter4--;
  }
  else
  {
    Counter4 = 59;
    M = 59;
  }
}
void print2digits(int number)
{
  if (number >= 0 && number < 10)
  {
    Serial.write('0');
  }
  Serial.print(number);
}
void print2digits1()
{
  if (Hour >= 0 && Hour < 10)
  {
    lcd.print("0");
  }
  lcd.print(Hour);
}
void print2digits2()
{
  if (Min >= 0 && Min < 10)
  {
    lcd.print("0");
  }
  lcd.print(Min);
}
void print2digits3()
{
  if (Sec >= 0 && Sec < 10)
  {
    lcd.print("0");
  }
  lcd.print(Sec);
}
void print2digits4()
{
  if (Day >= 0 && Day < 10)
  {
    lcd.print("0");
  }
  lcd.print(Day);
}
void print2digits5()
{
  if (Month >= 0 && Month < 10)
  {
    lcd.print("0");
  }
  lcd.print(Month);
}
void print2digits6()
{
  if (H >= 0 && H < 10)
  {
    lcd.print("0");
  }
  lcd.print(H);
}
void print2digits7()
{
  if (M >= 0 && M < 10)
  {
    lcd.print("0");
  }
  lcd.print(M);
}
void GetValue()
{
  if (RTC.read(tm))
  {
    Hour = tm.Hour;
    Min = tm.Minute;
    Sec = tm.Second;
    Day = tm.Day;
    Month = tm.Month;
    Year = tmYearToCalendar(tm.Year);
    Serial.print("Ok, Time = ");
    print2digits(Hour);
    Serial.write(':');
    print2digits(Min);
    Serial.write(':');
    print2digits(Sec);
    Serial.print(", Date (D/M/Y) = ");
    Serial.print(Day);
    Serial.write('/');
    Serial.print(Month);
    Serial.write('/');
    Serial.print(Year);
    Serial.println();
    lcd.setCursor(0,0);
    lcd.print("                    ");
    lcd.setCursor(0,1);
    lcd.print(" ");
    lcd.setCursor(1, 1);
    lcd.print("Time: ");
    lcd.setCursor(7, 1);
    print2digits1();
    lcd.setCursor(9, 1);
    lcd.print(":");
    lcd.setCursor(10, 1);
    print2digits2();
    lcd.setCursor(12, 1);
    lcd.print(":");
    lcd.setCursor(13, 1);
    print2digits3();
    lcd.setCursor(15,1);
    lcd.print("     ");
    lcd.setCursor(0,2);
    lcd.print("                    ");

    lcd.setCursor(1, 3);
    lcd.print("Date:");
    lcd.setCursor(7, 3);
    print2digits4();
    lcd.setCursor(9, 3);
    lcd.print("/");
    lcd.setCursor(10, 3);
    print2digits5();
    lcd.setCursor(12, 3);
    lcd.print("/");
    lcd.setCursor(13, 3);
    lcd.print(Year);
    lcd.setCursor(17,3);
    lcd.print("     ");
    chkalarm();
  }
}
void Buzzer()
{
  digitalWrite(buz, HIGH);
  delay(500);
  digitalWrite(buz, LOW);
  delay(500);
}

void chkalarm(){
      if ( Hour == H && Min == M)
      {
      if(Al==1){
        AlarmPage();
      }
      else{
        mainpage=0;
      }
    }
}

void loop()
{
  MainPage();
  ButtonState();
  MainCounter();
  SubCounter1();
  SubCounter2();
// chkalarm();
}
//////////////////////////////////////////////////////////////////////

