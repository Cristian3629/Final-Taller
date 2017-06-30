// Escribir un programa C que, sin crear archivos intermedios, procese el archivo“enteros.dat”. El
// procesamiento consiste en leer grupos de 2 enteros sin signo de 32 bits desde el archivo y
// escribir, en su lugar, la resta del grupo (es decir que el archivo se acortará).
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


#include <unistd.h>
#include <sys/types.h>


int main(int argc, char const *argv[]) {
  FILE* fp = fopen("enteros.dat", "rb+");
  if (fp == NULL){
    return 1;
  }
  printf("Se abrió el archivo de manera correcta\n");
  int write_pointer = 0;
  int read_pointer = 0;
  bool read_a_number = false;
  uint32_t other_number = 0;
  uint32_t number = 0;
  while (!feof(fp)){
    size_t size = fread(&number,1,sizeof(uint32_t),fp);
    if (size != 4){
      printf("No Lei cuatros bytes,lei %d\n",(int)size);
      break;
    }
    //si todavia no lei ningun numero
    if (!read_a_number){
      other_number = number;
      read_a_number = true;
    //si ya lei algun numero
    }else{
      //hago la resta
      number = other_number - number;
      printf("Number es:%x\n",number);
      //voy a donde tengo que escribir
      fseek(fp,write_pointer,SEEK_SET);
      //escribo
      fwrite(&number,1,sizeof(uint32_t),fp);
      //actualizo mi puntero para escribir
      write_pointer+=sizeof(uint32_t);
      read_a_number = false;
    }
    //TODO:preguntar
  read_pointer+=sizeof(uint32_t);
  fseek(fp,read_pointer,SEEK_SET);
  printf("Posicion de lectura:%d\n", read_pointer);
  printf("Posicion de escritura:%d\n",write_pointer);
  }
  //tengo que resolver que hacer con los bytes que me sobran
  if (ftruncate(fileno(fp), write_pointer) < 0){
    return 1;
  }
  fclose(fp);
  return 0;
}
