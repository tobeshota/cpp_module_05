#include <gtest/gtest.h>

#include <memory>

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Formのテストクラス(テストフィクスチャクラス)
class FormTest : public ::testing::Test {
 protected:
  // テストの前に実行される処理
  void SetUp() override {
    // テスト用にFormオブジェクトを初期化
    form = new Form();
  }
  // テストの後に実行される処理
  void TearDown() override { delete form; }
  // テストで使うメンバ変数
  Form* form;
};

// Formが_nameを持つ
TEST(FormAttributeTest, nameTest) {
  std::unique_ptr<Form> defaultName = std::make_unique<Form>();
  EXPECT_EQ(defaultName->getName(), DEFAULT_NAME);

  Form* byConstructor = new Form("byConstructor", 20, 50);
  EXPECT_EQ(byConstructor->getName(), "byConstructor");
  delete byConstructor;
}

// Formが_isSignedを持つ
TEST(FormAttributeTest, isSignedTest) {
  std::unique_ptr<Form> defaultIsSigned = std::make_unique<Form>();
  EXPECT_EQ(defaultIsSigned->getIsSigned(), DEFAULT_IS_SIGNED);
}

// Formが_gradeToSignを持つ
TEST(FormAttributeTest, gradeToSignTest) {
  std::unique_ptr<Form> defaultGradeToSign = std::make_unique<Form>();
  EXPECT_EQ(defaultGradeToSign->getGradeToSign(), DEFAULT_GRADE_TO_SIGN);

  Form* byConstructor = new Form("byConstructor", 20, 50);
  EXPECT_EQ(byConstructor->getGradeToSign(), 20);
  delete byConstructor;
}

// Formが_gradeToExecを持つ
TEST(FormAttributeTest, gradeToExecTest) {
  std::unique_ptr<Form> defaultGradeToExec = std::make_unique<Form>();
  EXPECT_EQ(defaultGradeToExec->getGradeToExec(), DEFAULT_GRADE_TO_EXEC);

  Form* byConstructor = new Form("byConstructor", 20, 50);
  EXPECT_EQ(byConstructor->getGradeToExec(), 50);
  delete byConstructor;
}

// Test to ensure the constructor throws an exception for invalid input
TEST(FormExceptionTest, gradeTooHighTest) {
  const int tooHigh = HIGHEST_POSSIBLE_GRADE - 1;

  EXPECT_THROW(Form(DEFAULT_NAME, tooHigh, DEFAULT_GRADE_TO_EXEC),
               Form::GradeTooHighException);
  EXPECT_THROW(Form(DEFAULT_NAME, DEFAULT_GRADE_TO_SIGN, tooHigh),
               Form::GradeTooHighException);
  EXPECT_THROW(Form(DEFAULT_NAME, tooHigh, tooHigh),
               Form::GradeTooHighException);
}

// _gradeToSignが150より大きくなると例外が飛ぶ
// TEST_F(FormTest, gradeTooHighTest) {
//   int tooHighGrade = HIGHEST_POSSIBLE_GRADE - 1;

//   // スローされる
//   EXPECT_THROW(form->setGradeSafely(tooHighGrade),
//                Bureaucrat::GradeTooHighException);
// }
