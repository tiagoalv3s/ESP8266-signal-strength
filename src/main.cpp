/*****************************************
 * ESP8266 SIGNAL STRENGTH VISUALIZATION *
 *****************************************/

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include "ThingSpeak.h"

const char* ssid = "ssid";
const char* password = "password";

// Channel ID number and API key provided by ThingSpeak
unsigned long channel = 0000000;
const char* apiKey = "Your write API key";

WiFiClient client;

void setup() {
    Serial.begin(115200);
    delay(10);
    Serial.print("Connecting to WiFi");
    WiFi.begin( ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(100);
        Serial.print(".");
    }
    Serial.println(" Connected!");

    ThingSpeak.begin(client);
}

void loop() {
    long rssi = WiFi.RSSI();

    int http = ThingSpeak.writeField(channel, 1, rssi, apiKey);

    if (http == 200){
        Serial.println("Write done.");
    } else {
        Serial.println("Error" + String(http));
    }

    delay(20000);
}