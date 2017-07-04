/*
Escribir un programa C que procese el archivo fuente.c sobre sí mismo
(sin crear archivos intermedios). El proceso consiste en eliminar todos los
comentarios ()
*/

//Status = 0 No encontré el primer /
//Status = 1 Encontré el primero /
//status = 2 Encontré el /*
//status = 3 Encontre /**
//status = 4 Encontre /**/

#include <stdio.h> //las otras funciones de archivo
#include <unistd.h> //ftruncate
#include <stdbool.h> //para usar booleanos


int main(int argc, char const *argv[]){
  FILE* fp = fopen("fuente.c","r+");
  if (fp == NULL){
    return 1;
  }
  int write_pointer = 0;
  int read_pointer = 0;
  int status = 0;
  //TODO: nunca sale del while, asi que hay que testear lo que leo
  while (!feof(fp)) {
    char c = fgetc(fp);
    switch (status) {
      case 4:
        status = 0;
        break;
      case 0:
        if (c == '/'){
          status++;
        }
        break;
      case 1:
        if (c == '*'){
          status++;
        }else{
          status = 0;
        }
        break;
      case 2:
        if (c == '*'){
          status++;
        }
        break;
      case 3:
        if (c == '/'){
          status++;
        }else{
          status = 0;
        }
    }
    if (status == 0){
      fseek(fp,write_pointer,SEEK_SET);
      fputc(c,fp);
      printf("%s",&c);
      write_pointer++;
    }
    read_pointer++;
    fseek(fp,read_pointer,SEEK_SET);
  }
  if (ftruncate(fileno(fp),write_pointer) < 0){
    return 1;
  };
  fclose(fp);
  return 0;
}
