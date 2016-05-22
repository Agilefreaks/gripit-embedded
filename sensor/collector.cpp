#include <Arduino.h>

#include "collector.h"
#include "frame.h"

void Collector::collect(Frame *frame) {
  last_frame_ = frame;
};

String Collector::print() {
  return String(String(id_, HEX) + ":" + last_frame_->print());
};
