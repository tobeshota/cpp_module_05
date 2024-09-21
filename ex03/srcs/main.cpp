#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/**Required grades:
 * ShrubberyCreationForm:  sign 145, exec 137
 * RobotomyRequestForm:    sign 72,  exec 45
 * PresidentialPardonForm: sign 25,  exec 5
 */
int main(void) {
  Intern someRandomIntern;
  RobotomyRequestForm* rrf = (RobotomyRequestForm*)someRandomIntern.makeForm(
      "robotomy request", "Bender");
  std::cout << rrf;
  delete rrf;
}
