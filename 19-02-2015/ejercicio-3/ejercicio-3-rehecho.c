//
// Created by darius on 06/07/17.
//

#include <stdio.h>
#include <stdint-gcc.h>
#include <stdbool.h>
#include <unistd.h>

/*
 * Enunciado: Escribir un programa C que, sin crear archivos intermedios, procese un archivo
 * binario "mayores.dat". El procesamiento consiste en leer 3 grupos de enteros sin signo de
 * 32 bits desde el archivo y escribir, en su lugar, el mayor de los 3 (el archivo se acortará).
 */

int mainw(int argc, char * argv[]){

  FILE * fp = fopen("../19-02-2015/ejercicio-7/RandomNumbers","rb+");
  short state;
  uint32_t higher;
  uint32_t number;
  long writing_pos;
  long reading_pos;
  bool finished;

  writing_pos = 0;
  reading_pos = 0;
  finished = false;
  while (!finished){
    state = 0;
    higher = 0;
    while (state < 3 && !feof(fp)){
      fread(&number,sizeof(uint32_t),1,fp);
      reading_pos += sizeof(uint32_t);
      if (number > higher){
        higher = number;
      }
      state++;
    }
    if (feof(fp)){
      finished = true;
    }
    fseek(fp,writing_pos,SEEK_SET);
    fwrite(&higher,sizeof(uint32_t),1,fp);
    writing_pos += sizeof(uint32_t);
    fseek(fp,reading_pos,SEEK_SET);
  }
  ftruncate(fileno(fp),writing_pos);
  fclose(fp);
}
