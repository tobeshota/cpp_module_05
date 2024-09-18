#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <cstdlib> // for rand()
#include <ctime>   // for time()

#define ROBOTOMY_REQUEST_FORM_NAME "RobotomyRequestForm"
#define ROBOTOMY_REQUEST_FORM_GRADE_TO_SIGN 72
#define ROBOTOMY_REQUEST_FORM_GRADE_TO_EXEC 45
#define DRILLING_NOISES "waiting...(dululululululululul)"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define DEFAULT "\x1b[0m\x1b[39m"
#define SUCCESS_MSG(TARGET)                        \
  (std::string(GREEN) + ">>>>>>>>>> " + (TARGET) + \
   " HAS BEEN ROBOTOMIZED <<<<<<<<<<" + DEFAULT + "\n")
#define FAILURE_MSG(TARGET)                      \
  (std::string(RED) + ">>>>>>>>>> " + (TARGET) + \
   " HAS FAILED TO ROBOTOMIZED <<<<<<<<<<" + DEFAULT + "\n")

class RobotomyRequestForm : public AForm {
 private:
  std::string _target;

 public:
  RobotomyRequestForm();
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(const RobotomyRequestForm& other);
  RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
  virtual ~RobotomyRequestForm();
  bool execute(Bureaucrat const& executor) const;
  std::string getTarget(void) const;
};

std::ostream& operator<<(std::ostream& os, RobotomyRequestForm* scform);

#endif
