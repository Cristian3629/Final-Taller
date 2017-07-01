//Escriba una aplicación C que lea de la línea de comandos un número y l
//o imprima en todas las bases entre 2 y 16.
#include <stdio.h>
int divide_by_base(int number, int base) {
  int coef = (number / base);
  int resto = number - coef*base;
  if (coef != 0){
    divide_by_base(coef,base);
  }
  printf("%d",resto);
}

int main(int argc, char *argv[]) {
  int number = 45;
  int base = 2;
  while (base <= 16){
    divide_by_base(number,base);
    base++;
    printf("\n");
  }
}