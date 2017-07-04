/*
Escriba un programa en C que tome 3 cadenas por lineas de comandos A B C e imprima
la cadena A después de haber reemplazado todas las ocurrencias de B por C.

Ejemplo:

./programa El ejercicio está mal hecho mal bien
El ejercicio está bien hecho
*/

#include <stdio.h> //las otras funciones de archivo

int main(int argc, char const *argv[]) {
  char* A = argv[1];
  char* B = argv[2];
  char* C = argv[3];
  //busco la cantidad de ocurrencias de B en A
  int len_a = strlen(A);
  int len_b = strlen(B);
  int len_c = strlen(C);
  int contador_de_ocurrencia_de_b_en_a = 0;
  for (size_t i = 0; i < len_a; i++) {
    if (A[i] == B[0]){
      bool b_en_a = true;
      int pos_desde_donde_comparo = i;
      for (size_t j = 1; j < len_b; j++) {
        if (A[pos_desde_donde_comparo + j] != B[j]){
          b_en_a = false;
          break;
        }
      }
      if (b_en_a){
        contador_de_ocurrencia_de_b_en_a++;
        i = pos_desde_donde_comparo + len_b;
      }
    }
  }

  int espacio_que_necesite = contador_de_ocurrencia_de_b_en_a*(len_b - len_c);

  int espacio_total = len_a + espacio_que_necesite;
  char* array_final = malloc(sizeof(char)*espacio_total + 1);

  int write_pointer = 0;
  int read_pointer = 0;

  //hacer el merge

  return 0;
}
