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



#ifndef


bind()

/*
bind a name to socket

vincula una direccion al file descriptor referido al socket, y este es normalmente
el local address, para eso se le pasa un struct addr en el cual se setea parametros como
sun_family
*/
