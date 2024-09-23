#include <gtest/gtest.h>

#include "Intern.hpp"

template <typename T>
std::string getInsertionCapturedStdout(T *form) {
  testing::internal::CaptureStdout();
  std::cout << form;
  std::string actual = testing::internal::GetCapturedStdout();
  return actual;
}

// Intern::makeForm()の第一引数に"shrubbery
// creation"を指定するとShrubberyCreationFormクラスのオブジェクトが作られる
TEST(MakeFormTest, MakeShrubberyCreationFormTest) {
  Intern someRandomIntern;
  ShrubberyCreationForm *scf =
      (ShrubberyCreationForm *)someRandomIntern.makeForm("shrubbery creation",
                                                         "Bender");
  std::string actual = getInsertionCapturedStdout(scf);
  std::string expect =
      "_name: ShrubberyCreationForm\n_target: Bender\n_isSigned: "
      "0\n_gradeToSign: 145\n_gradeToExec: 137\n";
  EXPECT_EQ(expect, actual);
}

// Intern::makeForm()の第一引数に"robotomy
// request"を指定するとRobotomyRequestFormクラスのオブジェクトが作られる
TEST(MakeFormTest, MakeRobotomyRequestFormTest) {
  Intern someRandomIntern;
  RobotomyRequestForm *rrf = (RobotomyRequestForm *)someRandomIntern.makeForm(
      "robotomy request", "Bender");
  std::string actual = getInsertionCapturedStdout(rrf);
  std::string expect =
      "_name: RobotomyRequestForm\n_target: Bender\n_isSigned: "
      "0\n_gradeToSign: 72\n_gradeToExec: 45\n";
  EXPECT_EQ(expect, actual);
}

// Intern::makeForm()の第一引数に"presidential
// pardon"を指定するとPresidentialPardonFormクラスのオブジェクトが作られる
TEST(MakeFormTest, MakePresidentialPardonFormTest) {
  Intern someRandomIntern;
  PresidentialPardonForm *ppf =
      (PresidentialPardonForm *)someRandomIntern.makeForm("presidential pardon",
                                                          "Bender");
  std::string actual = getInsertionCapturedStdout(ppf);
  std::string expect =
      "_name: PresidentialPardonForm\n_target: Bender\n_isSigned: "
      "0\n_gradeToSign: 25\n_gradeToExec: 5\n";
  EXPECT_EQ(expect, actual);
}

// Intern::makeForm()の第一引数に不当な値を指定すると例外が投げられる
TEST(MakeFormTest, MakeFormThrowTest) {
  Intern someRandomIntern;
  EXPECT_THROW(someRandomIntern.makeForm("noForm", "Bender"),
               Intern::NoFormExpception);
  EXPECT_THROW(someRandomIntern.makeForm("hogeForm", "Bender"),
               Intern::NoFormExpception);
  EXPECT_THROW(someRandomIntern.makeForm("fugaForm", "Bender"),
               Intern::NoFormExpception);
  EXPECT_THROW(someRandomIntern.makeForm("piyoForm", "Bender"),
               Intern::NoFormExpception);
  EXPECT_THROW(someRandomIntern.makeForm("fooForm", "Bender"),
               Intern::NoFormExpception);
  EXPECT_THROW(someRandomIntern.makeForm("barForm", "Bender"),
               Intern::NoFormExpception);
  EXPECT_THROW(someRandomIntern.makeForm("fizzForm", "Bender"),
               Intern::NoFormExpception);
  EXPECT_THROW(someRandomIntern.makeForm("buzzForm", "Bender"),
               Intern::NoFormExpception);
  EXPECT_THROW(someRandomIntern.makeForm("fizzbuzzForm", "Bender"),
               Intern::NoFormExpception);
}
