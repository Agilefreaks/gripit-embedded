#include <Arduino.h>

#include "collector.h"
#include "frame.h"

Collector::~Collector() {
  delete(buffer_);
  delete(lastFrame_);
  delete(currentFrame_);
}

void Collector::collect(Frame *frame) {
  buffer_->pushFront(frame);

  int sumTop = 0, sumRight = 0, sumBottom = 0, sumLeft = 0;
  Node<Frame> *root = buffer_->root();
  while (root != NULL) {
    sumTop += root->value->up();
    sumRight += root->value->right();
    sumBottom += root->value->bottom();
    sumLeft += root->value->left();
    root = root->next;
  }

  int bufferSize = buffer_->size();
  
  currentFrame_->set(sumTop / bufferSize, sumRight / bufferSize, sumBottom / bufferSize, sumLeft / bufferSize);
};

String Collector::exportFrame() {
  lastFrame_->set(currentFrame_->up(), currentFrame_->right(), currentFrame_->bottom(), currentFrame_->left());
  
  return String(String(id_, HEX) + ":" + currentFrame_->toString());
};

boolean Collector::hasFrame() {
  return (currentFrame_->diff(*lastFrame_) > THRESHOLD) && buffer_->isFull();
}
