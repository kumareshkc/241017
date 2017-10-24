int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup()
{
 Serial.begin(9600);
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT); 
 pinMode(5,OUTPUT);
}

void loop() 
{
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  val = analogRead(potpin);           
  val = map(val, 0, 1023, 0, 255);     
  analogWrite(5,val); 
  Serial.println(val);                
  delay(500);                          
}

