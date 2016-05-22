#ifndef COLLECTOR_H
#define COLLECTOR_H

#include <Arduino.h>

#include "frame.h"
#include "linked_list.h"

class Collector {
  const int id_;
  const int filter_ = 10;
  
  Frame *currentFrame_;
  Frame *lastFrame_;
  LinkedList<Frame>* buffer_;
  
  public:
    static const int THRESHOLD = 30;

    Collector(int id): id_(id), filter_(10) {
      buffer_ = new LinkedList<Frame>(filter_);
    };
    Collector(int id, int filter): id_(id), filter_(filter) {
      buffer_ = new LinkedList<Frame>(filter_);
    };
    
    void collect(Frame *frame);
    String exportFrame();
    boolean hasFrame();
};

#endif

