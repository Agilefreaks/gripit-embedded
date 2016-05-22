#include <ArduinoUnit.h>

#include "linked_list.h"

test(linked_list_push_front_when_root_is_null_will_replace_root) {
  LinkedList<int> list(2);
  int value = 42;
  
  list.pushFront(&value);
  
  assertEqual(*list.root()->value, 42);
  assertTrue(list.root()->next == NULL);
}

test(linked_list_push_front_when_root_in_not_null_will_add_element_to_front) {
  LinkedList<int> list(2);
  int value1 = 42;
  int value2 = 43;
  
  list.pushFront(&value1);
  list.pushFront(&value2);
  
  assertEqual(*list.root()->value, 43);
  assertEqual(*list.root()->next->value, 42);
  assertTrue(list.root()->next->next == NULL);
}

test(linked_list_push_front_when_more_then_size_will_drop_end) {
  LinkedList<int> list(2);
  int value1 = 42;
  int value2 = 43;
  int value3 = 44;
  
  list.pushFront(&value1);
  list.pushFront(&value2);
  list.pushFront(&value3);
  
  assertEqual(*list.root()->value, 44);
  assertEqual(*list.root()->next->value, 43);
  assertTrue(list.root()->next->next == NULL);
}

test(linked_list_push_front_will_update_size) {
  LinkedList<int> list(2);
  int value1 = 42;
  int value2 = 43;
  int value3 = 44;
  
  list.pushFront(&value1);
  list.pushFront(&value2);
  list.pushFront(&value3);
  
  assertEqual(list.size(), 2);
}
