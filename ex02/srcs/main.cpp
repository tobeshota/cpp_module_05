#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

int main(void) {
  Bureaucrat* signerA;
  RobotomyRequestForm* ffrom;
  int grade = 20;

  try {
    signerA = new Bureaucrat("you", grade);
    ffrom = new RobotomyRequestForm();
    ffrom->setIsSigned(true);
    ffrom->execute(*signerA);
    delete signerA;
    delete ffrom;
  } catch (std::exception& e) {
    std::cerr << e.what();
  }
}
