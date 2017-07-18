//
// Created by darius on 09/07/17.
//

#include <stdio.h>
#include <unistd.h>

int mainu(int argc, char * argv[]){

  FILE * file = fopen("../26-12-2012/ejercicio-7/fuente","r+");

  int writing_pos = 0;
  int reading_pos = 0;
  int state_on = 0;
  int state_off = 0;
  char c;

  //  ...../...../*.......*/.....*....

  while (!feof(file)){
    c = fgetc(file);
    if (feof(file)){
      break;
    }
    reading_pos++;

    if (state_on == 0){
      if (c == '/'){
        state_on = 1;
      } else {
        fseek(file,writing_pos,SEEK_SET);
        fputc(c,file);
        writing_pos++;
        fseek(file,reading_pos,SEEK_SET);
      }
    } else {
      if (state_on == 1){
        if (c == '*'){
          state_on = 2;
        } else {
          state_on = 0;
          fseek(file,writing_pos,SEEK_SET);
          fputc('/',file);
          writing_pos++;
          fputc(c,file);
          writing_pos++;
          fseek(file,reading_pos,SEEK_SET);
        }
      }
      }

    while (state_on == 2 && !feof(file)){
      c = fgetc(file);
      if (feof(file)){
        break;
      }
      reading_pos++;
      if (state_off == 0){
        if (c == '*'){
          state_off = 1;
        }
      } else {
        if (state_off == 1){
          if (c == '/'){
            state_on = 0;
            state_off = 0;
          }
        }
      }
    }
  }

  ftruncate(fileno(file),writing_pos);
  fclose(file);
}
