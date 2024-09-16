#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  Bureaucrat* signerA;
  ShrubberyCreationForm* SCFormA;
  int grade = 20;

  try {
    signerA = new Bureaucrat("you", grade);
    SCFormA = new ShrubberyCreationForm();
    SCFormA->setIsSigned(true);
    SCFormA->execute(*signerA);
    delete signerA;
    delete SCFormA;
  } catch (std::exception& e) {
    std::cerr << e.what();
  }
}
