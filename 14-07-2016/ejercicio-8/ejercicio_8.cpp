/*
Escriba las siguientes definiciones/declaraciones:
* Definicion de un puntero a la funcion MULT que tome dos enteros largos con
signo y devuelva su producto

*/
#include <vector>
signed long int MULT(signed long int a, signed long int b){
  return a*b;
}

signed long int(*p)(signed long int, signed long int);

void lala(){
  std::vector<int> vectora;
  vectora.erase();
}

// Declaración de un puntero a puntero a punto flotante de doble precision


double** p;



// Definicion de un caracter sin signo solamente visible en el modulo
static unsigned char a;
