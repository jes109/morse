#include <WiFi.h>
#include <HTTPClient.h>
#include <SimpleDHT.h>
//請修改以下參數--------------------------------------------
const char ssid[]     = "jessie"; //ssid:網路名稱
const char password[] = "chochorai"; //pasword：網路密碼
//請修改為你自己的API Key，並將https改為http
String url = "http://api.thingspeak.com/update?api_key=ZZF3VNRSZW5S7FH6";
int pinDHT11 = 15;
//---------------------------------------------------------
SimpleDHT11 dht11(pinDHT11);//宣告SimpleDHT11物件
//
int a=14;
int b=27;
int c=19;
int d=22;
int e=23;
int f=13;
int g=12;
int dp=21;
int BTN=18;
int RED=16;
int buttonstate = 0;
int lastButtonstate = 0;
//
void setup()
{
  pinMode(BTN,INPUT);
  pinMode(a, OUTPUT);  
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(dp, OUTPUT);
  digitalWrite(dp, 1);
  //
  Serial.begin(115200);
  Serial.print("開始連線到無線網路SSID:");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("連線完成");
}

void loop()
{
  buttonstate = digitalRead(BTN);
  if(buttonstate==0&&lastButtonstate==1){
    Serial.println("==========");
    //設定溫濕度初始值
    byte temperature = 0;
    byte humidity = 0;
    int err = SimpleDHTErrSuccess;
    if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
      Serial.print("溫度計讀取失敗，錯誤碼="); Serial.println(err); delay(1000);
      return;
   }
    //讀取成功，將溫濕度顯示在序列視窗
    Serial.print("溫度計讀取成功: ");
    Serial.print((int)temperature); Serial.print(" *C, ");
    Serial.print((int)humidity); Serial.println("%H");
   //
    int ans=(int)temperature%10;
  //開始傳送到thingspeak
  Serial.println("啟動網頁連線");
  HTTPClient http;
  //將溫度及濕度以http get參數方式補入網址後方
  String url1 = url + "&field1=" + (int)temperature + "&field2=" + (int)humidity;
  //http client取得網頁內容
  http.begin(url1);
  int httpCode = http.GET();
  if (httpCode == HTTP_CODE_OK)      {
    //讀取網頁內容到payload
    String payload = http.getString();
    //將內容顯示出來
    Serial.print("網頁內容=");
    Serial.println(payload);
  } else {
    //讀取失敗
    Serial.println("網路傳送失敗");
  }
  http.end();
  if(ans==0){n1();}
  else if(ans==1){n1();}
  else if(ans==2){n2();}
  else if(ans==3){n3();}
  else if(ans==4){n4();}
  else if(ans==5){n5();}
  else if(ans==6){n6();}
  else if(ans==7){n7();}
  else if(ans==8){n8();}
  else if(ans==9){n9();}
  //
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
//
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
void dot () {digitalWrite(RED,HIGH); tone(RED, 500); delay (100); digitalWrite(RED,LOW); noTone(RED); delay (200);}
void dash () {digitalWrite(RED,HIGH); tone(RED, 500); delay (300); digitalWrite(RED,LOW); noTone(RED); delay (200);}