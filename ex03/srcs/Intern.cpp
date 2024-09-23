#include "Intern.hpp"

void* createShrubberyCreationForm(const std::string& formTarget) {
  return new ShrubberyCreationForm(formTarget);
}

void* createRobotomyRequestForm(const std::string& formTarget) {
  return new RobotomyRequestForm(formTarget);
}

void* createPresidentialPardonForm(const std::string& formTarget) {
  return new PresidentialPardonForm(formTarget);
}

Intern::Intern() {
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

AForm* Intern::makeForm(const std::string& formName,
                        const std::string& formTarget) {
  const t_formMap formMap[] = {
      {"shrubbery creation", createShrubberyCreationForm},
      {"robotomy request", createRobotomyRequestForm},
      {"presidential pardon", createPresidentialPardonForm},
  };

  for (size_t i = 0; i < sizeof(formMap) / sizeof(formMap[0]); i++) {
    if (formMap[i].formName == formName)
      return (AForm*)formMap[i].createFormObjectFunction(formTarget);
  }
  throw Intern::NoFormExpception();
  return NULL;
}

const char* Intern::NoFormExpception::what() const throw() {
  return "There is no form to be made!\n";
}
