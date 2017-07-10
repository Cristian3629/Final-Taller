//
// Created by darius on 04/07/17.
//

/*
Escriba un programa en C que tome 3 cadenas por lineas de comandos A B C e imprima
la cadena A después de haber reemplazado todas las ocurrencias de B por C.

Ejemplo:

./programa El ejercicio está mal hecho mal bien
El ejercicio está bien hecho
*/
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_LEN 512

void agregar_texto(char **posicion, char *inicio, char *final){
  size_t amount = (final-inicio)*sizeof(char);
  memcpy(*posicion,inicio,amount);
  *posicion = *posicion + amount;
}

int maina(int argc, char * argv[]){
  char * A = argv[1];
  char * B = argv[2];
  char * C = argv[3];

  size_t lenA = strnlen(A,MAX_LEN);
  size_t lenB = strnlen(B,MAX_LEN);
  size_t lenC = strnlen(C,MAX_LEN);

  char * _A = (char*)malloc(MAX_LEN*sizeof(char));

  char * left_bracket, *right_bracket, *copy_position;
  bool remplazo_finalizado = false;
  left_bracket = A;
  copy_position = _A;
  while (!remplazo_finalizado){
    right_bracket = strstr(left_bracket,B);
    if (right_bracket == NULL){
      remplazo_finalizado = true;
      right_bracket = A + lenA*sizeof(char);
      agregar_texto(&copy_position, left_bracket, right_bracket);
      break;
    }
    agregar_texto(&copy_position, left_bracket, right_bracket);
    agregar_texto(&copy_position, C, C + lenC);
    left_bracket = right_bracket + lenB*sizeof(char);//es redundante??
  }

  printf("%s",_A);
  free(_A);
}