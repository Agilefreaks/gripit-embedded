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

test(frame_diff_frame_will_return_value) {
  Frame frame1 = Frame(42, 43, 44, 45);
  Frame frame2 = Frame(42, 43, 44, 45);
  
  assertEqual(frame1.diff(frame2), 0);
}

test(frame_diff_frame_will_return_average_value) {
  Frame frame1 = Frame(42, 43, 44, 45);
  Frame frame2 = Frame(43, 44, 45, 46);
  
  assertEqual(frame1.diff(frame2), 4);
}

test(frame_diff_frame_will_not_return_negative_average_value) {
  Frame frame1 = Frame(20, 0, 0, 0);
  Frame frame2 = Frame(130, 0, 0, 0);
  
  assertEqual(frame1.diff(frame2), 110);
}


