#ifndef STACK_H
#define STACK_H

#include <mutex>

class Stack{
  int array[1000];
  int size;
  int capacity;
  std::mutex m;

public:
  Stack(){
    size = 0;
    capacity = 1000;
  }

  void push(int i){
    m.lock();
    array[size] = i
    size++;
    m.unlock();
  }

  int pop(){
    m.lock();
    int num = array[size];
    size--;
    m.unlock();
    return num;
  }
}
