#include <gtest/gtest.h>
#include "Intern.hpp"

// Intern::makeForm()の第一引数に"robotomy request"を指定するとRobotomyRequestFormクラスのオブジェクトが作られる
TEST(MakeFormTest, MakeRobotomyRequestFormTest) {
	Intern someRandomIntern;
	RobotomyRequestForm* rrf = (RobotomyRequestForm *)someRandomIntern.makeForm("robotomy request", "Bender");
	testing::internal::CaptureStdout();
	std::cout << rrf;
	std::string actual = testing::internal::GetCapturedStdout();
	std::string expect = "_name: " + rrf->getName() + "\n_target: " + rrf->getTarget() +
      "\n_isSigned: " + intToString(rrf->getIsSigned()) +
      "\n_gradeToSign: " + intToString(rrf->getGradeToSign()) +
      "\n_gradeToExec: " + intToString(rrf->getGradeToExec()) + "\n";
}
