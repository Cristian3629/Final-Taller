#include <stdio.h>
#include <stdlib.h>


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
