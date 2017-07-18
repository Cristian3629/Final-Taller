#include <queue>
#include <cstdlib>
#include <cstdio>
#include "email.h"
#include "_Email.h"

static char * suma(int a, int b){
  int result = a+b;
  char * r = (char*)malloc(10*sizeof(char));
  snprintf(r,10,"%d",result);
  return r;
}
int main(int argc, char const *argv[]) {
//  Email email("cristian3629@gmail.com");
//  std::cout << email;
//
//  std::cout << "Ingrese el nuevo email:" << std::endl;
//  std::cin >> email;
//  std::cout << "El nuevo email es:";
//  std::cout << email;

//  _Email email("hola@gmail.com");
//  _Email email2("quetal@gmail.com");
//  email = email2;
//
//  std::cout << email;

  std::queue<int> cola;

//  char * (*p)(int, int) = suma;
//  char * a = p(5,5);
//  std::cout << a;
//  free(a);
//

  int a = 5;
  int *pInt = &a;
  int** ppInt = &(pInt);
  return 0;
}
