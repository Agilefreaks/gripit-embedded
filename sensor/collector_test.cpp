#include <ArduinoUnit.h>

#include "collector.h"
#include "frame.h"

test(collector_read) {
  Collector collector = Collector(42);
  
  Frame frame1 = Frame(0, 0, 0, 0);
  
  collector.collect(&frame1);
}

test(collector_print_with_frame_to_export_will_return_correct_string) {
  Collector collector = Collector(42);
  Frame frame1 = Frame(Collector::THRESHOLD + 1, 0, 0, 0);
  
  collector.collect(&frame1);
  
  assertEqual(collector.print(), String("2a:1f,0,0,0;"));
}
