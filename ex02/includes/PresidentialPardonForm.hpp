#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

#define PRESIDENTIAL_PARDON_FORM_NAME "PresidentialPardonForm"
#define PRESIDENTIAL_PARDON_FORM_GRADE_TO_SIGN 25
#define PRESIDENTIAL_PARDON_FORM_GRADE_TO_EXEC 5
#define PARDON(TARGET) ((TARGET) + "has been pardoned by Zaphod Beeblebrox\n")

class PresidentialPardonForm : public AForm {
 private:
  std::string _target;

 public:
  PresidentialPardonForm();
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(const PresidentialPardonForm& other);
  PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
  virtual ~PresidentialPardonForm();
  void execute(Bureaucrat const& executor) const;
  std::string getTarget(void) const;
};

std::ostream& operator<<(std::ostream& os, PresidentialPardonForm* scform);

#endif
