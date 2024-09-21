#include <gtest/gtest.h>

#include <fstream>  //  for File I/O

#include "ShrubberyCreationForm.hpp"

class ShrubberyCreationFormTest : public ::testing::Test {
 protected:
  // テストの前に実行される処理
  void SetUp() override {
    // テスト用にShrubberyCreationFormオブジェクトを初期化
    scform = new ShrubberyCreationForm(DEFAULT_TARGET);
  }
  // テストの後に実行される処理
  void TearDown() override { delete scform; }
  // テストで使うメンバ変数
  ShrubberyCreationForm* scform;
};

// AFormクラスを継承するShrubberyCreationFormクラスが存在する
TEST(ShruberryCreationFormAttributeTest, inheritAFromTest) {
  ShrubberyCreationForm* defaultName = new ShrubberyCreationForm();
  EXPECT_EQ(defaultName->getName(), SHRUBBERY_CREATION_FORM_NAME);
  EXPECT_EQ(defaultName->getGradeToSign(),
            SHRUBBERY_CREATION_FORM_GRADE_TO_SIGN);
  EXPECT_EQ(defaultName->getGradeToExec(),
            SHRUBBERY_CREATION_FORM_GRADE_TO_EXEC);
  delete defaultName;

  ShrubberyCreationForm* byConstructor =
      new ShrubberyCreationForm("byConstructor");
  EXPECT_EQ(byConstructor->getName(), SHRUBBERY_CREATION_FORM_NAME);
  EXPECT_EQ(byConstructor->getGradeToSign(),
            SHRUBBERY_CREATION_FORM_GRADE_TO_SIGN);
  EXPECT_EQ(byConstructor->getGradeToExec(),
            SHRUBBERY_CREATION_FORM_GRADE_TO_EXEC);
  delete byConstructor;
}

// ShrubberyCreationFormクラスが_targetを持つ
TEST(ShruberryCreationFormAttributeTest, targetTest) {
  ShrubberyCreationForm* defaultName = new ShrubberyCreationForm();
  EXPECT_EQ(defaultName->getTarget(), DEFAULT_TARGET);

  ShrubberyCreationForm* byConstructor =
      new ShrubberyCreationForm("byConstructor");
  EXPECT_EQ(byConstructor->getTarget(), "byConstructor");
  delete byConstructor;
}

// ShrubberyCreationFormクラスがexecuteメソッドを持つ
TEST_F(ShrubberyCreationFormTest, executeTest) {
  const std::string generatedFilePath = scform->getTarget() + "_shrubbery";
  std::ifstream outfile(generatedFilePath);
  // const std::string outfile = generatedFilePath;
  Bureaucrat* gradeOKSigner = new Bureaucrat("gradeOKSigner", 130);
  Bureaucrat* gradeTooLowSigner = new Bureaucrat("gradeTooLowSigner", 150);

  // 実行できる
  scform->setIsSigned(true);
  EXPECT_NO_THROW(scform->execute(*gradeOKSigner));
  EXPECT_TRUE(outfile.good());
  std::ifstream infile(generatedFilePath);
  EXPECT_TRUE(infile.is_open());  // ファイルが正しく開かれているかを確認する
  std::string actual_content((std::istreambuf_iterator<char>(infile)),
                             std::istreambuf_iterator<char>());
  EXPECT_EQ(actual_content, TREE);
  std::remove(generatedFilePath.c_str());

  // 実行できない(未署名のため)
  scform->setIsSigned(false);
  EXPECT_THROW(scform->execute(*gradeOKSigner), AForm::NoSignException);

  // 実行できない(grade不足のため)
  scform->setIsSigned(true);
  EXPECT_THROW(scform->execute(*gradeTooLowSigner),
               Bureaucrat::GradeTooLowException);
  EXPECT_TRUE(outfile.good());

  delete gradeOKSigner;
  delete gradeTooLowSigner;
}

// std::cout << scform
TEST_F(ShrubberyCreationFormTest, InsertionTest) {
  testing::internal::CaptureStdout();
  std::cout << scform;
  std::string actual = testing::internal::GetCapturedStdout();
  std::string expect =
      "_name: " + scform->getName() + "\n_target: " + scform->getTarget() +
      "\n_isSigned: " + intToString(scform->getIsSigned()) +
      "\n_gradeToSign: " + intToString(scform->getGradeToSign()) +
      "\n_gradeToExec" + intToString(scform->getGradeToExec());

  EXPECT_EQ(actual, expect);
}
