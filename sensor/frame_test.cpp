#include <ArduinoUnit.h>

#include "frame.h"

test(frame_constructor) {
  Frame frame = Frame(42, 43, 44, 45);
  
  assertEqual(frame.up(), 42);
  assertEqual(frame.right(), 43);
  assertEqual(frame.bottom(), 44);
  assertEqual(frame.left(), 45);
}

test(frame_toString) {
  Frame frame = Frame(42, 43, 44, 45);
  
  assertEqual(frame.toString(), String("2a,2b,2c,2d;"));
}

test(frame_minus_frame_will_return_value) {
  Frame frame1 = Frame(42, 43, 44, 45);
  Frame frame2 = Frame(42, 43, 44, 45);
  
  assertEqual(frame1 - frame2, 0);
}

