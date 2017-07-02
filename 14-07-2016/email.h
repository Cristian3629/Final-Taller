#ifndef EMAIL_H
#define EMAIL_H

#include <iostream>
#include <string>

using namespace std;

class Email {
private:
  std::string email;
  //Stream extraction
  //Use Example : cout << email;
  friend ostream& operator<<(std::ostream& out,const Email& otherEmail){
    out << "Email: "<<otherEmail.email << std::endl;
    return out;

  }
  //Stream insertion
  // Use Example: some_string >> email;
  friend istream& operator>>(std::istream& in, Email& otherEmail){
    in >> otherEmail.email;
    return in;

  }

public:
  Email(string email);
  ~Email();
  Email(const Email & otherEmail);
  bool operator==(const Email& otherEmail);
  /*TODO:falta el operador int*/
};




#endif /*EMAIL_H*/
