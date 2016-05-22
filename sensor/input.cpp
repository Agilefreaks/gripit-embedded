#include "input.h"
#include "frame.h"

Frame Input::read() {
  int val1 = analogRead(fsr_a0);
  int val2 = analogRead(fsr_a1);
  int val3 = analogRead(fsr_a2);
  int val4 = analogRead(fsr_a3);
  
  return Frame(val1, val2, val3, val4);
}
