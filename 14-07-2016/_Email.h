//
// Created by darius on 02/07/17.
//

#ifndef FINALC_EMAIL_DARIUS_H
#define FINALC_EMAIL_DARIUS_H
//Declare la clase Email para encapsular una cadena correspondiente a una dirección de
//    email. Incluya al menos: Constructor default y Constructor de Copia; Operador <<, ==, =, int y
//>>. Implemente el operador >>.

#include <iostream>
#include <string>
class _Email {
 private:
  std::string email;
 public:
  _Email(const std::string& email): email(email){}

  _Email(const _Email& other){
    this->email = other.email;
  }

  std::ostream& operator<<(std::ostream& os, const _Email& email);

  bool operator==(const _Email& other);

  void operator=(const _Email& other);

  operator int();

  std::istream& operator>>(std::istream& is, _Email& email){
    is.getline(&(email.email)[0] , 256);
    return is;
  }
};

#endif //FINALC_EMAIL_DARIUS_H
