#include "Bureaucrat.hpp"

int main(void) {
  Bureaucrat* signerA;
  Form* formA;
  int grade = 20;
  const int gradeToSign = 20;
  const int gradeToExec = 10;

  try {
    signerA = new Bureaucrat("you", grade);
    formA = new Form("form", gradeToSign, gradeToExec);
    signerA->signForm(*formA);
  } catch (std::exception& e) {
    std::cerr << e.what();
  }
  delete signerA;
  delete formA;
}
