#include <ArduinoUnit.h>
#include <MsTimer2.h>

#include "frame.h"
#include "sensor.h"
#include "input.h"

Input* input;

void setup() {
  Serial.begin(9600);

  input = new Input();
}

void loop() {
  testLoop();
  //mainLoop();
}

void testLoop() {
  Test::run();
}

void mainLoop() {
  Frame frame = input->read();

  Serial.println(frame.print());

  delay(100);
}
