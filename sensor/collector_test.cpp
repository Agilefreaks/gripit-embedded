#include <ArduinoUnit.h>

#include "collector.h"
#include "frame.h"

test(collector_exportFrame_will_return_the_average_of_last_filter_values) {
  Collector collector = Collector(42, 2);
  Frame frame1 = Frame(Collector::THRESHOLD + 1, Collector::THRESHOLD + 1, Collector::THRESHOLD + 1, Collector::THRESHOLD + 1);
  Frame frame2 = Frame(Collector::THRESHOLD + 10, Collector::THRESHOLD + 11, Collector::THRESHOLD + 12, Collector::THRESHOLD + 13);
  
  collector.collect(&frame1);
  collector.collect(&frame2);
  
  assertEqual(collector.exportFrame(), String("2a:23,24,24,25;"));
}

test(collector_exportFrame_with_frame_to_export_will_return_correct_string) {
  Collector collector = Collector(42, 1);
  Frame frame1 = Frame(Collector::THRESHOLD + 1, 0, 0, 0);
  
  collector.collect(&frame1);
  
  assertEqual(collector.exportFrame(), String("2a:1f,0,0,0;"));
}

test(collector_hasFrame_with_buffer_not_full_will_return_false) {
  Collector collector = Collector(42, 2);
  Frame frame1 = Frame(Collector::THRESHOLD + 1, 0, 0, 0);
  
  collector.collect(&frame1);
  
  assertFalse(collector.hasFrame());   
}

test(collector_hasFrame_with_buffer_full_will_return_true) {
  Collector collector = Collector(42, 2);
  Frame frame1 = Frame(Collector::THRESHOLD + 1, 0, 0, 0);
  Frame frame2 = Frame(Collector::THRESHOLD + 1, 0, 0, 0);
  
  collector.collect(&frame1);
  collector.collect(&frame2);
  
  assertTrue(collector.hasFrame());   
}

test(collector_hasFrame_when_new_frame_does_not_pass_threshold_will_return_false) {
  Collector collector = Collector(42, 2);
  Frame frame1 = Frame(Collector::THRESHOLD + 1, 0, 0, 0);
  Frame frame2 = Frame(Collector::THRESHOLD + 1, 0, 0, 0);
  
  collector.collect(&frame1);
  collector.collect(&frame2);
  
  collector.exportFrame();

  Frame frame3 = Frame(Collector::THRESHOLD - 1, 0, 0, 0);
  Frame frame4 = Frame(Collector::THRESHOLD - 1, 0, 0, 0);

  collector.collect(&frame3);
  collector.collect(&frame4);
  
  assertFalse(collector.hasFrame());   
}

