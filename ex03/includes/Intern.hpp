#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

typedef struct s_formMap {
  const std::string formName;
  void* (*createFormObjectFunction)(const std::string&);
} t_formMap;

void* createShrubberyCreationForm(const std::string& formTarget);
void* createRobotomyRequestForm(const std::string& formTarget);
void* createPresidentialPardonForm(const std::string& formTarget);

class Intern {
 public:
  Intern();
  Intern(const Intern& other);
  Intern& operator=(const Intern& other);
  ~Intern();
  AForm* makeForm(const std::string& formName, const std::string& formTarget);
  class NoFormExpception : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

#endif
