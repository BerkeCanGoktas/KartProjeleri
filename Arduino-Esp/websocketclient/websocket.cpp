#include "websocket.h"

 void WebSocket::tryToConnect(){
  bool success = this->client.connect(this->websockets_server_host, this->websockets_server_port, "/");
  if(success) {
        Serial.println("Connected!");
    } else {
        Serial.println("Not Connected!");
    }
  this->setConnected(success);
 };
 void WebSocket::sendMessage(const char* msg){
    if(this->connected) {
      if(this->client.available()){
        this->client.send(msg);
      }
       else{
        this->tryToConnect();
       }
    } else {
        Serial.println("Not Connected!");
        this->tryToConnect();
    }
  };
  void WebSocket::whenMessageRecieved(){
    // run callback when messages are received
    this->client.onMessage([&](WebsocketsMessage message) {
        Serial.print("Got Message: ");
        Serial.println(message.data());
    });
  };
  void WebSocket::checkMessages(){
    if(this->client.available()) {
        this->client.poll();
    }
  };
  void WebSocket::setServerAddress(const char* address){
    this->websockets_server_host = address;
  };
  void WebSocket::setServerPort(uint16_t port){
    this->websockets_server_port = port;
  };
  void WebSocket::setConnected(bool success){
    this->connected = success;
  };
  WebsocketsClient WebSocket::getClient(){
    return this->client;
  };
