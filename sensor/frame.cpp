#include "frame.h"

String Frame::print() {
  return String(String(up(), HEX) + "," + String(right(), HEX) + "," + String(bottom(), HEX) + "," + String(left(), HEX) + ";");
}
