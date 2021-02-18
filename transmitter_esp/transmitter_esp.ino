#include <WebSocketsClient.h>
#include <Hash.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>

WebSocketsClient webSocket;
void setup() {

  Serial.begin(115200);

  WiFiManager wifiManager;
  wifiManager.autoConnect("控制端");




  webSocket.begin("39.108.65.86", 8108, "/espws");//app 8109



  webSocket.setReconnectInterval(5000);
}

String readString;

void loop() {

  while (Serial.available()) { //返回串口缓冲区中当前剩余的字符个数
    char c = Serial.read(); //读取数据
    readString += c;
    delay(2);
  }

  if (readString.length() > 0) { //串口接收到了数据，可以读取
    Serial.println(readString);


    webSocket.sendTXT(readString);
    readString = "";
  }


  webSocket.loop();



}
