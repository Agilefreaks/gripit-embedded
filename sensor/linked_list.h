#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template<class T> 
struct Node {
  T *value;
  Node<T> *next;
};

template<class T> 
class LinkedList {
  const int size_;
  
  int currentSize_;
  Node<T> *root_ = NULL;
  
  public:
    LinkedList(int size): size_(size), currentSize_(0) {};
    
    inline Node<T>* root() { return root_; };
    inline int size() { return currentSize_; }
    
    void pushFront(T *value) {
      Node<T>* newNode = createNode(value);
      newNode->next = root_;
      root_ = newNode;
      
      if (isFull()) {
        removeLast();
      }
      else {
        currentSize_++;
      }
    };
    
    void removeLast() {
      Node<T> *last = root();
      Node<T> *beforeLast;
      
      while(last->next != NULL) {
        beforeLast = last;
        last = last->next;
      }
      
      beforeLast->next = NULL;
      delete last;
    }
    
    boolean isFull() {
      return size_ == currentSize_;
    }

  private:
    
    Node<T>* createNode(T *value) {
      Node<T>* node = (Node<T>*)malloc(sizeof(Node<T>));
      node->value = value;
      node->next = NULL;
      
      return node;
    }
};

#endif

