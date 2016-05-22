#ifndef INPUT_H
#define INPUT_H

#include <Arduino.h>

#include "frame.h"

class Input {
  const int fsr_a0 = A0;
  const int fsr_a1 = A1;
  const int fsr_a2 = A2;
  const int fsr_a3 = A3;

  public:
    Frame read();
};

#endif
