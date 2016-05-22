#include "frame.h"

String Frame::toString() {
  return String(String(up(), HEX) + "," + String(right(), HEX) + "," + String(bottom(), HEX) + "," + String(left(), HEX) + ";");
}

int Frame::diff(const Frame& frame) {
  int up = abs(this->up() - frame.up());
  int right = abs(this->right() - frame.right());
  int bottom = abs(this->bottom() - frame.bottom());
  int left = abs(this->left() - frame.left());
  
  return up + right + bottom + left;
}

void Frame::set(int up, int right, int bottom, int left) {
  up_ = up;
  right_ = right;
  bottom_ = bottom;
  left_ = left;
}
