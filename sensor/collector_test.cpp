#include <ArduinoUnit.h>

#include "collector.h"
#include "frame.h"

test(collector_print_will_return_the_average_of_last_filter_values) {
  Collector collector = Collector(42, 2);
  Frame frame1 = Frame(Collector::THRESHOLD + 1, 0, 0, 0);
  Frame frame2 = Frame(Collector::THRESHOLD + 10, 0, 0, 0);
  
  collector.collect(&frame1);
  collector.collect(&frame2);
  
  assertEqual(collector.print(), String("2a:23,0,0,0;"));
}

test(collector_print_with_frame_to_export_will_return_correct_string) {
  Collector collector = Collector(42);
  Frame frame1 = Frame(Collector::THRESHOLD + 1, 0, 0, 0);
  
  collector.collect(&frame1);
  
  assertEqual(collector.print(), String("2a:1f,0,0,0;"));
}
