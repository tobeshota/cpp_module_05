#include "AForm.hpp"

AForm::AForm()
    : _name(DEFAULT_NAME),
      _isSigned(DEFAULT_IS_SIGNED),
      _gradeToSign(DEFAULT_GRADE_TO_SIGN),
      _gradeToExec(DEFAULT_GRADE_TO_EXEC) {
  std::cout << "(constructor)AForm Default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, const int gradeToSign,
             const int gradeToExec)
    : _name(name),
      _isSigned(DEFAULT_IS_SIGNED),
      _gradeToSign(gradeToSign),
      _gradeToExec(gradeToExec) {
  if (_gradeToSign < HIGHEST_POSSIBLE_GRADE ||
      _gradeToExec < HIGHEST_POSSIBLE_GRADE)
    throw AForm::GradeTooHighException();
  else if (_gradeToSign > LOWEST_POSSIBLE_GRADE ||
           _gradeToExec > LOWEST_POSSIBLE_GRADE)
    throw AForm::GradeTooLowException();

  std::cout << "(constructor)AForm " << _name << " has been created!"
            << std::endl;
}

AForm::AForm(const AForm& other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign),
      _gradeToExec(other._gradeToExec) {
  std::cout << "(constructor)AForm Copy constructor called" << std::endl;
  *this = other;
}

// 何もすることがない
AForm& AForm::operator=(const AForm& other) {
  if (this == &other) return *this;
  return *this;
}

AForm::~AForm() {
  std::cout << "(destructor)AForm " << _name << " has been destroyed!"
            << std::endl;
}

const std::string AForm::getName(void) const { return _name; }

bool AForm::getIsSigned(void) const { return _isSigned; }

int AForm::getGradeToSign(void) const { return _gradeToSign; }

int AForm::getGradeToExec(void) const { return _gradeToExec; }

void AForm::setIsSigned(bool isSigned) { _isSigned = isSigned; }

bool AForm::beSigned(Bureaucrat& signer) {
  bool didGetSigned;

  if (signer.getGrade() > this->getGradeToSign()) {
    throw AForm::GradeTooLowException();
  } else if (_isSigned == true)
    didGetSigned = false;
  else {
    didGetSigned = true;
    setIsSigned(true);
  }
  return didGetSigned;
}

const char* AForm::GradeTooHighException::what() const throw() {
  return GradeTooHighExceptionMSG;
}

const char* AForm::GradeTooLowException::what() const throw() {
  return GradeTooLowExceptionMSG;
}

std::ostream& operator<<(std::ostream& os, AForm* form) {
  os << "_name: " + form->getName() +
            "\n_isSigned: " + intToString(form->getIsSigned()) +
            "\n_gradeToSign: " + intToString(form->getGradeToSign()) +
            "\n_gradeToExec" + intToString(form->getGradeToExec());
  return os;
}
