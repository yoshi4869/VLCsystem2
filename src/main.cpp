#include <Arduino.h>

#define H HIGH
#define L LOW
#define INTERVAL 3000 //点灯間隔

const int LEDpin = 8;
//{0 1}={00100 01110}の２値で明暗を表現


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


//pwm0とpwm1でデータを作る
void data(int led, float t){
  pwm0(led,t);
  pwm0(led,t);
  pwm0(led,t);
  pwm0(led,t);
  pwm0(led,t);
}
//1つのLEDで出力する
void outputLED() {
  data(LEDpin, INTERVAL);
}

void setup() {
  //LEDピンの設定
  pinMode(LEDpin, OUTPUT);
  pinMode(LEDpin,OUTPUT);
}
void loop() {
  outputLED();
}

