#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#define DEFAULT_NAME "default"
#define DEFAULT_GRADE 150

class Bureaucrat {
 private:
  std::string _name;
  int _grade;

 public:
  Bureaucrat();
  Bureaucrat(const std::string& name, int grade);
  Bureaucrat(const Bureaucrat& other);
  Bureaucrat& operator=(const Bureaucrat& other);
  ~Bureaucrat();
  std::string getName() const;
  int getGrade() const;
  void setName(const std::string name);
  void setGrade(int grade);
};

#endif
