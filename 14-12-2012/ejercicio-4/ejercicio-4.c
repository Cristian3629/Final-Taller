//
// Created by darius on 10/07/17.
// 0x34 0x43 0x44 por la secuencia 0x34 0x43
//

/*
 * eeeeabceabccee
 * read
 * if (state == 0) {
 *    if (a) {
 *      state == 1;
 *    } else {
 *      state = 0;
 *    }
 *    write
 * } else {
 * if (state == 1) {
 *    if (b) {
 *      state = 2;
 *    } else {
 *      state = 0;
 *    }
 *    write
 * } else {
 * if (state == 2) {
 *    if (c) {
 *      no write;
 *      task_completed = false;
 *    } else {
 *      write;
 *    }
 *    state = 0
 *}}}
 */
#include <stdbool.h>
#include <stdio.h>

void write(char c, FILE * file, int reading_pos, int * writing_pos){
  fseek(file,*writing_pos,SEEK_SET);
  fputc(c,file);
  *writing_pos = *writing_pos + 1;
  fseek(file,reading_pos,SEEK_SET);
}
int bmain(int argc, char * argv[]){

  FILE * file = fopen("../14-12-2012/ejercicio-4/data.bin","r+");

  char c;
  bool task_completed = false;
  int state = 0;
  int writing_pos = 0;
  int reading_pos = 0;

  while (!task_completed){
    task_completed = true;
    while (true){
      c = fgetc(file);
      if (feof(file)){
        break;
      }
      reading_pos++;
      if (state == 0){
        if (c == 'a'){//0x34
          state = 1;
        } else {
          state = 0;
        }
        write(c,file,reading_pos,&writing_pos);
      } else {
        if (state == 1){
          if (c == 'b'){ //0x43
            state = 2;
          } else {
            state = 0;
          }
          write(c,file,reading_pos,&writing_pos);
        } else {
          if (state == 2){
            if ( c == 'c'){//0x44
              task_completed = false;
            } else {
              write(c,file,reading_pos,&writing_pos);
            }
            state = 0;
          }
        }
      }
    }
    if (!task_completed){
      fseek(file,0,SEEK_SET);
      reading_pos = 0;
      writing_pos = 0;
    }
  }

  fclose(file);
}