#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm(PRESIDENTIAL_PARDON_FORM_NAME,
            PRESIDENTIAL_PARDON_FORM_GRADE_TO_SIGN,
            PRESIDENTIAL_PARDON_FORM_GRADE_TO_EXEC),
      _target(DEFAULT_TARGET) {
  std::cout << "(constructor)PresidentialPardonForm Default constructor called"
            << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm(PRESIDENTIAL_PARDON_FORM_NAME,
            PRESIDENTIAL_PARDON_FORM_GRADE_TO_SIGN,
            PRESIDENTIAL_PARDON_FORM_GRADE_TO_EXEC),
      _target(target) {
  std::cout << "(constructor)PresidentialPardonForm " << this->getName()
            << " has been created!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& other)
    : AForm(PRESIDENTIAL_PARDON_FORM_NAME,
            PRESIDENTIAL_PARDON_FORM_GRADE_TO_SIGN,
            PRESIDENTIAL_PARDON_FORM_GRADE_TO_EXEC),
      _target(other.getTarget()) {
  *this = other;
}

// 何もすることがない
PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& other) {
  if (this != &other) return *this;
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "(destructor)PresidentialPardonForm " << this->getName()
            << " has been destroyed!" << std::endl;
}

bool PresidentialPardonForm::execute(Bureaucrat const& executor) const {
  if (this->isAbleToExecute(executor) == true) {
    std::cout << PARDON(this->getTarget());
  }
  return true;
}

std::ostream& operator<<(std::ostream& os, PresidentialPardonForm* ppform) {
  os << "_name: " + ppform->getName() + "\n_target: " + ppform->getTarget() +
            "\n_isSigned: " + intToString(ppform->getIsSigned()) +
            "\n_gradeToSign: " + intToString(ppform->getGradeToSign()) +
            "\n_gradeToExec: " + intToString(ppform->getGradeToExec());
  return os;
}

std::string PresidentialPardonForm::getTarget(void) const { return _target; }
