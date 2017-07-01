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

long calcular_espacio(FILE * file){
  long espacio_a_reservar;
  unsigned short consonantes;
  unsigned int len_palabra;
  char c;
  consonantes = 0;
  espacio_a_reservar = 0;
  len_palabra = 0;

  c = fgetc(file);
  while (!feof(file)){
    len_palabra++;
    if (!is_vocal(c) && c != ' ' && c != '\n'){
      consonantes++;
    }
    if (c == ' ' || c == '\n'){
      if (consonantes > 2){
        espacio_a_reservar += len_palabra;
      }
      len_palabra = 0;
      consonantes = 0;
    }
    c = fgetc(file);
  }
  return espacio_a_reservar;
}

int main() {
  FILE *file;
  unsigned char c;

  long espacio_a_reservar;

  long reading_pos;
  long writing_pos;

  file = fopen("file.txt", "r+");

  espacio_a_reservar = calcular_espacio(file);

  reading_pos = ftell(file) - 2;
  //abbabaa'\n'|   ftell(file)
  //abbabaa|'\n'   ftell(file)-1;
  //abbaba|a'\n'   ftell(file)-2;
  fseek(file,0,SEEK_END);
  for (int i = 0; i < (espacio_a_reservar - 1); i++) {
    fputc(' ',file);
  }

  fseek(file,-1,SEEK_END);
  writing_pos = ftell(file);
  long _reading_pos;
  while (reading_pos >= 0) {
    _reading_pos = reading_pos;
    if (copy_backwards(file, &reading_pos, &writing_pos)) {
      copy_backwards(file, &_reading_pos, &writing_pos);
    }
  }
  fseek(file,0,SEEK_END);

  fputc('\n',file); //segun parece hay una convención de que los archivos de texto
  //han de terminar con un newline. De hecho si se ejecuta este programa 2 veces sin
  //esta linea, en la segunda vez tira error. Así anda bien.
  fclose(file);

  return 0;
}