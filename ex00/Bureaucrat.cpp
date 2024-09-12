#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(DEFAULT_NAME), _grade(DEFAULT_GRADE) {
  std::cout << "(constructor)Bureaucrat Default constructor called"
            << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) {
  _name = name;
  _grade = grade;
  std::cout << "(constructor)Bureaucrat " << _name << " has been created!"
            << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
  std::cout << "(constructor)ClapTrap Copy constructor called" << std::endl;
  *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
  if (this != &other) {
    _name = other._name;
    _grade = other._grade;
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "(destructor)Bureaucrat " << _name << " has been destroyed!"
            << std::endl;
}

std::string Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::setName(const std::string name) { _name = name; }

void Bureaucrat::setGrade(int grade) { _grade = grade; }
