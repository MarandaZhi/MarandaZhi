#include <WebSocketsClient.h>
#include <Hash.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>

WebSocketsClient webSocket;

void webSocketEvent(WStype_t type, uint8_t *payload, size_t length)
{

  switch (type)
  {

case WStype_TEXT: ws:
      String  command = (char*)payload;
      //pwmin = command.toInt();
      Serial.print(command);
      break;


  }
}
void setup() {

  Serial.begin(115200);
 

//  WiFiManager wifiManager;
//  wifiManager.autoConnect("接收端");
   WiFi.begin("***", "****");

// while (WiFi.status() != WL_CONNECTED) {
//    delay(500);
//    Serial.print(".");
//  }



  webSocket.begin("39.108.65.86", 8109, "/espws");//app 8108


  webSocket.onEvent(webSocketEvent);
  webSocket.setReconnectInterval(5000);
}




void loop() {



  webSocket.loop();
}
