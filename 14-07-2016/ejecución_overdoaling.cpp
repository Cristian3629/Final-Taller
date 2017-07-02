#include "email.h"

int main(int argc, char const *argv[]) {
  Email email("cristian3629@gmail.com");
  std::cout << email;

  std::cout << "Ingrese el nuevo email:" << std::endl;
  std::cin >> email;
  std::cout << "El nuevo email es:";
  std::cout << email;
  return 0;
}
