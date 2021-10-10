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
#define LORA_FREQUENCY 433E6    // Set LoRa frequency
#define SERIAL_BAUD 9600        // Set serial baud rate for debugging
#define CS_PIN 15               // LoRa radio chip select
#define RST_PIN 16              // LoRa radio reset
#define IRQ_PIN 4               // change for your board; must be a hardware interrupt pin
/*
 * Define DEBUG for Debug Mode
 * DEBUG_LEVEL 0,1,2 can be used for various debugging levels
 * 0: Verbose mode
 * 1: Debug mode
 * 2: End user mode
*/
#define DEBUG 
#define DEBUG_LEVEL 1
#ifdef DEBUG
#define debug_Println(level,msg) { \
        if(DEBUG_LEVEL <= level) \
        Serial.println(msg); \
        }
#define debug_Print(level,msg) { \
        if(DEBUG_LEVEL <= level) \
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
  //Initialize LoRa for radio communication
  LoRa.setPins(CS_PIN, RST_PIN, IRQ_PIN);
  if (!LoRa.begin(LORA_FREQUENCY)) 
  {
   debug_Println(1,"\nStarting LoRa failed..! Error.");
   while (true);                     // if failed, loop for ever.
  }
  debug_Println(1,"Lora Init Success...");
}

void loop() 
{
  debug_Println(0,"Main thread running...");
  delay(1000); //FIXME: REMOVE THIS LINE AFTER ADDING MAIN THREAD FUNCTIONS
}
