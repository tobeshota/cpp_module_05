#include "Bureaucrat.hpp"

int main(void) {
  Bureaucrat* signerA;
  AForm* formA;
  int grade = 20;
  const int gradeToSign = 20;
  const int gradeToExec = 10;

  try {
    signerA = new Bureaucrat("you", grade);
    formA = new AForm("form", gradeToSign, gradeToExec);
    signerA->signAForm(*formA);
  } catch (std::exception& e) {
    std::cerr << e.what();
  }
  delete signerA;
  delete formA;
}
