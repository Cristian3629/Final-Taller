#include <stdio.h>



float funcion_ejemplo(unsigned short a, int** b){
  printf("funcion_ejemplo\n");
  return 1.1;
}



int  main(int argc, char const *argv[]) {
  //aca declaro el puntero a la funcion
  float (*p)(unsigned short, int**);
  //aca lo inicializo
  p = &funcion_ejemplo;
  //preparo los punteros
  unsigned short  a = 5;
  int b = 5;
  int* c = &b;
  int** d = &c;
  p(a,d );
  return 0;
}
