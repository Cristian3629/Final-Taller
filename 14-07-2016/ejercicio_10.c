/*
Escriba un programa en C que tome 3 cadenas por lineas de comandos A B C e imprima
la cadena A después de haber reemplazado todas las ocurrencias de B por C.

Ejemplo:

./programa El ejercicio está mal hecho mal bien
El ejercicio está bien hecho
*/

#include <stdio.h> //las otras funciones de archivo
#include <string.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
 //  int len_a = strlen(A);
 //  int len_b = strlen(B);
 //  int len_c = strlen(C);
 //
 // int pos_a = 0;
 // char const* char_ocurrencia = A;
 // while (char_ocurrencia != NULL) {
 //   char* char_ocurrencia = strstr(char_ocurrencia,B);
 //   if (char_ocurrencia != NULL){
 //     contador_de_ocurrencia_de_b_en_a++;
 //   }
 // }
 //
 // printf("La cantidad de ocurrencias es:%d\n",contador_de_ocurrencia_de_b_en_a);

 for (size_t i = 0; i < argc; i++) {
   printf("%s %d\n", argv[i],(int )i);
 }

 char* A = argv[1];
 char* B = argv[2];
 char* C = argv[3];

 //obtengo la longitud de cada palabra
 int len_a = strlen(A);
 int len_b = strlen(B);
 int len_c = strlen(C);


 int contador_de_ocurrencia_de_b_en_a = 0;

 char* char_ocurrencia = A;
 while (char_ocurrencia != NULL) {
   char_ocurrencia = strstr(char_ocurrencia,B);
   if (char_ocurrencia != NULL){
     contador_de_ocurrencia_de_b_en_a++;
     char_ocurrencia = &char_ocurrencia[len_b];
   }
 }

  printf("Cantidad de ocurrencias:%d\n",contador_de_ocurrencia_de_b_en_a);

  int total_len = len_a + contador_de_ocurrencia_de_b_en_a*(len_b-len_c);
  char* string_final = (char*)malloc(sizeof(char)*(total_len + 1));
  string_final[total_len] = '\0';

  int write_pointer = 0;
  for (size_t read_pointer = 0; read_pointer < len_a; i++) {
    char c = A[read_pointer];
    if (c == B[0]){
      bool is_b = true;
      //me fijo si lo que encontre es la palabra B
      for (size_t j = 0; j < len_b; i++) {
        if (B[j] != A[read_pointer + j]){
          is_b = false;
          break;
        }
      }
      if (is_b){
        for (size_t i = 0; i < count; i++) {
          /* code */
        }
      }
    }
  }

  return 0;
}
