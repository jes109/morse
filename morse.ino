#include <BluetoothSerial.h> 
BluetoothSerial SerialBT;
//腳位設定
int BTN=19;
int LED_RED=16;
int LED_GREEN=17;
int LED_YELLOW=25;
int BUZZ=16;
int OVER=5;
//字母摩斯密碼
String a ="01";
String b ="1000";
String c ="1010";
String d ="100";
String e ="0";
String f ="0010";
String g ="110";
String h ="0000";
String i ="00";
String j ="0111";
String k ="101";
String l ="0100";
String m ="11";
String n ="10";
String o ="111";
String p ="0110";
String q ="1101";
String r ="010";
String s ="000";
String t ="1";
String u ="001";
String v ="0001";
String w ="011";
String x ="1001";
String y ="1011";
String z ="1100";
//
void setup() {
   pinMode(BTN,INPUT);
   pinMode(OVER,INPUT);
   pinMode(LED_RED,OUTPUT);
   pinMode(LED_YELLOW,OUTPUT);
   pinMode(LED_GREEN,OUTPUT);
   pinMode(BUZZ,OUTPUT);
   //
   Serial.begin(115200);
   Serial.println("hello");
   SerialBT.begin("ESP32_Morse");
}

void loop() {
  //輸入單字
  String text="0";
  while(text=="0"){
    if (SerialBT.available()) {
    text = SerialBT.readString();
    Serial.println(text);
  }
  delay(500);
  }
  //儲存單字長度
  int Length=text.length();//單字長度
  bool check;//確認正確與否
  int count=0;//計算輸入到第幾個摩斯密碼
  int flag=false;//確認是否完全輸入正確
  //先播放
  for(int k=0;k<Length;k++){
    if (text[k] == 'a' || text[k] == 'A') {mA();}
    else if (text[k] == 'b' || text[k] == 'B') {mB();}
    else if (text[k] == 'c' || text[k] == 'C') {mC();}
    else if (text[k] == 'd' || text[k] == 'D') {mD();}
    else if (text[k] == 'e' || text[k] == 'E') {mE();}
    else if (text[k] == 'f' || text[k] == 'F') {mF();}
    else if (text[k] == 'g' || text[k] == 'G') {mG();}
    else if (text[k] == 'h' || text[k] == 'H') {mH();}
    else if (text[k] == 'i' || text[k] == 'I') {mI();}
    else if (text[k] == 'j' || text[k] == 'J') {mJ();}
    else if (text[k] == 'k' || text[k] == 'K') {mK();}
    else if (text[k] == 'l' || text[k] == 'L') {mL();}
    else if (text[k] == 'm' || text[k] == 'M') {mM();}
    else if (text[k] == 'n' || text[k] == 'N') {mN();}
    else if (text[k] == 'o' || text[k] == 'O') {mO();}
    else if (text[k] == 'p' || text[k] == 'P') {mP();}
    else if (text[k] == 'q' || text[k] == 'Q') {mQ();}
    else if (text[k] == 'r' || text[k] == 'R') {mR();}
    else if (text[k] == 's' || text[k] == 'S') {mS();}
    else if (text[k] == 't' || text[k] == 'T') {mT();}
    else if (text[k] == 'u' || text[k] == 'U') {mU();}
    else if (text[k] == 'v' || text[k] == 'V') {mV();}
    else if (text[k] == 'w' || text[k] == 'W') {mW();}
    else if (text[k] == 'x' || text[k] == 'X') {mX();}
    else if (text[k] == 'y' || text[k] == 'Y') {mY();}
    else if (text[k] == 'z' || text[k] == 'Z') {mZ();}
  }
  //一個一個按按鈕輸入摩斯密碼
  while(flag!=true){
    Serial.println("開始迴圈"); 
    check=Morse(text[count]);
    if(check==true && count==Length-1){
        digitalWrite(LED_GREEN,HIGH);delay(1000);
        count++;
        flag=true;
        Serial.println("恭喜答對");
      }  
    else if(check==true){
        digitalWrite(LED_YELLOW,HIGH);delay(1000);
        Serial.println("下一碼");
        count++;
      }  
    else{
        digitalWrite(LED_RED,HIGH);delay(1000);
        Serial.println("不對欸");
        count=0;
      } 
      Serial.println("一次迴圈"); 
  }
  //顯示溫度
}
//
bool Morse(char word){
  Serial.println("進入morse"); 
  String ans;//對應字母
  if (word == 'a' || word == 'A') {ans=a;}
  else if (word == 'b' || word == 'B') {ans=b;}
  else if (word == 'c' || word == 'C') {ans=c;}
  else if (word == 'd' || word == 'D') {ans=d;}
  else if (word == 'e' || word == 'E') {ans=e;}
  else if (word == 'f' || word == 'F') {ans=f;}
  else if (word == 'g' || word == 'G') {ans=g;}
  else if (word == 'h' || word == 'H') {ans=h;}
  else if (word == 'i' || word == 'I') {ans=i;}
  else if (word == 'j' || word == 'J') {ans=j;}
  else if (word == 'k' || word == 'K') {ans=k;}
  else if (word == 'l' || word == 'L') {ans=l;}
  else if (word == 'm' || word == 'M') {ans=m;}
  else if (word == 'n' || word == 'N') {ans=n;}
  else if (word == 'o' || word == 'O') {ans=o;}
  else if (word == 'p' || word == 'P') {ans=p;}
  else if (word == 'q' || word == 'Q') {ans=q;}
  else if (word == 'r' || word == 'R') {ans=r;}
  else if (word == 's' || word == 'S') {ans=s;}
  else if (word == 't' || word == 'T') {ans=t;}
  else if (word == 'u' || word == 'U') {ans=u;}
  else if (word == 'v' || word == 'V') {ans=v;}
  else if (word == 'w' || word == 'W') {ans=w;}
  else if (word == 'x' || word == 'X') {ans=x;}
  else if (word == 'y' || word == 'Y') {ans=y;}
  else if (word == 'z' || word == 'Z') {ans=z;}
  Serial.println(ans);
  int interval=500;//長短分隔時間
  int currentstate=0;//目前按鈕狀態
  int currentState=0;
  int previousstate=0;//之前按鈕狀態
  int previousState=0;
  unsigned long currenttime=0;//目前按鈕時間
  unsigned long previoustime=0;//之前按鈕時間
  bool fin=false;//輸入持續確認
  unsigned long pressDuration;//案的時長
  String input;//輸入的密碼
  int over=0;//完成輸入
  while(fin!=true){
    Serial.println("morse迴圈開始"); 
  //
    currentstate = digitalRead(BTN);  
    currentState = digitalRead(OVER); 
    if (currentstate != previousstate) {        
      if (currentstate == HIGH){
        previoustime=millis();
      }
      else{
        currenttime = millis();  // 記錄目前時間
        pressDuration = currenttime - previoustime;
        //
        if (pressDuration >= interval) {
          Serial.print("-");
          dash();
          input+='1';
         Serial.print(input);
        } 
        else {
         Serial.print(".");
         dot();
          input+='0';
          Serial.println(input);
        }
      }
    }
    if(currentState==0&&previousState==1){
      Serial.println("結束");
      fin=true;
    }
    Serial.println("morse迴圈結束"); 
  }
  if(input==ans){
    return(true);
  }
  else{
    return(false);
  }
}
//
void mA () {dot();dash();shortspace();}
void mB () {dash();dot();dot();dot();shortspace();}
void mC () {dash();dot();dash();dot();shortspace();}
void mD () {dash();dot();dot();shortspace();}
void mE () {dot();shortspace();}
void mF () {dot();dot();dash();dot();shortspace();}
void mG () {dash();dash();dot();shortspace();}
void mH () {dot();dot();dot();dot();shortspace();}
void mI () {dot();dot();shortspace();}
void mJ () {dot();dash();dash();dash();shortspace();}
void mK () {dash();dot();dash();shortspace();}
void mL () {dot();dash();dot();dot();shortspace();}
void mM () {dash();dash();shortspace();}
void mN () {dash();dot();shortspace();}
void mO () {dash();dash();dash();shortspace();}
void mP () {dot();dash();dash();dot();shortspace();}
void mQ () {dash();dash();dot();dash();shortspace();}
void mR () {dot();dash();dot();shortspace();}
void mS () {dot();dot();dot();shortspace();}
void mT () {dash();shortspace();}
void mU () {dot();dot();dash();shortspace();}
void mV () {dot();dot();dot();dash();shortspace();}
void mW () {dot();dash();dash();shortspace();}
void mX () {dash();dot();dot();dash();shortspace();}
void mY () {dash();dot();dash();dash();shortspace();}
void mZ () {dash();dash();dot();dot();shortspace();}
void dot () {digitalWrite(LED_YELLOW,HIGH); delay (100); digitalWrite(LED_YELLOW,LOW); delay (200);}//改
void dash () {digitalWrite(LED_YELLOW,HIGH); delay (300); digitalWrite(LED_YELLOW,LOW); delay (200);}//改
void shortspace () {delay(600);}