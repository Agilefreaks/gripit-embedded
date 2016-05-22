#ifndef FRAME_H
#define FRAME_H

#include <Arduino.h>

class Frame {
  int up_ = 0, right_ = 0, bottom_ = 0, left_ = 0;
  
  public:
    Frame() {};
    Frame(int up, int right, int bottom, int left): up_(up), right_(right), bottom_(bottom), left_(left) {};
    
    inline const int up() const { return up_; };
    inline const int right() const { return right_; };
    inline const int bottom() const { return bottom_; };
    inline const int left() const { return left_; };
    
    String toString();
    int diff(const Frame& frame);
    void set(int up, int right, int bottom, int left);
};

#endif
