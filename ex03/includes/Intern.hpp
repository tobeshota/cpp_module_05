#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// タイプ定義：クラスのインスタンスを生成するための関数ポインタ
typedef AForm* (Intern::*CreateFormObjectFunction)(const std::string& );

typedef struct s_formMap {
    const std::string formName;
    CreateFormObjectFunction createFormObjectFunction;
}              t_formMap;

class Intern {
 private:
  const t_formMap *_formMap;
  const t_formMap *Intern::getFormMap(void);
  ShrubberyCreationForm* createShrubberyCreationForm(const std::string& formTarget);
  RobotomyRequestForm* createRobotomyRequestForm(const std::string& formTarget);
  PresidentialPardonForm* createPresidentialPardonForm(const std::string& formTarget);
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
