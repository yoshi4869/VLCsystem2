#include <Arduino.h>

#define H HIGH
#define L LOW
#define INTERVAL 20 //点灯間隔

const int LEDpin = 8;
const byte interruptPin = 2;//2番ピンの割り込み0を使う
volatile int flag= LOW;
//{0 1}={00100 01110}の２値で明暗を表現

void turnoff() {
    flag= !flag;
}

void pwm0(int led,float t){//00100=LLHLL
  digitalWrite(led,L);
  delayMicroseconds(t);
  digitalWrite(led,L);
  delayMicroseconds(t);
  digitalWrite(led,H);
  delayMicroseconds(t);
  digitalWrite(led,L);
  delayMicroseconds(t);
  digitalWrite(led,L);
  delayMicroseconds(t);
}
void pwm1(int led,float t){//01110=LHHHL
  digitalWrite(led,L);
  delayMicroseconds(t);
  digitalWrite(led,H);
  delayMicroseconds(t);
  digitalWrite(led,H);
  delayMicroseconds(t);
  digitalWrite(led,H);
  delayMicroseconds(t);
  digitalWrite(led,L);
  delayMicroseconds(t);
}

//データ部分の抽出に必要
void head(int led,float t){//11111=HHHHH
  digitalWrite(led,H);
  delayMicroseconds(t);
  digitalWrite(led,H);
  delayMicroseconds(t);
  digitalWrite(led,H);
  delayMicroseconds(t);
  digitalWrite(led,H);
  delayMicroseconds(t);
  digitalWrite(led,H);
  delayMicroseconds(t);
}

//pwm0とpwm1でデータを作る
void data(int led, float t){
  //head(led,t);
  pwm1(led,t);
  pwm0(led,t);
  pwm0(led,t);
  pwm1(led,t);
  pwm0(led,t);
  //head(led,t);
}
//6つのLEDで出力する
void outputLED() {
  for(int i = LEDpin;i < LEDpin + 6;i++){
  data(i, INTERVAL);
  }
}
//6つのLEDの出力を止める
void turnOff() {
  for(int i = LEDpin;i < LEDpin + 6;i++){
  digitalWrite(i, L);
  }
}

void setup() {
  //割り込みSWの設定
  pinMode(interruptPin, INPUT_PULLUP);
  pinMode(LEDpin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), outputLED, LOW);
  //LEDピンの設定
  pinMode(LEDpin, OUTPUT);
  for(int i = LEDpin ;i < LEDpin + 6;i++){
  pinMode(i,OUTPUT);
  }
}
void loop() {
  //turnOff();
}

