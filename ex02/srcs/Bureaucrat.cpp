#include "Bureaucrat.hpp"

#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name(DEFAULT_NAME), _grade(DEFAULT_GRADE) {
  std::cout << "(constructor)Bureaucrat Default constructor called"
            << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
  Bureaucrat::setGradeSafely(grade);
  std::cout << "(constructor)Bureaucrat " << _name << " has been created!"
            << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other.getName()) {
  std::cout << "(constructor)Bureaucrat Copy constructor called" << std::endl;
  *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
  if (this != &other) this->setGradeSafely(other.getGrade());
  return *this;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "(destructor)Bureaucrat " << _name << " has been destroyed!"
            << std::endl;
}

const std::string Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::setGradeSafely(int grade) {
  if (grade < HIGHEST_POSSIBLE_GRADE)
    throw Bureaucrat::GradeTooHighException();
  else if (grade > LOWEST_POSSIBLE_GRADE)
    throw Bureaucrat::GradeTooLowException();
  _grade = grade;
}

void Bureaucrat::incrementGrade(void) { setGradeSafely(_grade - 1); }

void Bureaucrat::decrementGrade(void) { setGradeSafely(_grade + 1); }

void Bureaucrat::signForm(AForm& form) {
  bool didGetSigned = form.beSigned(*this);
  if (didGetSigned == true)
    std::cout << this->getName() + " signed " << form.getName() << std::endl;
  else
    std::cout << this->getName() + " couldn't sign " << form.getName()
              << " because is has already signed" << std::endl;
}

void Bureaucrat::executeForm(AForm const& form) {
  bool beAbleToExec = form.execute(*this);
  if (beAbleToExec == true)
    std::cout << this->getName() + " executed " << form.getName() << std::endl;
  else
    std::cout << this->getName() + " did not execute " << form.getName()
              << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return GradeTooHighExceptionMSG;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return GradeTooLowExceptionMSG;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat* b) {
  os << b->getName() + ", bureaucrat grade " + intToString(b->getGrade()) +
            "\n";
  return os;
}

// int型をstring型に変換
std::string intToString(const int num) {
  std::stringstream ss;
  ss << num;
  std::string str = ss.str();
  return str;
}
