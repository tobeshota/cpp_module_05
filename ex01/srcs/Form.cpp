#include "Form.hpp"

Form::Form()
    : _name(DEFAULT_NAME),
      _isSigned(DEFAULT_IS_SIGNED),
      _gradeToSign(DEFAULT_GRADE_TO_SIGN),
      _gradeToExec(DEFAULT_GRADE_TO_EXEC) {
  std::cout << "(constructor)Form Default constructor called" << std::endl;
}

Form::Form(const std::string& name, const int gradeToSign,
           const int gradeToExec)
    : _name(name),
      _isSigned(DEFAULT_IS_SIGNED),
      _gradeToSign(gradeToSign),
      _gradeToExec(gradeToExec) {
  if (_gradeToSign < HIGHEST_POSSIBLE_GRADE ||
      _gradeToExec < HIGHEST_POSSIBLE_GRADE)
    throw Form::GradeTooHighException();
  else if (_gradeToSign > LOWEST_POSSIBLE_GRADE ||
           _gradeToExec > LOWEST_POSSIBLE_GRADE)
    throw Form::GradeTooLowException();

  std::cout << "(constructor)Form " << _name << " has been created!"
            << std::endl;
}

Form::Form(const Form& other)
    : _name(other._name),
      _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign),
      _gradeToExec(other._gradeToExec) {
  std::cout << "(constructor)Form Copy constructor called" << std::endl;
  *this = other;
}

// 何もすることがない
Form& Form::operator=(const Form& other) {
  if (this == &other) return *this;
  return *this;
}

Form::~Form() {
  std::cout << "(destructor)Form " << _name << " has been destroyed!"
            << std::endl;
}

const std::string Form::getName(void) const { return _name; }

bool Form::getIsSigned(void) const { return _isSigned; }

int Form::getGradeToSign(void) const { return _gradeToSign; }

int Form::getGradeToExec(void) const { return _gradeToExec; }

void Form::setIsSigned(bool isSigned) { _isSigned = isSigned; }

bool Form::beSigned(Bureaucrat& signer) {
  bool didGetSigned;

  if (signer.getGrade() > this->getGradeToSign()) {
    throw Form::GradeTooLowException();
  } else if (_isSigned == true)
    didGetSigned = false;
  else {
    didGetSigned = true;
    setIsSigned(true);
  }
  return didGetSigned;
}

const char* Form::GradeTooHighException::what() const throw() {
  return GradeTooHighExceptionMSG;
}

const char* Form::GradeTooLowException::what() const throw() {
  return GradeTooLowExceptionMSG;
}

std::ostream& operator<<(std::ostream& os, Form* form) {
  os << "_name: " + form->getName() +
            "\n_isSigned: " + intToString(form->getIsSigned()) +
            "\n_gradeToSign: " + intToString(form->getGradeToSign()) +
            "\n_gradeToExec: " + intToString(form->getGradeToExec());
  return os;
}
