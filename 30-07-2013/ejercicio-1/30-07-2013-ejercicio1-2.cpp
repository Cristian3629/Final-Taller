#include <stdio.h>


//2. La declaración de un puntero a una función que toma como parámetros unentero corto
//sin signo y un puntero a puntero a entero y devuelve un número de punto flotante.

float funcion_ejemplo(unsigned short a, int** b){
  printf("funcion_ejemplo\n");
  return 1.1;
}

int  maina(int argc, char const *argv[]) {
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
