/*
  Esp8266 Websockets Client
  This sketch:
        1. Connects to a WiFi network
        2. Connects to a Websockets server
        3. Sends the websockets server a message ("Hello Server")
        4. Prints all incoming messages while the connection is open
  Hardware:
        For this sketch you only need an ESP8266 board.
  Created 15/02/2019
  By Gil Maimon
  https://github.com/gilmaimon/ArduinoWebsockets
*/

#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include "websocket.h"
#include "accelometer.h"

Accelometer accelSensor;
WebSocket socket;

const char* ssid = "Redmi Note 9 Pro"; //Enter SSID
const char* password = "7d7e3c031eac"; //Enter Password
//const char* ssid = "SUPERONLINE_WiFi_2.4G_5481"; //Enter SSID
//const char* password = "RFNECRWFPM4K"; //Enter Password
//StaticJsonDocument<200> doc;
int velocity = 0;
const char* setMessage(const char* topic, std::string content){
  StaticJsonDocument<200> doc;
  doc["topic"] = topic;
  doc["content"] = content;
  char json_string[256];
  serializeJson(doc, json_string);
  return json_string;
}

void setup() {
    Serial.begin(115200);
    accelSensor.initialiseSensor();
    socket.setServerAddress("192.168.237.142"); //Enter server adress
    socket.setServerPort(3001); // Enter server port

    // Connect to wifi
    WiFi.begin(ssid, password);

    // Wait some time to connect to wifi
    for(int i = 0; i < 10 && WiFi.status() != WL_CONNECTED; i++) {
        Serial.print(".");
        delay(1000);
    }
    // Check if connected to wifi
    if(WiFi.status() != WL_CONNECTED) {
        Serial.println("No Wifi!");
        return;
    }
    Serial.print("IP:");
    Serial.println(WiFi.localIP());
    Serial.println("Connected to Wifi, Connecting to server.");
    // try to connect to Websockets server
    socket.tryToConnect();
    socket.whenMessageRecieved();
}

void loop() {
    // let the websockets client check for incoming messages
    socket.checkMessages();
    if(WiFi.status() != WL_CONNECTED) {
        Serial.println("No Wifi!");
        return;
    }
    StaticJsonDocument<200> doc;
      doc["topic"] = "Tren/Velocity";
      //int state = 0; //hızlanma, duraktan kalkarken bu state olacak durağa varıldığında state 1 (yavaşlama) stateine geçilecek, renk sensöründe ayarlanmalı
      //velocity = round(accelSensor.calculateSpeed(state, velocity));
      doc["content"] = velocity;
      char json_string[256];
      serializeJson(doc, json_string);
    socket.sendMessage(json_string);
    //socket.sendMessage(setMessage("Tren/Velocity",  std::to_string(velocity)));
    delay(500);
}
