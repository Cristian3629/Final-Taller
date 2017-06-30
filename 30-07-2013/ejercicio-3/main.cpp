#include "stack.h"
#include <thread>
#include <iostream>       // std::cout

Stack stack;

int push(int i){
  stack.push(i);
}

int pop(int i){
  stack.pop();
}

int main(int argc, char const *argv[]) {
  std::thread threads[20];

  for (size_t i = 0; i < 20; i++) {
    if (i % 2 == 0){
      threads[i] = std::thread(push,i);
    }else{
      threads[i] = std::thread(pop,i);
    }
  }


  for (size_t i = 0; i < 20; i++) {
    (threads[i]).join();
  }


  for (size_t i = 0; i < 10; i++) {
    std::cout << "El numero que saque es :" << stack.pop() << std::endl;
  }
  return 0;
}
