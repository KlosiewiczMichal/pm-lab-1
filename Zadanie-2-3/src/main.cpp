#include <Arduino.h>

#define CAR_RED 12
#define CAR_YELLOW 11
#define CAR_GREEN 10
#define PED_RED 9
#define PED_GREEN 8

#define PED_BUTTON 2

#define CHANGE_TIME 10000
#define STATE_1_TIME 10000
#define STATE_2_TIME 1000
#define STATE_3_TIME 7000
#define STATE_4_TIME 1000

enum LightState_t{ GREEN, YELLOW, YELLOW_RED, RED};
LightState_t lightState = GREEN; // Stan sygnalizatora
unsigned long changeTime = 0; // Czas ostatniej zmiany świateł

void setup() {
  pinMode(CAR_RED, OUTPUT);
  pinMode(CAR_YELLOW, OUTPUT);
  pinMode(CAR_GREEN, OUTPUT);
  pinMode(PED_RED, OUTPUT);
  pinMode(PED_GREEN, OUTPUT);
  pinMode(PED_BUTTON, INPUT);
  // Ustalenie początkowej wartości na wyjściach sterujących światła
  digitalWrite(CAR_RED, LOW);
  digitalWrite(CAR_YELLOW, LOW);
  digitalWrite(CAR_GREEN, HIGH);
  digitalWrite(PED_RED, HIGH);
  digitalWrite(PED_GREEN, LOW);
  changeTime = millis();
}

void loop() {
  uint8_t state = digitalRead(PED_BUTTON); //Odczyt stanu wejścia przycisku
  switch (lightState){
    case GREEN:
      digitalWrite(CAR_GREEN, HIGH);
      digitalWrite(CAR_YELLOW, LOW);
      digitalWrite(CAR_RED, LOW);
      digitalWrite(PED_RED, HIGH);
      digitalWrite(PED_GREEN, LOW);
      if(((millis() - changeTime) > STATE_1_TIME) || (state == HIGH)){
        lightState = YELLOW;
        changeTime = millis();
      }
    break;
  }
}