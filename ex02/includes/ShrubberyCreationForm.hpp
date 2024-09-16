#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <fstream>  // for file output

#include "AForm.hpp"

#define SHRUBBERY_CREATION_FORM_NAME "ShrubberyCreationForm"
#define SHRUBBERY_CREATION_FORM_GRADE_TO_SIGN 145
#define SHRUBBERY_CREATION_FORM_GRADE_TO_EXEC 137

#define TREE \
  "\
       &&& &&  & && \n\
    && &\\/&\\|& ()|/ @, && \n\
    &\\/(/&/&||/& /_/)_&/ \n\
 &() &\\/&|()|/&\\/ '%\" & () \n\
 &_\\/&_&&_/\\/&/\\\\&\\_/_& && \n\
  &&   && & &| &| /& & && \n\
      |||\\/  |||  \\/  || \n\
      |||||  |||  |||  ||| \n\
      |||||  |||  |||  ||| \n\
  ,////|||||||//||/||||\\, \n\
^^^^^^^^^^^^^^^^^^^^^^^^^^^ \n\
         ||||| ||||| \n\
         ||||| ||||| \n\
         ||||| ||||| \n\
         ||||| ||||| \n\
      ~~~~~~~~~~~~~~~~~ \n"

class ShrubberyCreationForm : public AForm {
 private:
  std::string _target;

 public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(std::string target);
  ShrubberyCreationForm(const ShrubberyCreationForm& other);
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
  virtual ~ShrubberyCreationForm();
  void execute(Bureaucrat const& executor) const;
  std::string getTarget(void) const;
};

#endif
