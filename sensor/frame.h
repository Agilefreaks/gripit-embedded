#ifndef FRAME_H
#define FRAME_H

#include <Arduino.h>

class Frame {
  const int up_, right_, bottom_, left_;
  
  public:
    Frame(int up, int right, int bottom, int left): up_(up), right_(right), bottom_(bottom), left_(left) {};

    String print();
    
    inline const int up() const { return up_; };
    inline const int right() const { return right_; };
    inline const int bottom() const { return bottom_; };
    inline const int left() const { return left_; };
};

#endif
