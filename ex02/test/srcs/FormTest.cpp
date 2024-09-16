#include <gtest/gtest.h>

#include <memory>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// AFormのテストクラス(テストフィクスチャクラス)
class AFormTest : public ::testing::Test {
 protected:
  // テストの前に実行される処理
  void SetUp() override {
    // テスト用にAFormオブジェクトを初期化
    form = new AForm();
  }
  // テストの後に実行される処理
  void TearDown() override { delete form; }
  // テストで使うメンバ変数
  AForm* form;
};

// AFormが_nameを持つ
TEST(AFormAttributeTest, nameTest) {
  std::unique_ptr<AForm> defaultName = std::make_unique<AForm>();
  EXPECT_EQ(defaultName->getName(), DEFAULT_NAME);

  AForm* byConstructor = new AForm("byConstructor", 20, 50);
  EXPECT_EQ(byConstructor->getName(), "byConstructor");
  delete byConstructor;
}

// AFormが_isSignedを持つ
TEST(AFormAttributeTest, isSignedTest) {
  std::unique_ptr<AForm> defaultIsSigned = std::make_unique<AForm>();
  EXPECT_EQ(defaultIsSigned->getIsSigned(), DEFAULT_IS_SIGNED);
}

// AFormが_gradeToSignを持つ
TEST(AFormAttributeTest, gradeToSignTest) {
  std::unique_ptr<AForm> defaultGradeToSign = std::make_unique<AForm>();
  EXPECT_EQ(defaultGradeToSign->getGradeToSign(), DEFAULT_GRADE_TO_SIGN);

  AForm* byConstructor = new AForm("byConstructor", 20, 50);
  EXPECT_EQ(byConstructor->getGradeToSign(), 20);
  delete byConstructor;
}

// AFormが_gradeToExecを持つ
TEST(AFormAttributeTest, gradeToExecTest) {
  std::unique_ptr<AForm> defaultGradeToExec = std::make_unique<AForm>();
  EXPECT_EQ(defaultGradeToExec->getGradeToExec(), DEFAULT_GRADE_TO_EXEC);

  AForm* byConstructor = new AForm("byConstructor", 20, 50);
  EXPECT_EQ(byConstructor->getGradeToExec(), 50);
  delete byConstructor;
}

// _gradeToSignが150より大きくなると例外が飛ぶ
// _gradeToExecが1より小さくなると例外が飛ぶ
TEST(AFormExceptionTest, gradeTooHighTest) {
  const int tooHigh = HIGHEST_POSSIBLE_GRADE - 1;

  EXPECT_THROW(AForm(DEFAULT_NAME, tooHigh, DEFAULT_GRADE_TO_EXEC),
               AForm::GradeTooHighException);
  EXPECT_THROW(AForm(DEFAULT_NAME, DEFAULT_GRADE_TO_SIGN, tooHigh),
               AForm::GradeTooHighException);
  EXPECT_THROW(AForm(DEFAULT_NAME, tooHigh, tooHigh),
               AForm::GradeTooHighException);
}

// _gradeToSignが150より大きくなると例外が飛ぶ
// _gradeToExecが150より大きくなると例外が飛ぶ
TEST(AFormExceptionTest, gradeTooLowTest) {
  const int tooLow = LOWEST_POSSIBLE_GRADE + 1;

  EXPECT_THROW(AForm(DEFAULT_NAME, tooLow, DEFAULT_GRADE_TO_EXEC),
               AForm::GradeTooLowException);
  EXPECT_THROW(AForm(DEFAULT_NAME, DEFAULT_GRADE_TO_SIGN, tooLow),
               AForm::GradeTooLowException);
  EXPECT_THROW(AForm(DEFAULT_NAME, tooLow, tooLow),
               AForm::GradeTooLowException);
}

// _gradeToSignが1~150の範囲内のとき例外が飛ばない
// _gradeToExecが1~150の範囲内のとき例外が飛ばない
TEST(AFormExceptionTest, GradeOKTest) {
  EXPECT_NO_THROW(
      AForm(DEFAULT_NAME, DEFAULT_GRADE_TO_SIGN, DEFAULT_GRADE_TO_EXEC));
  EXPECT_NO_THROW(
      AForm(DEFAULT_NAME, HIGHEST_POSSIBLE_GRADE, DEFAULT_GRADE_TO_EXEC));
  EXPECT_NO_THROW(
      AForm(DEFAULT_NAME, DEFAULT_GRADE_TO_SIGN, HIGHEST_POSSIBLE_GRADE));
  EXPECT_NO_THROW(
      AForm(DEFAULT_NAME, HIGHEST_POSSIBLE_GRADE, HIGHEST_POSSIBLE_GRADE));
  EXPECT_NO_THROW(
      AForm(DEFAULT_NAME, LOWEST_POSSIBLE_GRADE, DEFAULT_GRADE_TO_EXEC));
  EXPECT_NO_THROW(
      AForm(DEFAULT_NAME, DEFAULT_GRADE_TO_SIGN, LOWEST_POSSIBLE_GRADE));
  EXPECT_NO_THROW(
      AForm(DEFAULT_NAME, LOWEST_POSSIBLE_GRADE, LOWEST_POSSIBLE_GRADE));
}

// std::cout << form
TEST_F(AFormTest, InsertionTest) {
  testing::internal::CaptureStdout();

  std::cout << form;

  std::string actual = testing::internal::GetCapturedStdout();
  std::string expect =
      "_name: " + form->getName() +
      "\n_isSigned: " + intToString(form->getIsSigned()) +
      "\n_gradeToSign: " + intToString(form->getGradeToSign()) +
      "\n_gradeToExec" + intToString(form->getGradeToExec());

  EXPECT_EQ(actual, expect);
}

// AFormがbeSigined()を持つ
TEST(AFormMethodTest, beSignedTest) {
  // signerA(grade: 20) can sign formA(grade: 20)
  AForm* formA = new AForm("formA", 20, DEFAULT_GRADE_TO_EXEC);
  Bureaucrat* signerA = new Bureaucrat("signerA", 20);
  EXPECT_NO_THROW(formA->beSigned(*signerA));

  // signerA(grade: 20) cannot sign formB(grade: 15)
  AForm* formB = new AForm("formB", 15, DEFAULT_GRADE_TO_EXEC);
  EXPECT_THROW(formB->beSigned(*signerA), AForm::GradeTooLowException);

  delete formA;
  delete formB;
  delete signerA;
}
