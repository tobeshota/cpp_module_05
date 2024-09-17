#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

#define ROBOTOMY_REQUEST_FORM_NAME "ShrubberyCreationForm"
#define ROBOTOMY_REQUEST_FORM_GRADE_TO_SIGN 72
#define ROBOTOMY_REQUEST_FORM_GRADE_TO_EXEC 45

class RobotomyRequestForm : public AForm {
 private:
  std::string _target;

 public:
  RobotomyRequestForm();
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(const RobotomyRequestForm& other);
  RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
  virtual ~RobotomyRequestForm();
  void execute(Bureaucrat const& executor) const;
  std::string getTarget(void) const;
};

#endif
