#include <gtest/gtest.h>

#include <fstream>  //  for File I/O
#include <memory>

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
  std::unique_ptr<RobotomyRequestForm> defaultName =
      std::make_unique<RobotomyRequestForm>();
  EXPECT_EQ(defaultName->getName(), ROBOTOMY_REQUEST_FORM_NAME);
  EXPECT_EQ(defaultName->getGradeToSign(), ROBOTOMY_REQUEST_FORM_GRADE_TO_SIGN);
  EXPECT_EQ(defaultName->getGradeToExec(), ROBOTOMY_REQUEST_FORM_GRADE_TO_EXEC);

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
  std::unique_ptr<RobotomyRequestForm> defaultName =
      std::make_unique<RobotomyRequestForm>();
  EXPECT_EQ(defaultName->getTarget(), DEFAULT_TARGET);

  RobotomyRequestForm* byConstructor = new RobotomyRequestForm("byConstructor");
  EXPECT_EQ(byConstructor->getTarget(), "byConstructor");
  delete byConstructor;
}

// RobotomyRequestFormクラスが_targetを持つ
// TEST_F(RobotomyRequestFormTest, executeTest) {
//   const std::string generatedFilePath = rrform->getTarget() + "_shrubbery";
//   const std::string outfile = generatedFilePath;
//   Bureaucrat* gradeOKSigner = new Bureaucrat("gradeOKSigner", 130);
//   Bureaucrat* gradeTooLowSigner = new Bureaucrat("gradeTooLowSigner", 150);

//   delete gradeOKSigner;
//   delete gradeTooLowSigner;
// }
