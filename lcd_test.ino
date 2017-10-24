#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x38,16,2);
void setup() 
{
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(A0,INPUT);
  delay(500);
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("HELLO");
  delay(500);
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("WELCOME");
  delay(500);
  lcd.clear();
}

void loop() 
{
    int sensorValue = analogRead(A0);
    lcd.setCursor(0, 0);
    lcd.print("the analog value");
    lcd.setCursor(0, 1);
    lcd.print("is         ");
    lcd.setCursor(12, 1);
    lcd.print(sensorValue); 

}
