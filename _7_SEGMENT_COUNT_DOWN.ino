int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
void setup() {
  // put your setup code here, to run once:
pinMode(pinA,OUTPUT);
pinMode(pinB,OUTPUT);
pinMode(pinC,OUTPUT);
pinMode(pinD,OUTPUT);
pinMode(pinE,OUTPUT);
pinMode(pinF,OUTPUT);
pinMode(pinG,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  // 9
digitalWrite(pinA,LOW);
digitalWrite(pinB,LOW);
digitalWrite(pinC,LOW);
digitalWrite(pinD,HIGH);
digitalWrite(pinE,HIGH);
digitalWrite(pinF,LOW);
digitalWrite(pinG,LOW);
delay(1000);
  // 8
digitalWrite(pinA,LOW);
digitalWrite(pinB,LOW);
digitalWrite(pinC,LOW);
digitalWrite(pinD,LOW);
digitalWrite(pinE,LOW);
digitalWrite(pinF,LOW);
digitalWrite(pinG,LOW);
delay(1000);
  // 7
digitalWrite(pinA,LOW);
digitalWrite(pinB,LOW);
digitalWrite(pinC,LOW);
digitalWrite(pinD,HIGH);
digitalWrite(pinE,HIGH);
digitalWrite(pinF,HIGH);
digitalWrite(pinG,HIGH);
delay(1000);
  // 6
digitalWrite(pinA,LOW);
digitalWrite(pinB,HIGH);
digitalWrite(pinC,LOW);
digitalWrite(pinD,LOW);
digitalWrite(pinE,LOW);
digitalWrite(pinF,LOW);
digitalWrite(pinG,LOW);
delay(1000);
 // 5
digitalWrite(pinA,LOW);
digitalWrite(pinB,HIGH);
digitalWrite(pinC,LOW);
digitalWrite(pinD,LOW);
digitalWrite(pinE,HIGH);
digitalWrite(pinF,LOW);
digitalWrite(pinG,LOW);
delay(1000);
  // 4
digitalWrite(pinA,HIGH);
digitalWrite(pinB,LOW);
digitalWrite(pinC,LOW);
digitalWrite(pinD,HIGH);
digitalWrite(pinE,HIGH);
digitalWrite(pinF,LOW);
digitalWrite(pinG,LOW);
delay(1000);
  // 3
digitalWrite(pinA,LOW);
digitalWrite(pinB,LOW);
digitalWrite(pinC,LOW);
digitalWrite(pinD,LOW);
digitalWrite(pinE,HIGH);
digitalWrite(pinF,HIGH);
digitalWrite(pinG,LOW);
delay(1000);
  // 2
digitalWrite(pinA,LOW);
digitalWrite(pinB,LOW);
digitalWrite(pinC,HIGH);
digitalWrite(pinD,LOW);
digitalWrite(pinE,LOW);
digitalWrite(pinF,HIGH);
digitalWrite(pinG,LOW);
delay(1000);
  // 1
digitalWrite(pinA,HIGH);
digitalWrite(pinB,LOW);
digitalWrite(pinC,LOW);
digitalWrite(pinD,HIGH);
digitalWrite(pinE,HIGH);
digitalWrite(pinF,HIGH);
digitalWrite(pinG,HIGH);
delay(1000);
  //0
digitalWrite(pinA,LOW);
digitalWrite(pinB,LOW);
digitalWrite(pinC,LOW);
digitalWrite(pinD,LOW);
digitalWrite(pinE,LOW);
digitalWrite(pinF,LOW);
digitalWrite(pinG,HIGH);
delay(1000);
}
