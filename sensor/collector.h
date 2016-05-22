#ifndef COLLECTOR_H
#define COLLECTOR_H

#include <Arduino.h>

#include "frame.h"

class Collector {
  const int id_;
  
  Frame *last_frame_;
  
  public:
    static const int THRESHOLD = 30;

    Collector(int id): id_(id) {};
    
    void collect(Frame *frame);
    String print();
};

#endif

