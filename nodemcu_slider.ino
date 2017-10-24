//NOTE:  Opening the Serial Monitor tool in Arduino 1.6.4 causes the ESP8266 to reset

#include <ESP8266WiFi.h>
#include <NeoPixelBus.h>

#define pixelCount 8

NeoPixelBus strip = NeoPixelBus(pixelCount, 5);  //D10(TX) on the nodemcu board is 1, D2 is pin 4

int openClosePin = 5;
int statusPin = 4;


WiFiServer server(80);

//*-- IoT Information
const char* SSID = "garage_door";
const char* PASS = "123456789";
int redVal;
int redTemp=1;
int greVal;
int bluVal;
int mattradVal;
char colorBuff[4];
int ledState = LOW;             // ledState used to set the LED
unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 300;           // interval at which to blink (milliseconds)
int intCyclopsLedCnt=1;

void setup() {
    Serial.begin(115200);  //NOTE:  this must be done after "strip.Begin()" or Serial Monitor will crash the ESP8266
    delay(50);
    Serial.println();
    Serial.println();
    Serial.print("starting up and connecting to: ");
    Serial.println(SSID);    
    WiFi.softAP(SSID, PASS);  //start the ESP8266 as an Access point
    Serial.println("WiFi connected");
    delay(1000);
    server.begin();  //Start the web server
    Serial.println("Server started");

    strip.Begin();  //this resets all the neopixels to an off state, NOTE: this must be done before serial.begin or "serial monitor" will crash the ESP8266
    strip.Show();
    delay(1000);
}

void loop() {
  int bufLength;

//  strip.SetPixelColor(1,RgbColor(44,55,0)); 
//  strip.Show();
  delay(500);
 
  if(mattradVal==1)
  {
    cyclopsIt();
  }
  if(mattradVal==2)
  {
    twinkleIt();
  }
 
  WiFiClient client = server.available();    // Check if a client has connected
  if (!client) {
    return;  //do nothing if there is not a client for the server
  }
   
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
   
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println("Request is:");
  Serial.println(request);
  client.flush();

  if(request.indexOf("submit") != -1) {  //this is used to ignore "favicon.ico" and other requests
     int Pos_r = request.indexOf("redVal");
     int Pos_g = request.indexOf("greVal", Pos_r);  //finds a location of a string "g", after the position of "r"
     int Pos_b = request.indexOf("bluVal", Pos_g);
     int Pos_rad = request.indexOf("matrad",Pos_b);
     int End = request.indexOf("H", Pos_b);
     if(End < 0){
       End =  request.length() + 1;
     }
     //red
     bufLength = ((Pos_g) - (Pos_r+7));    //the 7 is for the "redVal=" string
     if(bufLength > 4){  //dont overflow the buffer  (we only want 3 digits)
       bufLength = 4;
     }    
     request.substring((Pos_r+7), (Pos_g-1)).toCharArray(colorBuff, bufLength);  //transfer substring to buffer  (cuts from past the "r=" to just before the "g", stores the length into a buffer)
     redVal = atoi(colorBuff);  //converts the array (3 digits) into an interger, this will be the red value
     //Green
     bufLength = ((Pos_b) - (Pos_g+7));    //the 7 is for the "greVal=" string
     if(bufLength > 4){  //dont overflow the buffer
       bufLength = 4;
     }      
     request.substring((Pos_g+7), (Pos_b-1)).toCharArray(colorBuff, bufLength);  //transfer substring to buffer
     greVal = atoi(colorBuff);
     //blue
     bufLength = ((Pos_rad) - (Pos_b+7));  //start to get the blue value
     if(bufLength > 4){  //dont overflow the buffer
       bufLength = 4;
     }      
     request.substring((Pos_b+7), (Pos_rad-1)).toCharArray(colorBuff, bufLength);  //transfer substring to buffer
     bluVal = atoi(colorBuff);



     bufLength = ((End) - (Pos_rad+7));
     if(bufLength > 4){  //dont overflow the buffer
       bufLength = 4;
     }      
     request.substring((Pos_rad+7), (End-1)).toCharArray(colorBuff, bufLength);  //transfer substring to buffer
     mattradVal = atoi(colorBuff);
    
     
    Serial.println("Red is:  ");
    Serial.println(redVal); 
    redTemp=redVal;
    Serial.println("Green is:  ");
    Serial.println(greVal); 
    Serial.println("Blue is:  ");
    Serial.println(bluVal);
    Serial.println("radio button is:  ");
//    Serial.println(mattradVal);
     strip.SetPixelColor(0,RgbColor(redVal,greVal,bluVal)); 
     strip.SetPixelColor(1,RgbColor(redVal,greVal,bluVal)); 
     strip.SetPixelColor(2,RgbColor(redVal,greVal,bluVal)); 
     strip.SetPixelColor(3,RgbColor(redVal,greVal,bluVal)); 
     strip.SetPixelColor(4,RgbColor(redVal,greVal,bluVal)); 
     strip.SetPixelColor(5,RgbColor(redVal,greVal,bluVal)); 
     strip.SetPixelColor(6,RgbColor(redVal,greVal,bluVal)); 
     strip.SetPixelColor(7,RgbColor(redVal,greVal,bluVal)); 
     strip.Show();
  }

  // Return the response
  client.println("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
  client.println("<!DOCTYPE HTML>\r\n<html>\r\n<head>\r\n<title>Matt's test page</title>");
  client.println("<meta name='viewport' content='width=device-width', initial-scale='1'>");
  client.println("<br>");
  client.println("<body><center>Set the color and then choose an animation:");
  client.println("<form method=get><br>Red:  <input type='range' min='1' max='100' name=redVal value=redTemp oninput='showValue(this.value)'>");    //was onchange event
  client.println("<span id='range'>0</span>");
  client.println("<script type='text/javascript'>\r\nfunction showValue(newValue)\r\n{\r\ndocument.getElementById('range').innerHTML=newValue;\r\n}\r\n</script>\r\n");
/*
  client.println("<script type='text/javascript'>");
  client.println("function showValue(newValue)");
  client.println("{");
  client.println("document.getElementById('range').innerHTML=newValue;");
  client.println("}");
  client.println("</script>");
 */
  client.print("<br><br>Green:  <input type='range' min='1' max='100' name=greVal value=>");
  client.print("<br><br>Blue:  <input type='range' min='1' max='100' name=bluVal value=>");
  client.print("<br><br><input type=radio name='matrad' value='1' checked>Cyclopse</>"); 
  client.print("<input type=radio name='matrad' value='2'>Twinkle</>"); 
  client.print("<input type=radio name='matrad' value='3'>Solid On</>"); 
  client.println("&nbsp;<br><br><input name=H type=submit value=submit><br><br>");  //</form>
  client.println("</form>");
  client.println("<script type='text/javascript'></script>\r\n");
  client.println("</center>");
  client.println("</BODY>");
  client.println("</HTML>");
  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
  
}

void blinkIt(void)
{
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW)
    {
      ledState = HIGH;
     strip.SetPixelColor(0,RgbColor(255,30,30)); 
     strip.SetPixelColor(1,RgbColor(255,30,30)); 
    }
    else
    {
      ledState = LOW;
     strip.SetPixelColor(0,RgbColor(5,30,250)); 
     strip.SetPixelColor(1,RgbColor(5,30,250)); 
    }
    strip.Show();
  }
}

