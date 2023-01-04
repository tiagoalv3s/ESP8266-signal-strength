#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include "ThingSpeak.h"
#include "secrets.h"

const char* ssid = "ssid";
const char* password = "password";

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

}