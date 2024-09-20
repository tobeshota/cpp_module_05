#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/**Required grades:
 * ShrubberyCreationForm:  sign 145, exec 137
 * RobotomyRequestForm:    sign 72,  exec 45
 * PresidentialPardonForm: sign 25,  exec 5
 */
int main(void) {
  const int grade = 1;
  Bureaucrat* bureaucrat = new Bureaucrat("bureaucrat", grade);
  PresidentialPardonForm* ppform = new PresidentialPardonForm("ppform");
  try {
    bureaucrat->signForm(*ppform);
    bureaucrat->executeForm(*ppform);
  } catch (std::exception& e) {
    std::cerr << e.what();
  }
  delete bureaucrat;
  delete ppform;
}
