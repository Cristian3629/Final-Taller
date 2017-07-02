#include "email.h"


/*
1)
Declare la clase Email para encapsular una cadena correspondiente a una direccion
de email. Incluya al menos: Constructor Default y Constructor de Copia: Operador
<<,==,=, int y >>. Implemente el operador >>.

*/


using namespace std;

Email::Email(string email){
  this->email = email;
}


Email::Email(const Email & otherEmail):email(otherEmail.email){}



bool Email::operator==(const Email& otherEmail){
  return this->email == otherEmail.email;
}


Email::~Email(){

}
