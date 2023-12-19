#include <SimpleDHT.h>
#include <HTTPClient.h>
#include <BluetoothSerial.h>
BluetoothSerial SerialBT;
const char ssid[] = "jessie";
const char password[] = "chochorai";
String url = "http://api.thingspeak.com/update?api_key=ZZF3VNRSZW5S7FH6";
int pinDHT11 = 15;
SimpleDHT11 dht11(pinDHT11);
int a=14;
int b=27;
int c=19;
int d=22;
int e=23;
int f=13;
int g=12;
int dp=21;
int BTN=18;
int BUZZ=25;
int GREEN=17;
int RED=16;
int buttonstate = 0;
int lastButtonstate = 0;
void setup() {
  pinMode(BTN,INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BUZZ, OUTPUT);
  pinMode(a, OUTPUT);  
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(dp, OUTPUT);
  digitalWrite(dp, 1);
  digitalWrite(a, 1);
  digitalWrite(b, 1);
  digitalWrite(c, 1);
  digitalWrite(d, 1);
  digitalWrite(e, 1);
  digitalWrite(f, 1);
  digitalWrite(g, 1);
  Serial.print(F("開始連線到無線網路SSID:"));
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println(F("連線完成"));
  SerialBT.begin(F("ESP32_BT"));
  Serial.begin(115200);
}
void loop() {
  buttonstate = digitalRead(BTN);
  if(buttonstate==0&&lastButtonstate==1){
    Serial.println(F("=========="));
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print(F("溫度計讀取失敗，錯誤碼=")); Serial.println(err); delay(1000);
    return;
  }
  Serial.print(F("溫度計讀取成功: "));
  Serial.print((int)temperature); Serial.print(F(" *C, "));
  Serial.print((int)humidity); Serial.println(F("%H"));
  Serial.println(F("啟動網頁連線"));
  HTTPClient http;
  String url1 = url + "&field1=" + (int)temperature + "&field2=" + (int)humidity;
  http.begin(url1);
  int httpCode = http.GET();
  if (httpCode == HTTP_CODE_OK){
    String payload = http.getString();
    Serial.print(F("網頁內容="));
    Serial.println(payload);
  } else {
    Serial.println(F("網路傳送失敗"));
  }
  int ans=(int)temperature%10;  
  char n;
  if(ans==0){n1();n='0';}
  else if(ans==1){n1();n='1';}
  else if(ans==2){n2();n='2';}
  else if(ans==3){n3();n='3';}
  else if(ans==4){n4();n='4';}
  else if(ans==5){n5();n='5';}
  else if(ans==6){n6();n='6';}
  else if(ans==7){n7();n='7';}
  else if(ans==8){n8();n='8';}
  else if(ans==9){n9();n='9';}
  //
  bool flag=false;
  while(flag!=true){
    char text='n';
    while(text=='n'){
     if (SerialBT.available()) {
     text = SerialBT.read();
     Serial.println(text);
    }
   }
   if(text==n){
      digitalWrite(GREEN,HIGH);delay(1000);
      digitalWrite(GREEN,LOW);delay(1000);
      flag=true;
    }
    else{
      digitalWrite(RED,HIGH);delay(1000);
      digitalWrite(RED,LOW);delay(1000);
    }
  }
  if(ans==0){digital_0();}
  else if(ans==1){digital_1();}
  else if(ans==2){digital_2();}
  else if(ans==3){digital_3();}
  else if(ans==4){digital_4();}
  else if(ans==5){digital_5();}
  else if(ans==6){digital_6();}
  else if(ans==7){digital_7();}
  else if(ans==8){digital_8();}
  else if(ans==9){digital_9();}
  }
  lastButtonstate = buttonstate;
}
void digital_0(void)
{
  digitalWrite(a, 0);
  digitalWrite(b, 0);
  digitalWrite(c, 0);
  digitalWrite(d, 0);
  digitalWrite(e, 0);
  digitalWrite(f, 0);
  digitalWrite(g, 1);  
}
void digital_1(void)
{
  digitalWrite(a, 0);
  digitalWrite(b, 1);
  digitalWrite(c, 1);
  digitalWrite(d, 0);
  digitalWrite(e, 0);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
}
void digital_2(void)
{
  digitalWrite(a, 0);
  digitalWrite(b, 0);
  digitalWrite(c, 1);
  digitalWrite(d, 0);
  digitalWrite(e, 0);
  digitalWrite(f, 1);
  digitalWrite(g, 0);
}
void digital_3(void)
{
  digitalWrite(a, 0);
  digitalWrite(b, 0);
  digitalWrite(c, 0);
  digitalWrite(d, 0);
  digitalWrite(e, 1);
  digitalWrite(f, 1);
  digitalWrite(g, 0);
}
void digital_4(void)
{
  digitalWrite(a, 1);
  digitalWrite(b, 0);
  digitalWrite(c, 0);
  digitalWrite(d, 1);
  digitalWrite(e, 1);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
}
void digital_5(void)
{
  digitalWrite(a, 0);
  digitalWrite(b, 1);
  digitalWrite(c, 0);
  digitalWrite(d, 0);
  digitalWrite(e, 1);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
}
void digital_6(void)
{
  digitalWrite(a, 0);
  digitalWrite(b, 1);
  digitalWrite(c, 0);
  digitalWrite(d, 0);
  digitalWrite(e, 0);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
  }
void digital_7(void)
{
  digitalWrite(a, 0);
  digitalWrite(b, 0);
  digitalWrite(c, 0);
  digitalWrite(d, 1);
  digitalWrite(e, 1);
  digitalWrite(f, 1);
  digitalWrite(g, 1);
}
void digital_8(void)
{
  digitalWrite(a, 0);
  digitalWrite(b, 0);
  digitalWrite(c, 0);
  digitalWrite(d, 0);
  digitalWrite(e, 0);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
}
void digital_9(void)
{
  digitalWrite(a, 0);
  digitalWrite(b, 0);
  digitalWrite(c, 0);
  digitalWrite(d, 1);
  digitalWrite(e, 1);
  digitalWrite(f, 0);
  digitalWrite(g, 0);
}
void n1 () {dot();dash();dash();dash();dash();}
void n2 () {dot();dot();dash();dash();dash();}
void n3 () {dot();dot();dot();dash();dash();}
void n4 () {dot();dot();dot();dot();dash();}
void n5 () {dot();dot();dot();dot();dot();}
void n6 () {dash();dot();dot();dot();dot();}
void n7 () {dash();dash();dot();dot();dot();}
void n8 () {dash();dash();dash();dot();dot();}
void n9 () {dash();dash();dash();dash();dot();}
void n0 () {dash();dash();dash();dash();dash();}
void dot () {digitalWrite(BUZZ,HIGH); delay (100); digitalWrite(BUZZ,LOW); delay (200);}
void dash () {digitalWrite(BUZZ,HIGH); delay (300); digitalWrite(BUZZ,LOW); delay (200);}
