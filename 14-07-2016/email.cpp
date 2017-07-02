#include "email.h"


/*
1)
Declare la clase Email para encapsular una cadena correspondiente a una direccion
de email. Incluya al menos: Constructor Default y Constructor de Copia: Operador
<<,==,=, int y >>. Implemente el operador >>.

*/


using namespace std;

Email::Email(string email){
  this.email = email;
}


Email::Email(const Email & otherEmail)string(otherEmail.email){

}


//Stream extraction
//Use Example : cout << email;
ostream& Email::operator<<(ostream& out,const Email& otherEmail){
  out << otherEmail.email << '/n';
  return out;
}

//Stream insertion
// Use Example: some_string >> email;
ostream& Email::operator>>(ostream& in, const Email & otherEmail){

}


Email::~Email(){

}
