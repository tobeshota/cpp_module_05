#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm(SHRUBBERY_CREATION_FORM_NAME, SHRUBBERY_CREATION_FORM_GRADE_TO_SIGN,
            SHRUBBERY_CREATION_FORM_GRADE_TO_EXEC),
      _target(DEFAULT_TARGET) {
  std::cout << "(constructor)ShrubberyCreationForm Default constructor called"
            << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm(SHRUBBERY_CREATION_FORM_NAME, SHRUBBERY_CREATION_FORM_GRADE_TO_SIGN,
            SHRUBBERY_CREATION_FORM_GRADE_TO_EXEC),
      _target(target) {
  std::cout << "(constructor)ShrubberyCreationForm " << this->getName()
            << " has been created!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(SHRUBBERY_CREATION_FORM_NAME, SHRUBBERY_CREATION_FORM_GRADE_TO_SIGN,
            SHRUBBERY_CREATION_FORM_GRADE_TO_EXEC),
      _target(other.getTarget()) {
  *this = other;
}

// 何もすることがない
ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& other) {
  if (this != &other) return *this;
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "(destructor)ShrubberyCreationForm " << this->getName()
            << " has been destroyed!" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  if (this->isAbleToExecute(executor) == true) {
    std::ofstream outfile;
    outfile.open(this->getTarget() + "_shrubbery", std::ios::out);
    outfile << TREE;
    outfile.close();
  }
}

std::string ShrubberyCreationForm::getTarget(void) const { return _target; }
