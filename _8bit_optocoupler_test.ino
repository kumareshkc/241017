/*
  DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor

 This example code is in the public domain.
 */

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton1 = 2;
int pushButton2 = 3;
int pushButton3 = 4;
int pushButton4 = 5;
int pushButton5 = 6;
int pushButton6 = 7;
int pushButton7 = 8;
int pushButton8 = 9;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton1, INPUT);
  pinMode(pushButton2, INPUT); 
  pinMode(pushButton3, INPUT);
  pinMode(pushButton4, INPUT);
  pinMode(pushButton5, INPUT);
  pinMode(pushButton6, INPUT);
  pinMode(pushButton7, INPUT);
  pinMode(pushButton8, INPUT);
  pinMode(53,OUTPUT);
  pinMode(51,OUTPUT);
  pinMode(49,OUTPUT);
  pinMode(47,OUTPUT);
  pinMode(45,OUTPUT);
  pinMode(43,OUTPUT);
  pinMode(41,OUTPUT);
  pinMode(39,OUTPUT);
  digitalWrite(53,LOW);
  digitalWrite(51,LOW);
  digitalWrite(49,LOW);
  digitalWrite(47,LOW);
  digitalWrite(45,LOW);
  digitalWrite(43,LOW);
  digitalWrite(41,LOW);
  digitalWrite(39,LOW);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState1 = digitalRead(pushButton1);
  int buttonState2 = digitalRead(pushButton2);
  int buttonState3 = digitalRead(pushButton3);
  int buttonState4 = digitalRead(pushButton4);
  int buttonState5= digitalRead(pushButton5);
  int buttonState6= digitalRead(pushButton6);
  int buttonState7= digitalRead(pushButton7);
  int buttonState8= digitalRead(pushButton8);
  // print out the state of the button:
       
       if(buttonState1 ==0)
        {
        digitalWrite(53,HIGH);
        }
        else
        {
          digitalWrite(53,LOW);
        }

        

        if(buttonState2 ==0)
        {
         digitalWrite(51,HIGH);
        }
        else
        {
          digitalWrite(51,LOW);
        }



         if(buttonState3 ==0)
          {
           digitalWrite(49,HIGH);
           }
           else
           {
            digitalWrite(49,LOW);
            }

             if(buttonState4 ==0)
             {
             digitalWrite(47,HIGH);
              }
              else
            {
            digitalWrite(47,LOW);
        }

        

        if(buttonState5 ==0)
        {
         digitalWrite(45,HIGH);
        }
        else
        {
          digitalWrite(45,LOW);
        }


         if(buttonState6 ==0)
        {
        digitalWrite(43,HIGH);
        }
        else
        {
          digitalWrite(43,LOW);
        }

        

        if(buttonState7 ==0)
        {
         digitalWrite(41,HIGH);
        }
        else
        {
          digitalWrite(41,LOW);
        }


 if(buttonState8 ==0)
        {
         digitalWrite(39,HIGH);
        }
        else
        {
          digitalWrite(39,LOW);
        }
        

        
  //Serial.println(buttonState);
  delay(1);        // delay in between reads for stability
}

