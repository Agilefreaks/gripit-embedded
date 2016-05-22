#include "frame.h"

String Frame::toString() {
  return String(String(up(), HEX) + "," + String(right(), HEX) + "," + String(bottom(), HEX) + "," + String(left(), HEX) + ";");
}

int Frame::operator-(const Frame& frame) {
  return 0;
}
