#include <gtest/gtest.h>
#include "Intern.hpp"

// Intern::makeForm()がクラスを生成する
TEST(InternTest, MakeFormTest) {
	Intern someRandomIntern;
	RobotomyRequestForm* rrf = (RobotomyRequestForm *)someRandomIntern.makeForm("robotomy request", "Bender");
	testing::internal::CaptureStdout();
	std::cout << rrf;
	std::string actual = testing::internal::GetCapturedStdout();
	std::string expect = "_name: " + rrf->getName() + "\n_target" + rrf->getTarget() +
      "\n_isSigned: " + intToString(rrf->getIsSigned()) +
      "\n_gradeToSign: " + intToString(rrf->getGradeToSign()) +
      "\n_gradeToExec" + intToString(rrf->getGradeToExec());
}
