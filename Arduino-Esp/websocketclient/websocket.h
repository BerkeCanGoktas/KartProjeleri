#include <ArduinoWebsockets.h>

using namespace websockets;

class WebSocket{

private:
  WebsocketsClient client;
  const char* websockets_server_host;  //server adress
  uint16_t websockets_server_port; //server port
  bool connected;

public:
  void tryToConnect();
  void sendMessage(const char* msg);
  void whenMessageRecieved();
  void checkMessages();
  
  void setServerAddress(const char* address);
  void setServerPort(uint16_t port);
  void setConnected(bool success);
  WebsocketsClient getClient();
};
