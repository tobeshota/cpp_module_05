#include "Intern.hpp"

const t_formMap *Intern::getFormMap(void) {
	const t_formMap formMap[] = {
    {"ShrubberyCreationForm", Intern::createShrubberyCreationForm},
    {"RobotomyRequestForm", Intern::createRobotomyRequestForm},
    {"PresidentialPardonForm", Intern::createPresidentialPardonForm},
  };
  return formMap;
}

ShrubberyCreationForm* Intern::createShrubberyCreationForm(const std::string& formTarget) {
  return new ShrubberyCreationForm(formTarget);
}

RobotomyRequestForm* Intern::createRobotomyRequestForm(const std::string& formTarget) {
  return new RobotomyRequestForm(formTarget);
}

PresidentialPardonForm* createPresidentialPardonForm(const std::string& formTarget) {
  return new PresidentialPardonForm(formTarget);
}

Intern::Intern() : _formMap(getFormMap()) {
  std::cout << "(constructor)Intern Default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
  std::cout << "(constructor)Intern Copy constructor called" << std::endl;
  *this = other;
}

// 何もすることがない
Intern& Intern::operator=(const Intern& other) {
  std::cout << "Intern Copy assignment operator called" << std::endl;
  if (this != &other) return *this;
  return *this;
}

Intern::~Intern() {
  std::cout << "(destructor)Intern has been destroyed!" << std::endl;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget) {
  for(int i = 0; i < sizeof(_formMap); i++) {
    if (_formMap[i].formName == formName)
      return _formMap[i].createFormObjectFunction(formTarget);
  }
  throw Intern::NoFormExpception();
  return NULL;
}

const char* Intern::NoFormExpception::what() const throw() {
  return "There is no form to be made!\n";
}
