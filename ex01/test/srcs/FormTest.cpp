#include <gtest/gtest.h>

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
  Form* defaultName = new Form();
  EXPECT_EQ(defaultName->getName(), DEFAULT_NAME);
  delete defaultName;

  Form* byConstructor = new Form("byConstructor", 20, 50);
  EXPECT_EQ(byConstructor->getName(), "byConstructor");
  delete byConstructor;
}

// Formが_isSignedを持つ
TEST(FormAttributeTest, isSignedTest) {
  Form* defaultIsSigned = new Form();
  EXPECT_EQ(defaultIsSigned->getIsSigned(), DEFAULT_IS_SIGNED);
}

// Formが_gradeToSignを持つ
TEST(FormAttributeTest, gradeToSignTest) {
  Form* defaultGradeToSign = new Form();
  EXPECT_EQ(defaultGradeToSign->getGradeToSign(), DEFAULT_GRADE_TO_SIGN);

  Form* byConstructor = new Form("byConstructor", 20, 50);
  EXPECT_EQ(byConstructor->getGradeToSign(), 20);
  delete byConstructor;
}

// Formが_gradeToExecを持つ
TEST(FormAttributeTest, gradeToExecTest) {
  Form* defaultGradeToExec = new Form();
  EXPECT_EQ(defaultGradeToExec->getGradeToExec(), DEFAULT_GRADE_TO_EXEC);
  delete defaultGradeToExec;

  Form* byConstructor = new Form("byConstructor", 20, 50);
  EXPECT_EQ(byConstructor->getGradeToExec(), 50);
  delete byConstructor;
}

// _gradeToSignが150より大きくなると例外が飛ぶ
// _gradeToExecが1より小さくなると例外が飛ぶ
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
// _gradeToExecが150より大きくなると例外が飛ぶ
TEST(FormExceptionTest, gradeTooLowTest) {
  const int tooLow = LOWEST_POSSIBLE_GRADE + 1;

  EXPECT_THROW(Form(DEFAULT_NAME, tooLow, DEFAULT_GRADE_TO_EXEC),
               Form::GradeTooLowException);
  EXPECT_THROW(Form(DEFAULT_NAME, DEFAULT_GRADE_TO_SIGN, tooLow),
               Form::GradeTooLowException);
  EXPECT_THROW(Form(DEFAULT_NAME, tooLow, tooLow), Form::GradeTooLowException);
}

// _gradeToSignが1~150の範囲内のとき例外が飛ばない
// _gradeToExecが1~150の範囲内のとき例外が飛ばない
TEST(FormExceptionTest, GradeOKTest) {
  EXPECT_NO_THROW(
      Form(DEFAULT_NAME, DEFAULT_GRADE_TO_SIGN, DEFAULT_GRADE_TO_EXEC));
  EXPECT_NO_THROW(
      Form(DEFAULT_NAME, HIGHEST_POSSIBLE_GRADE, DEFAULT_GRADE_TO_EXEC));
  EXPECT_NO_THROW(
      Form(DEFAULT_NAME, DEFAULT_GRADE_TO_SIGN, HIGHEST_POSSIBLE_GRADE));
  EXPECT_NO_THROW(
      Form(DEFAULT_NAME, HIGHEST_POSSIBLE_GRADE, HIGHEST_POSSIBLE_GRADE));
  EXPECT_NO_THROW(
      Form(DEFAULT_NAME, LOWEST_POSSIBLE_GRADE, DEFAULT_GRADE_TO_EXEC));
  EXPECT_NO_THROW(
      Form(DEFAULT_NAME, DEFAULT_GRADE_TO_SIGN, LOWEST_POSSIBLE_GRADE));
  EXPECT_NO_THROW(
      Form(DEFAULT_NAME, LOWEST_POSSIBLE_GRADE, LOWEST_POSSIBLE_GRADE));
}

// std::cout << form
TEST_F(FormTest, InsertionTest) {
  testing::internal::CaptureStdout();

  std::cout << form;

  std::string actual = testing::internal::GetCapturedStdout();
  std::string expect =
      "_name: " + form->getName() +
      "\n_isSigned: " + intToString(form->getIsSigned()) +
      "\n_gradeToSign: " + intToString(form->getGradeToSign()) +
      "\n_gradeToExec: " + intToString(form->getGradeToExec()) + "\n";

  EXPECT_EQ(actual, expect);
}

// FormがbeSigined()を持つ
TEST(FormMethodTest, beSignedTest) {
  // signerA(grade: 20) can sign formA(grade: 20)
  Form* formA = new Form("formA", 20, DEFAULT_GRADE_TO_EXEC);
  Bureaucrat* signerA = new Bureaucrat("signerA", 20);
  EXPECT_NO_THROW(formA->beSigned(*signerA));

  // signerA(grade: 20) cannot sign formB(grade: 15)
  Form* formB = new Form("formB", 15, DEFAULT_GRADE_TO_EXEC);
  EXPECT_THROW(formB->beSigned(*signerA), Form::GradeTooLowException);

  delete formA;
  delete formB;
  delete signerA;
}
