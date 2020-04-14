#include <Arduino.h>

#define H HIGH
#define L LOW

const int LEDpin = 8;
const byte interruptPin = 2;//2番ピンの割り込み0を使う
volatile int flag= LOW;

void outputLED() {
  for(int i = LEDpin;i < LEDpin + 6;i++){
  digitalWrite(i, flag);
  }
}
void turnoff() {
    flag= !flag;
}

void setup() {
  //割り込みSWの設定
  pinMode(interruptPin, INPUT_PULLUP);
  pinMode(LEDpin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), turnoff, RISING);
  //LEDピンの設定
  pinMode(LEDpin, OUTPUT);
  for(int i = LEDpin ;i < LEDpin + 6;i++){
  pinMode(i,OUTPUT);
  }
}
void loop() {
  outputLED();
}

