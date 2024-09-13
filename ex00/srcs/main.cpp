#include "Bureaucrat.hpp"

int main(void) {
  Bureaucrat* manA;
  const std::string name = "you";
  int grade = 42;

  try {
    manA = new Bureaucrat("you", grade);
  } catch (std::exception& e) {
    std::cerr << e.what();
  }
  delete manA;
}
