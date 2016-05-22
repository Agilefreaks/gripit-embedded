#include <ArduinoUnit.h>
#include "frame.h"

test(frame_constructor) {
  Frame frame = Frame(42, 43, 44, 45);
  
  assertEqual(frame.up(), 42);
  assertEqual(frame.right(), 43);
  assertEqual(frame.bottom(), 44);
  assertEqual(frame.left(), 45);
}

test(frame_print) {
  Frame frame = Frame(42, 43, 44, 45);
  
  assertEqual(frame.print(), String("2a,2b,2c,2d;"));
}