void cyclopsIt(void)
{
  unsigned long currentMillis = millis();
   
  if(currentMillis - previousMillis >= interval) 
  {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   
    
    intCyclopsLedCnt=intCyclopsLedCnt+1;  //advance to the next LED
    if(intCyclopsLedCnt>15)  //There are 8, RGB LED's, this cycles through the 8 going one direction and then 8 going the other direction
    {
      intCyclopsLedCnt=0; //start the LED cyclops over again
    }     
    if(intCyclopsLedCnt <= 7)  //are we going from left to right in lighting up the LED's?
    {
      strip.SetPixelColor(intCyclopsLedCnt,RgbColor(redVal,greVal,bluVal));   //turn on the current LED, based on the 3 slider color
      if(intCyclopsLedCnt>0)  //make sure we haave advanced by one LED before we turn off the previous LED
      {
        strip.SetPixelColor(intCyclopsLedCnt-1,RgbColor(0,0,0));   //turn off the previous LED
      }
    }
    if(intCyclopsLedCnt > 7)  //are we advancing from right to left?
    {
      strip.SetPixelColor(15-intCyclopsLedCnt,RgbColor(100,10,10));   //when going in this direction, always be red
      strip.SetPixelColor(16-intCyclopsLedCnt,RgbColor(0,0,0));   //turn off the previous LED
    }
    strip.Show();  //update the neopixels (WS2812 RGB LED's)
  }
}

void twinkleIt(void)
{
  unsigned long currentMillis = millis();
   
  if(currentMillis - previousMillis >= interval) 
  {
      // save the last time you blinked the LED 
      previousMillis = currentMillis;   
      
      
  }  
  
}
- See more at: http://www.esp8266.com/viewtopic.php?f=8&t=3598#sthash.wo49SQ2k.dpuf
