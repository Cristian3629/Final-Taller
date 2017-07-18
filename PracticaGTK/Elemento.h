//
// Created by darius on 13/07/17.
//

#ifndef PRACTICA_GTK_ELEMENTO_H
#define PRACTICA_GTK_ELEMENTO_H

#include <algorithm>
#include <iostream>

//weas de operadores wn
class Elemento {
 private:
  int i = 5;
 public:

  Elemento(){}

  Elemento(int i) : i(i){}

  Elemento& operator=(const Elemento& elemento){
    if (this == &elemento){
      return *this;
    }
    this-> i = elemento.i;
    return *this;
  }

  Elemento( const Elemento& elemento){
    this->i = elemento.i;
  }

  Elemento& operator=(Elemento&& elemento){
    this->i = elemento.i;
    elemento.i = 0;
    return *this;
  }

  Elemento(Elemento&& elemento){
    this->i = elemento.i;
    elemento.i = 0;
  }

  friend std::ostream& operator<<(std::ostream& os, const Elemento& elemento){
    os << elemento.i;
    return os;
  }
};

int main(int argc, char * argv[]){
  Elemento e1(10);
  Elemento e3;
  Elemento e2 = std::move(e1);
  e3 = std::move(e2);

  std::cout << e1 << std::endl;
  std::cout << e2 << std::endl;
  std::cout << e3 << std::endl;

}

#endif //PRACTICA_GTK_ELEMENTO_H
