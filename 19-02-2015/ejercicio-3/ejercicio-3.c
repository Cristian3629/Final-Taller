//
// Created by darius on 04/07/17.
//

#ifndef FINALC_EJERCICIO_3_H
#define FINALC_EJERCICIO_3_H

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint-gcc.h>
/*
 * Enunciado: Escribir un programa C que, sin crear archivos intermedios, procese un archivo
 * binario "mayores.dat". El procesamiento consiste en leer 3 grupos de enteros sin signo de
 * 32 bits desde el archivo y escribir, en su lugar, el mayor de los 3 (el archivo se acortará).
 */
int mainb(int argc, char * argv[]){
  int state;
  uint32_t higher;
  uint32_t number;
  long read_pos;
  long writing_pos;
  bool finished;
  FILE * fp = fopen("../19-02-2015/ejercicio-7/RandomNumbers","rb+");

//  Para ver el archivo binario, descomentar esto y comentar lo de abajo.
//  while (!feof(fp)){
//    fread(&number,sizeof(uint32_t),1,fp);
//    printf("%zu\n",number);
//  }

  finished = false;
  read_pos = 0;
  writing_pos = 0;
  while (!finished){
    higher = 0;
    state = 0;
    while (state < 3 && !feof(fp)){
      fread(&number,sizeof(uint32_t),1,fp);
      read_pos += sizeof(uint32_t);
      if (number > higher){
        higher = number;
      }
      state++;
    }
    if (feof(fp)){
      finished = true;
      /*
       * no puedo poner feof como condicion del while porque
       * no sale nunca debido a que cuando hago el fseek ultimo
       * nunca me reposiciona después del final de archivo
       * sino que corre la marca del fin de archivo y la condicion
       * feof(fp) pasa a ser falsa.
       */
    }
    fseek(fp,writing_pos,SEEK_SET);
    fwrite(&higher,sizeof(uint32_t),1,fp);
    writing_pos += sizeof(uint32_t);
    fseek(fp,read_pos,SEEK_SET);
  }
  ftruncate(fileno(fp),writing_pos);
  fclose(fp);
}
#endif //FINALC_EJERCICIO_3_H
