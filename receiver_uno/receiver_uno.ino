

void setup() {

  Serial.begin(115200);

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
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
    if (readString == "Click") {
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      delay(100);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
    }

    readString = "";
  }


}
