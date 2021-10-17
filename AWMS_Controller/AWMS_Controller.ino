/*
   Automatic Water Management system(AWMS)
   Project done at IoTuneZ technologies
   as part of industrial internship
   Author: R&D lead and Interns at IoTuneZ Technologies
   Code for Controller
   Communication is done using radio wave transmission of packets.
   LoRa modules are used for transmitting datas.
*/
#include <SPI.h>                // include libraries
#include <LoRa.h>
#include <Wire.h>
#include "WMMOled.h"
#include "SSD1306Wire.h"
#define LORA_FREQUENCY 433E6    // Set LoRa frequency
#define SERIAL_BAUD 9600        // Set serial baud rate for debugging
#define CS_PIN 15               // LoRa radio chip select
#define RST_PIN 16              // LoRa radio reset
#define IRQ_PIN 4               // change for your board; must be a hardware interrupt pin
#define SDA_PIN 10              //OLED I2c Data pin 
#define SCL_PIN 9               //OLED I2c Clock pin 
#define ADDRESS 0x3c            //address of 126X64 OLED
//Declaring Object of SSD1306Wire :@address ,@SDA_PIN,@SCK_PIN
SSD1306Wire display(ADDRESS,SDA_PIN,SCL_PIN); 

/*
 * Define DEBUG for Debug Mode
 * DEBUG_LEVEL 0,1,2 can be used for various debugging levels
 * 2: Verbose mode
 * 1: Debug mode
 * 0: End user mode
*/
#define DEBUG 
#define DEBUG_LEVEL 1
#ifdef DEBUG
#define debug_Println(level,msg) { \
        if(DEBUG_LEVEL >= level) \
        Serial.println(msg); \
        }
#define debug_Print(level,msg) { \
        if(DEBUG_LEVEL >= level) \
        Serial.print(msg); \
        }
#else
#define debug_Println(x)
#define debug_Print(x)
#endif

void setup() 
{
  //Initialize Serial communication for debugging.
  Serial.begin(SERIAL_BAUD);
  debug_Println(1,"\nSerial Init Success...");
  //Initialize I2C Communication pin for OLED display.
  Wire.begin(SDA_PIN,SCL_PIN);
  //Initialize LoRa for radio communication
  LoRa.setPins(CS_PIN, RST_PIN, IRQ_PIN);
  if (!LoRa.begin(LORA_FREQUENCY)) 
  {
   debug_Println(1,"\nStarting LoRa failed..! Error.");
   while (true);                     // if failed, loop for ever.
  }
  debug_Println(1,"Lora Init Success...");

  //Initialize GPIO pins OUTPUT, INPUT
  //gpioInit();

  //Initialize OLED
  oledInit(display);

  //initialize WiFi
  //create_access_point.
  //wifiInit();

  //async_webserver_to_save_the_conigfuration
  //async webServer(function to handle input data);

  //Initialize NTP
  //ntpInit();//save UTC time.

  //Initialize AES
  //aesInit();
  
  //initialize file system
   if (SPIFFS.begin()) 
   {
    debug_Println(1,"\nSPIFFS Active");
  } 
  else {
    debug_Println(1,"\nUnable to activate SPIFFS");
  }
}
  //system reset flag 

  //set button gpio as input hardware interupt
  //ISR for button interupt(set number as per secs)


void loop() 
{
  
  debug_Println(2,"Main thread running...");

  //Button press handler (function to handle what to do with each type of button press comes in)

  //check last message (function to check if any message is received)

  //message handler function (Function to handle message if any message is received)

  //sync time function (sync time every 3 days w.r.t to last time synced)

  //update millis
  
}
