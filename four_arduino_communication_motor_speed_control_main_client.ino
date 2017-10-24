#include <Wire.h>
const byte slaveId = 1;

int volts;
byte c[2];

void setup()
{
  Wire.begin(slaveId); 
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestevent);
  Serial.begin(115200);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(10,OUTPUT);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);  
  digitalWrite(10,LOW);    
}

void loop()
{
}

void receiveEvent(int howMany)
{  
  while (1 < Wire.available())
  { 
    char c = Wire.read();
    analogWrite(10,c);
    Serial.print(c); 
     if (c == 'H')
    {
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);     
    }
    else if(c == 'L')
    {
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);      
    }    
    else 
    {
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);      
    }      
  }
  int x = Wire.read();
  analogWrite(10,x);    
  Serial.println(x);       
}
void requestevent()
{
volts = analogRead(0);
c[0] = highByte(volts);
c[1]=lowByte(volts);
Wire.write(c,2);
}
