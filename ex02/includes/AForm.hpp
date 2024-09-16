#ifndef FORM_HPP
#define FORM_HPP

class Bureaucrat;

#include <iostream>

#include "Bureaucrat.hpp"

#define DEFAULT_IS_SIGNED false
#define DEFAULT_GRADE_TO_SIGN 20
#define DEFAULT_GRADE_TO_EXEC 10
#define DEFAULT_TARGET "<target>"

class AForm {
 private:
  const std::string _name;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExec;

 public:
  AForm();
  AForm(const std::string& name, const int gradeToSign, const int gradeToExec);
  AForm(const AForm& other);
  AForm& operator=(const AForm& other);
  ~AForm();
  const std::string getName(void) const;
  bool getIsSigned(void) const;
  int getGradeToSign(void) const;
  int getGradeToExec(void) const;
  void setIsSigned(bool isSigned);
  bool beSigned(Bureaucrat& signer);
  virtual void execute(Bureaucrat const& executor) const = 0;

  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& os, AForm* form);

#endif
