/*
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */

#include <Arduino.h>
#include "WiFi.h"

#define WIFI_NETWORK "SPARK-7J5TDB"
#define WIFI_PASSWORD "VXKTSEH8ME"
#define WIFI_TIMEOUT_MS 20000

void connectToWiFi() {
  Serial.println("Connecting to Wifi");
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_NETWORK, WIFI_PASSWORD);

  unsigned long startAttemptTime = millis();

  while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < WIFI_TIMEOUT_MS){
    Serial.print(".");
    delay(100);
  }

  if(WiFi.status() != WL_CONNECTED){
    Serial.println("Failed!");
    //take action 
  } else {
    Serial.println("Connected!");
    Serial.println(WiFi.localIP());
  }
}

// Set LED_BUILTIN if it is not defined by Arduino framework
// #define LED_BUILTIN 2

void setup()
{
  // initialize LED digital pin as an output.
  Serial.begin(9600);
  connectToWiFi();

}

void loop()
{
  // turn the LED on (HIGH is the voltage level)

}