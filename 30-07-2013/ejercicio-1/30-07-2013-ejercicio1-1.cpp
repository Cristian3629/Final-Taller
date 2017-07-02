#include <stdio.h>
#include <stdlib.h>

//1.La definición de una función de alcance local al archivo de
//  definición, denominada suma que tome como parámetros 2 enteros y devuelva un
//  puntero a caracter con el resultado de la suma formateada como una cadena.
static char* sumar(int a, int b){
  int result = a + b;
  char* buffer = (char*)malloc(sizeof(char)*5 + 1);
  snprintf(buffer,sizeof(buffer),"%d",result);
  return buffer;
}

int main ()
{
  char* result = sumar(1,2);
  printf("El resultado es el siguiente:%s\n", result);
  free(result);
}
