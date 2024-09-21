#include <gtest/gtest.h>

#include <fstream>  //  for File I/O

#include "PresidentialPardonForm.hpp"

class PresidentialPardonFormTest : public ::testing::Test {
 protected:
  // テストの前に実行される処理
  void SetUp() override {
    // テスト用にPresidentialPardonFormオブジェクトを初期化
    ppform = new PresidentialPardonForm(DEFAULT_TARGET);
  }
  // テストの後に実行される処理
  void TearDown() override { delete ppform; }
  // テストで使うメンバ変数
  PresidentialPardonForm* ppform;
};

// AFormクラスを継承するPresidentialPardonFormクラスが存在する
TEST(PresidentialPardonFormAttributeTest, inheritAFromTest) {
  PresidentialPardonForm* defaultName = new PresidentialPardonForm();
  EXPECT_EQ(defaultName->getName(), PRESIDENTIAL_PARDON_FORM_NAME);
  EXPECT_EQ(defaultName->getGradeToSign(),
            PRESIDENTIAL_PARDON_FORM_GRADE_TO_SIGN);
  EXPECT_EQ(defaultName->getGradeToExec(),
            PRESIDENTIAL_PARDON_FORM_GRADE_TO_EXEC);
  delete defaultName;

  PresidentialPardonForm* byConstructor =
      new PresidentialPardonForm("byConstructor");
  EXPECT_EQ(byConstructor->getName(), PRESIDENTIAL_PARDON_FORM_NAME);
  EXPECT_EQ(byConstructor->getGradeToSign(),
            PRESIDENTIAL_PARDON_FORM_GRADE_TO_SIGN);
  EXPECT_EQ(byConstructor->getGradeToExec(),
            PRESIDENTIAL_PARDON_FORM_GRADE_TO_EXEC);
  delete byConstructor;
}

// PresidentialPardonFormクラスが_targetを持つ
TEST(PresidentialPardonFormAttributeTest, targetTest) {
  PresidentialPardonForm* defaultName = new PresidentialPardonForm();
  EXPECT_EQ(defaultName->getTarget(), DEFAULT_TARGET);
  delete defaultName;

  PresidentialPardonForm* byConstructor =
      new PresidentialPardonForm("byConstructor");
  EXPECT_EQ(byConstructor->getTarget(), "byConstructor");
  delete byConstructor;
}

// PresidentialPardonFormクラスがexecuteメソッドを持つ
TEST_F(PresidentialPardonFormTest, executeTest) {
  const std::string generatedFilePath = ppform->getTarget() + "_shrubbery";
  const std::string outfile = generatedFilePath;
  Bureaucrat* gradeOKSigner = new Bureaucrat("gradeOKSigner", 5);
  Bureaucrat* gradeTooLowSigner = new Bureaucrat("gradeTooLowSigner", 21);

  // 実行できる
  testing::internal::CaptureStdout();
  ppform->setIsSigned(true);
  EXPECT_NO_THROW(ppform->execute(*gradeOKSigner));
  const std::string actual = testing::internal::GetCapturedStdout();
  const std::string expect = PARDON(ppform->getTarget());
  EXPECT_EQ(actual, expect);

  // 実行できない(未署名のため)
  ppform->setIsSigned(false);
  EXPECT_THROW(ppform->execute(*gradeOKSigner), AForm::NoSignException);

  // 実行できない(grade不足のため)
  ppform->setIsSigned(true);
  EXPECT_THROW(ppform->execute(*gradeTooLowSigner),
               Bureaucrat::GradeTooLowException);

  delete gradeOKSigner;
  delete gradeTooLowSigner;
}

// std::cout << ppform
TEST_F(PresidentialPardonFormTest, InsertionTest) {
  testing::internal::CaptureStdout();
  std::cout << ppform;
  std::string actual = testing::internal::GetCapturedStdout();
  std::string expect =
      "_name: " + ppform->getName() + "\n_target: " + ppform->getTarget() +
      "\n_isSigned: " + intToString(ppform->getIsSigned()) +
      "\n_gradeToSign: " + intToString(ppform->getGradeToSign()) +
      "\n_gradeToExec: " + intToString(ppform->getGradeToExec());

  EXPECT_EQ(actual, expect);
}
