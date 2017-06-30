char* a[10];

/*miro a que apunta a algo char, no tengo anda mas a la izquierda y miro a la derecha
tengo 10 de esos*/

char (*a)[10]
/*miro a, voy a la izquierda a encuentr un *, entonces a apunta a algo, encuentro
un parentesis y voy a a derecha, entonces a apunta a un array de 10 cosas, regreso a la
izquierda y a apunta a un array de 10 chars*/


char (*f) (int)[10]

(*f) //f apunta a algo
(*f) (int) //f apunta a una funcion que recibe un int
char (*f) (int) //f apunta a una funcion que recibe un int y devuelve un char
char (*f)(int) [10] //tengo un array de punteros a funciones que recibe un int y devuelve un cha




//TODO
#ifndef


bind()

/*
bind a name to socket

vincula una direccion al file descriptor referido al socket, y este es normalmente
el local address, para eso se le pasa un struct addr en el cual se setea parametros como
sun_family
*/


¿Qué es un Mutex?. Ejemplifique.




¿Qué diferencias existen entre una comunicación UDP y TCP? ¿Qué funciones
requieren ser invocadas en cada caso para enviar datos?



¿Qué es un método virtual? ¿Para qué se usan? Ejemplifique.




¿Qué es una MACRO? ¿Qué usos tiene? ¿En qué parte del proceso de transformación
de código se resuelve?



¿Qué clase ofrece el paquete STL para encapsular una lista? Ejemplifique su uso.



¿Qué cuidado especial tendría Ud. al momento de escribir un operador= para una
clase que usa memoria dinámica? Ejemplifique.




nombre_de_clase& nombre_de_clase::operator=(const nombre_de_clase& other){
    if (*this == other){
      return *this;
    }
    //puntero = other.puntero;
    *puntero = *other.puntero;
    return *this;
}


nombre_de_clase::~nombre_de_clase(){
    free (puntero);
}
