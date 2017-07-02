#ifndef EMAIL_H
#define EMAIL_H

using namespace std;

class Email {
private:
  string email;
public:
  Email(string email);
  ~Email();
  Email(const Email & otherEmail);
  ostream& operator<<(ostream& out,const Email& otherEmail);
  ostream& operator>>(ostream& in, const Email & otherEmail);

  operator==(const Email& otherEmail);
  operator=(const Email & otherEmail);
  /*TODO:falta el operador int*/
};


#endif /*EMAIL_H*/
