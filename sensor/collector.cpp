#include <Arduino.h>

#include "collector.h"
#include "frame.h"

void Collector::collect(Frame *frame) {
  linkedList_->pushFront(frame);
  
  int sumTop = 0, sumRight = 0, sumBottom = 0, sumLeft = 0;
  Node<Frame> *root = linkedList_->root();
  while(root != NULL) {
    sumTop += root->value->up();
    root = root->next;
  }

  result_frame_ = new Frame(sumTop / linkedList_->size(), 0, 0, 0);
};

String Collector::print() {
  return String(String(id_, HEX) + ":" + result_frame_->print());
};
