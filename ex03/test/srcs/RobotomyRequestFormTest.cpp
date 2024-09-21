#include <gtest/gtest.h>

#include <fstream>  //  for File I/O

#include "RobotomyRequestForm.hpp"

class RobotomyRequestFormTest : public ::testing::Test {
 protected:
  // テストの前に実行される処理
  void SetUp() override {
    // テスト用にRobotomyRequestFormオブジェクトを初期化
    rrform = new RobotomyRequestForm(DEFAULT_TARGET);
  }
  // テストの後に実行される処理
  void TearDown() override { delete rrform; }
  // テストで使うメンバ変数
  RobotomyRequestForm* rrform;
};

// AFormクラスを継承するRobotomyRequestFormクラスが存在する
TEST(RobotomyRequestFormAttributeTest, inheritAFromTest) {
  RobotomyRequestForm* defaultName = new RobotomyRequestForm();
  EXPECT_EQ(defaultName->getName(), ROBOTOMY_REQUEST_FORM_NAME);
  EXPECT_EQ(defaultName->getGradeToSign(), ROBOTOMY_REQUEST_FORM_GRADE_TO_SIGN);
  EXPECT_EQ(defaultName->getGradeToExec(), ROBOTOMY_REQUEST_FORM_GRADE_TO_EXEC);
  delete defaultName;

  RobotomyRequestForm* byConstructor = new RobotomyRequestForm("byConstructor");
  EXPECT_EQ(byConstructor->getName(), ROBOTOMY_REQUEST_FORM_NAME);
  EXPECT_EQ(byConstructor->getGradeToSign(),
            ROBOTOMY_REQUEST_FORM_GRADE_TO_SIGN);
  EXPECT_EQ(byConstructor->getGradeToExec(),
            ROBOTOMY_REQUEST_FORM_GRADE_TO_EXEC);
  delete byConstructor;
}

// RobotomyRequestFormクラスが_targetを持つ
TEST(RobotomyRequestFormAttributeTest, targetTest) {
  RobotomyRequestForm* defaultName = new RobotomyRequestForm();
  EXPECT_EQ(defaultName->getTarget(), DEFAULT_TARGET);

  RobotomyRequestForm* byConstructor = new RobotomyRequestForm("byConstructor");
  EXPECT_EQ(byConstructor->getTarget(), "byConstructor");
  delete byConstructor;
}

// RobotomyRequestFormクラスがexecuteメソッドを持つ
TEST_F(RobotomyRequestFormTest, executeTest) {
  const std::string generatedFilePath = rrform->getTarget() + "_shrubbery";
  const std::string outfile = generatedFilePath;
  Bureaucrat* gradeOKSigner = new Bureaucrat("gradeOKSigner", 42);
  Bureaucrat* gradeTooLowSigner = new Bureaucrat("gradeTooLowSigner", 48);

  // 実行できる
  testing::internal::CaptureStdout();
  rrform->setIsSigned(true);
  EXPECT_NO_THROW(rrform->execute(*gradeOKSigner));
  const std::string actual = testing::internal::GetCapturedStdout();
  bool contains_success =
      actual.find(SUCCESS_MSG(rrform->getTarget())) != std::string::npos;
  bool contains_failure =
      actual.find(FAILURE_MSG(rrform->getTarget())) != std::string::npos;
  EXPECT_TRUE(contains_success || contains_failure);

  // 実行できない(未署名のため)
  rrform->setIsSigned(false);
  EXPECT_THROW(rrform->execute(*gradeOKSigner), AForm::NoSignException);

  // 実行できない(grade不足のため)
  rrform->setIsSigned(true);
  EXPECT_THROW(rrform->execute(*gradeTooLowSigner),
               Bureaucrat::GradeTooLowException);

  delete gradeOKSigner;
  delete gradeTooLowSigner;
}

// std::cout << rrform
TEST_F(RobotomyRequestFormTest, InsertionTest) {
  testing::internal::CaptureStdout();
  std::cout << rrform;
  std::string actual = testing::internal::GetCapturedStdout();
  std::string expect =
      "_name: " + rrform->getName() + "\n_target: " + rrform->getTarget() +
      "\n_isSigned: " + intToString(rrform->getIsSigned()) +
      "\n_gradeToSign: " + intToString(rrform->getGradeToSign()) +
      "\n_gradeToExec: " + intToString(rrform->getGradeToExec());

  EXPECT_EQ(actual, expect);
}
