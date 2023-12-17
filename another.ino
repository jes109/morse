#include <WiFi.h>
#include <HTTPClient.h>
#include <SimpleDHT.h>
//
const char ssid[]     = "1502"; //ssid:網路名稱
const char password[] = "ntuedorm"; //pasword：網路密碼
//
String url = "http://api.thingspeak.com/update?api_key=R1H2QFMF34U13LNI";
int pinDHT11 = 4;//假設DHT11接在腳位GPIO15，麵包板右側序號4
//---------------------------------------------------------
SimpleDHT11 dht11(pinDHT11);//宣告SimpleDHT11物件
int a=7;//定義數位接口7 連接a 七段顯示器
int b=6;// 定義數位接口6 連接b 七段顯示器
int c=5;// 定義數位接口5 連接c 七段顯示器
int d=11;// 定義數位接口11 連接d 七段顯示器
int e=10;// 定義數位接口10 連接e 七段顯示器
int f=8;// 定義數位接口8 連接f 七段顯示器
int g=9;// 定義數位接口9 連接g 七段顯示器
int dp=4;// 定義數位接口4 連接dp 七段顯示器
int BTN=5;//按鈕
//
int buttonState = 0;      // 儲存按鈕狀態
int lastButtonState = 0;  // 儲存前一次的按鈕狀態
//
void digital_1(void) //顯示數字1
{
  unsigned char j;
  digitalWrite(c,HIGH);//给數位接口5高電位，點亮c段
  digitalWrite(b,HIGH);//點亮b段
  for(j=7;j<=11;j++)//熄滅其余段
    digitalWrite(j,LOW);
  
  digitalWrite(dp,LOW);//熄滅小數點DP段
}
void digital_2(void) //顯示數字2
{
  unsigned char j;
  digitalWrite(b,HIGH);
  digitalWrite(a,HIGH);
  for(j=9;j<=11;j++)
    digitalWrite(j,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(c,LOW);
  digitalWrite(f,LOW);
}
void digital_3(void) //顯示數字3
{
  unsigned char j;
  digitalWrite(g,HIGH);
  digitalWrite(d,HIGH);
  for(j=5;j<=7;j++)
    digitalWrite(j,HIGH);
  
  digitalWrite(dp,LOW);
  digitalWrite(f,LOW);
  digitalWrite(e,LOW);
}
void digital_4(void) //顯示數字4
{
  digitalWrite(c,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(a,LOW);
  digitalWrite(e,LOW);
  digitalWrite(d,LOW);
}
void digital_5(void) //顯示數字5
{
  unsigned char j;
  for(j=7;j<=9;j++)
    digitalWrite(j,HIGH);
  
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(b,LOW);
  digitalWrite(e,LOW);
}
void digital_6(void) //顯示數字6
{
  unsigned char j;
  for(j=7;j<=11;j++)
    digitalWrite(j,HIGH);

  digitalWrite(c,HIGH);
  digitalWrite(dp,LOW);
  digitalWrite(b,LOW);
}
void digital_7(void) //顯示數字7
{
  unsigned char j;
  for(j=5;j<=7;j++)
    digitalWrite(j,HIGH);
  digitalWrite(dp,LOW);
  for(j=8;j<=11;j++)
    digitalWrite(j,LOW);
}
void digital_8(void) //顯示數字8
{
  unsigned char j;
  for(j=5;j<=11;j++)
    digitalWrite(j,HIGH);
  digitalWrite(dp,LOW);
}
void setup() {
  pinMode(BTN,INPUT);
  // put your setup code here, to run once:
  int i;//定义变量
  for(i=4;i<=11;i++)
    pinMode(i,OUTPUT);//設置4～11 引脚為輸出模式
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
  Serial.begin(115200);
  Serial.println("hello");
  SerialBT.begin("ESP32_Morse");
}

void loop() {
  buttonState = digitalRead(BTN);
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
  int ans=(int)temperature%10;
  char n;
  if(ans==1){n1();n='1';}
  else if(ans==2){n2();n='2';}
  else if(ans==3){n3();n='3';}
  else if(ans==4){n4();n='4';}
  else if(ans==5){n5();n='5';}
  else if(ans==6){n6();n='6';}
  else if(ans==7){n7();n='7';}
  else if(ans==8){n8();n='8';}
  else if(ans==9){n9();n='9';}
  \\
  bool flag=false;
  while(flag!=true){
    char text='n';
    while(text=="n"){
     if (SerialBT.available()) {
     text = SerialBT.read();
     Serial.println(text);
    }
   }
   if(text==n){
      digitalWrite(LED_GREEN,HIGH);delay(1000);
      digitalWrite(LED_GREEN,LOW);delay(1000);
      flag=true;
    }
    else{
      digitalWrite(LED_RED,HIGH);delay(1000);
      digitalWrite(LED_RED,LOW);delay(1000);
    }
  }
  if(ans==1==1){digital_1();}
  else if(ans==2){digital_2();}
  else if(ans==3){digital_3();}
  else if(ans==4){digital_4();}
  else if(ans==5){digital_5();}
  else if(ans==6){digital_6();}
  else if(ans==7){digital_7();}
  else if(ans==8){digital_8();}
  else if(ans==9){digital_9();}
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
  delay(30000);//休息30秒
  }
}
//
void n1 () {dot();dash();dash();dash();dash();shortspace();}//number 1 in morse code
void n2 () {dot();dot();dash();dash();dash();shortspace();}
void n3 () {dot();dot();dot();dash();dash();shortspace();}
void n4 () {dot();dot();dot();dot();dash();shortspace();}
void n5 () {dot();dot();dot();dot();dot();shortspace();}
void n6 () {dash();dot();dot();dot();dot();shortspace();}
void n7 () {dash();dash();dot();dot();dot();shortspace();}
void n8 () {dash();dash();dash();dot();dot();shortspace();}
void n9 () {dash();dash();dash();dash();dot();shortspace();}
void n0 () {dash();dash();dash();dash();dash();shortspace();}
void dot () {digitalWrite(led,HIGH); tone(buzzer, 500); delay (100); digitalWrite(led,LOW); noTone(buzzer); delay (200);}//改
void dash () {digitalWrite(led2,HIGH); tone(buzzer, 500); delay (300); digitalWrite(led2,LOW); noTone(buzzer); delay (200);}//改
void shortspace () {delay(600);}//改
