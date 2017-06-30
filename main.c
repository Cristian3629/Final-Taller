#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_vocal(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
    return true;
  } else {
    return false;
  }
}

bool copy_backwards(FILE *file, long *reading_pos, long *writing_pos) {
  char c = '\0';
  unsigned short consonantes = 0;
  while ((c != ' ') && (*reading_pos >= 0)) {
    fseek(file,*reading_pos,SEEK_SET);
    c = fgetc(file);
    if (c != '\n' && c != ' '){
      consonantes += !is_vocal(c);
    }

    (*reading_pos)--;

    fseek(file, *writing_pos, SEEK_SET);
    fputc(c, file);
    (*writing_pos)--;

    fseek(file, *reading_pos, SEEK_SET);
  }
  return (consonantes > 2);
}
int main() {
  FILE *file;
  unsigned char c;
  unsigned short palabras;
  unsigned short consonantes;
  unsigned int espacio_a_reservar;
  unsigned int len_palabra;

  long reading_pos;
  long writing_pos;

  file = fopen("file.txt", "r+");

  consonantes = 0;
  espacio_a_reservar = 0;
  len_palabra = 0;
  c = fgetc(file);
  while (!feof(file)) {
    len_palabra++;
    if (!is_vocal(c) && c != ' ') {
      consonantes++;
    }
    if (c == ' ') {
      if (consonantes > 2) {
        espacio_a_reservar += len_palabra;
      }
      consonantes = 0;
      len_palabra = 0;
    }
    c = fgetc(file);
  }

  fseek(file,-1,SEEK_END);
  reading_pos = ftell(file) - 1;
  for (int i = 0; i < espacio_a_reservar - 1; i++) {
    fputc(' ',file);
  }

  fseek(file,0,SEEK_END);
  writing_pos = ftell(file);
  long _reading_pos;
  while (reading_pos >= 0) {
    _reading_pos = reading_pos;
    if (copy_backwards(file, &reading_pos, &writing_pos)) {
      copy_backwards(file, &_reading_pos, &writing_pos);
    }
  }

  fclose(file);
  return 0;
}