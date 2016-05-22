#ifndef COLLECTOR_H
#define COLLECTOR_H

#include <Arduino.h>

#include "frame.h"
#include "linked_list.h"

class Collector {
  const int id_;
  const int filter_ = 10;
  
  Frame *result_frame_;
  LinkedList<Frame>* linkedList_;
  
  public:
    static const int THRESHOLD = 30;

    Collector(int id): id_(id), filter_(10) {
      linkedList_ = new LinkedList<Frame>(filter_);
    };
    Collector(int id, int filter): id_(id), filter_(filter) {
      linkedList_ = new LinkedList<Frame>(filter_);
    };
    
    void collect(Frame *frame);
    String print();
};

#endif

