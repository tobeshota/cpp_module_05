#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

#define DEFAULT_IS_SIGNED false
#define DEFAULT_GRADE_TO_SIGN 20
#define DEFAULT_GRADE_TO_EXEC 10

class Form {
 private:
  const std::string _name;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExec;

 public:
  Form();
  Form(const std::string& name, const int gradeToSign, const int gradeToExec);
  Form(const Form& other);
  Form& operator=(const Form& other);
  ~Form();
  const std::string getName(void) const;
  bool getIsSigned(void) const;
  const int getGradeToSign(void) const;
  const int getGradeToExec(void) const;
  bool beSigned(Bureaucrat& signer);

  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& os, Form* form);

#endif
