#include <stdio.h>

void funcion_con_argumentos_opcionales(int a, int b = 0){
  printf("a+b=%d\n", a+b);
}


int main(int argc, char const *argv[]) {
  funcion_con_argumentos_opcionales(10);
  funcion_con_argumentos_opcionales(10,20);
  return 0;
}
