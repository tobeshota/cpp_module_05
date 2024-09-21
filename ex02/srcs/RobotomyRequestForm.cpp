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

// 50% chance to return true or false
static bool randomBool(void) {
  std::srand(std::time(0));
  return std::rand() % 2 == 0;
}

bool RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  if (this->isAbleToExecute(executor) == true) {
    for (int i = 0; i < executor.getGrade(); i++)
      std::cout << DRILLING_NOISES << std::endl;
    if (randomBool() == true)
      std::cout << SUCCESS_MSG(this->getTarget());
    else
      std::cout << FAILURE_MSG(this->getTarget());
  }
  return true;
}

std::ostream& operator<<(std::ostream& os, RobotomyRequestForm* rrform) {
  os << "_name: " + rrform->getName() + "\n_target: " + rrform->getTarget() +
            "\n_isSigned: " + intToString(rrform->getIsSigned()) +
            "\n_gradeToSign: " + intToString(rrform->getGradeToSign()) +
            "\n_gradeToExec" + intToString(rrform->getGradeToExec());
  return os;
}

std::string RobotomyRequestForm::getTarget(void) const { return _target; }
