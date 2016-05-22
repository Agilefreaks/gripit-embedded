#include <ArduinoUnit.h>
#include <MsTimer2.h>

#include "frame.h"
#include "input.h"
#include "collector.h"

Input* input;
Collector* collector;

void setup() {
  Serial.begin(9600);

  input = new Input();
  collector = new Collector(42);
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
  collector->collect(&frame);
  
  Serial.println(collector->exportFrame());

  delay(100);
}

