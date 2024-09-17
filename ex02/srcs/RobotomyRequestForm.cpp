#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm(ROBOTOMY_REQUEST_FORM_NAME, ROBOTOMY_REQUEST_FORM_GRADE_TO_SIGN,
            ROBOTOMY_REQUEST_FORM_GRADE_TO_EXEC),
      _target(DEFAULT_TARGET) {
  std::cout << "(constructor)RobotomyRequestForm Default constructor called"
            << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm(ROBOTOMY_REQUEST_FORM_NAME, ROBOTOMY_REQUEST_FORM_GRADE_TO_SIGN,
            ROBOTOMY_REQUEST_FORM_GRADE_TO_EXEC),
      _target(target) {
  std::cout << "(constructor)RobotomyRequestForm " << this->getName()
            << " has been created!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(ROBOTOMY_REQUEST_FORM_NAME, ROBOTOMY_REQUEST_FORM_GRADE_TO_SIGN,
            ROBOTOMY_REQUEST_FORM_GRADE_TO_EXEC),
      _target(other.getTarget()) {
  *this = other;
}

// 何もすることがない
RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& other) {
  if (this != &other) return *this;
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "(destructor)RobotomyRequestForm " << this->getName()
            << " has been destroyed!" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  if (executor.getGrade() > this->getGradeToExec())
    throw Bureaucrat::GradeTooLowException();
  else if (this->getIsSigned() == false)
    throw AForm::NoSignException();
  else {
    ;
  }
}

std::string RobotomyRequestForm::getTarget(void) const { return _target; }
