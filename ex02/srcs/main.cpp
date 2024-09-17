#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

int main(void) {
  Bureaucrat* signerA;
  RobotomyRequestForm* RRFormA;
  int grade = 20;

  try {
    signerA = new Bureaucrat("you", grade);
    RRFormA = new RobotomyRequestForm();
    RRFormA->setIsSigned(true);
    RRFormA->execute(*signerA);
    delete signerA;
    delete RRFormA;
  } catch (std::exception& e) {
    std::cerr << e.what();
  }
}
