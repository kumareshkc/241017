/*
SD card datalogger
 
This example shows how to log data from three analog sensors 
to an SD card using the SD library.    
The circuit:
* analog sensors on analog ins 0, 1, and 2
* SD card attached to SPI bus as follows:
** MOSI - pin 11
** MISO - pin 12
** CLK - pin 13
** CS - pin 4 
*/

#include <ESP8266WiFi.h>  
#include <WiFiClient.h>  
#include <ThingSpeak.h>  
#include <SD.h>
const char* ssid = "Evermore Ventures - BLR";  
const char* password = "22296598"; 
const char* server = "api.thingspeak.com";  
WiFiClient client;  
unsigned long myChannelNumber = 320890;  
const char * myWriteAPIKey = "ZJROVYLA3C4LAD8J";   
const int chipSelect = 4;
int sensor; 
int analogPin=0;      

void setup()
{
Serial.begin(115200);
while (!Serial)
  {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
    Serial.print("Initializing SD card...");
    pinMode(10, OUTPUT);  
       if (!SD.begin(chipSelect)) 
       {
       Serial.println("Card failed, or not present");
       return;
       }
    
       Serial.println("card initialized.");
       pinMode(analogPin,INPUT);

  Serial.println();  
  Serial.println();  
  Serial.print("Connecting to ");  
  Serial.println(ssid);  
  WiFi.begin(ssid, password);  
 while (WiFi.status() != WL_CONNECTED)  
  {  
   delay(500);  
   Serial.print(".");  
  }  
  Serial.println("");  
  Serial.println("WiFi connected");  
  // Print the IP address  
  Serial.println(WiFi.localIP());  
  ThingSpeak.begin(client);       
}

void loop()
{
  if(Serial.available()>= 0)
  {
   String dataString = "";
        //if( analogPin==0)
          //{
           sensor = analogRead(analogPin);
           delay(250);
          //}
   
          dataString += String(sensor);
          File dataFile = SD.open("data.txt", FILE_WRITE);

          if (dataFile)
            {
             dataFile.println(dataString);
             dataFile.close();
             Serial.println(dataString);
            }  
            // if the file isn't open, pop up an error:
        else
           {
           Serial.println("error opening datalog.txt");
           } 
       }
       else
       {         
         ThingSpeak.writeField(myChannelNumber, 1,sensor, myWriteAPIKey);
         Serial.println(sensor);    
         delay(250);
      }

}





