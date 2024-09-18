#include <gtest/gtest.h>

// スマートポインタ．スコープを抜けると、自動的にメモリが解放されるポインタ
#include <memory>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// Bureaucratのテストクラス(テストフィクスチャクラス)
class BureaucratTest : public ::testing::Test {
 protected:
  // テストの前に実行される処理
  void SetUp() override {
    // テスト用にBureaucratオブジェクトを初期化
    bureaucrat = new Bureaucrat(DEFAULT_NAME, DEFAULT_GRADE);
  }
  // テストの後に実行される処理
  void TearDown() override { delete bureaucrat; }
  // テストで使うメンバ変数
  Bureaucrat* bureaucrat;
};

// Bureaucratがnameを持つ
TEST(BureaucratAttributeTest, nameTest) {
  Bureaucrat* defaultName = new Bureaucrat();
  EXPECT_EQ(defaultName->getName(), DEFAULT_NAME);
  delete defaultName;

  Bureaucrat* byConstructor = new Bureaucrat("byConstructor", 20);
  EXPECT_EQ(byConstructor->getName(), "byConstructor");
  delete byConstructor;
}

// Bureaucratがgradeを持つ
TEST(BureaucratAttributeTest, gradeTest) {
  Bureaucrat* defaultGrade = new Bureaucrat();
  EXPECT_EQ(defaultGrade->getGrade(), DEFAULT_GRADE);
  delete defaultGrade;

  Bureaucrat* byConstructor = new Bureaucrat("byConstructor", 20);
  EXPECT_EQ(byConstructor->getGrade(), 20);
  delete byConstructor;

  Bureaucrat* byMethod = new Bureaucrat();
  byMethod->setGradeSafely(50);
  EXPECT_EQ(byMethod->getGrade(), 50);
  delete byMethod;
}

// _gradeが1より小さくなると例外が飛ぶ
TEST_F(BureaucratTest, gradeTooHighTest) {
  int tooHighGrade = HIGHEST_POSSIBLE_GRADE - 1;

  // スローされる
  EXPECT_THROW(bureaucrat->setGradeSafely(tooHighGrade),
               Bureaucrat::GradeTooHighException);
}

// _gradeが150より大きくなると例外が飛ぶ
TEST_F(BureaucratTest, GradeTooLowTest) {
  int tooLowGrade = LOWEST_POSSIBLE_GRADE + 1;

  // スローされる
  EXPECT_THROW(bureaucrat->setGradeSafely(tooLowGrade),
               Bureaucrat::GradeTooLowException);
  EXPECT_THROW(bureaucrat->decrementGrade(),
               Bureaucrat::GradeTooLowException);  //  初期値(150) + 1
}

// _gradeが1~150の範囲内のとき例外が飛ばない
TEST_F(BureaucratTest, GradeOKTest) {
  // スローされない
  EXPECT_NO_THROW(bureaucrat->setGradeSafely(42));
  EXPECT_NO_THROW(bureaucrat->setGradeSafely(HIGHEST_POSSIBLE_GRADE));
  EXPECT_NO_THROW(bureaucrat->setGradeSafely(LOWEST_POSSIBLE_GRADE));
  EXPECT_NO_THROW(bureaucrat->incrementGrade());  //  初期値(150) - 1
}

// 標準出力の内容を確認するテスト
TEST_F(BureaucratTest, InsertionTest) {
  // 標準出力をキャプチャ開始
  testing::internal::CaptureStdout();

  // テスト対象の関数を呼び出す
  std::cout << bureaucrat;

  // 標準出力のキャプチャ結果を取得
  std::string actual = testing::internal::GetCapturedStdout();
  // 望まれる標準出力を定義
  std::string expect = bureaucrat->getName() + ", bureaucrat grade " +
                       intToString(bureaucrat->getGrade()) + "\n";

  // 出力が"hello world"であることを確認
  EXPECT_EQ(actual, expect);
}

// BureaucratがsignForm()を持つ
TEST(BureaucratMethodTest, signFormTest) {
  ShrubberyCreationForm* scform = new ShrubberyCreationForm("scform");
  Bureaucrat* gradeOKSigner = new Bureaucrat("gradeOKSigner", 145);
  Bureaucrat* gradeTooLowSigner = new Bureaucrat("gradeTooLowSigner", 150);

  // gradeOKSigner(grade: 145) signed scform(required grades to sign: 145)
  testing::internal::CaptureStdout();
  gradeOKSigner->signForm(*scform);
  std::string actualA = testing::internal::GetCapturedStdout();
  std::string expectA =
      gradeOKSigner->getName() + " signed " + scform->getName() + "\n";
  EXPECT_EQ(actualA, expectA);

  // gradeTooLowSigner(grade: 150) cannot sign scform(required grades to sign:
  // 145)
  EXPECT_THROW(gradeTooLowSigner->signForm(*scform),
               ShrubberyCreationForm::GradeTooLowException);

  // gradeOKSigner(grade: 145) couldn't sign scform(required grades to sign:
  // 145) because scform has already signed
  testing::internal::CaptureStdout();
  scform->setIsSigned(true);
  gradeOKSigner->signForm(*scform);
  std::string actualB = testing::internal::GetCapturedStdout();
  std::string expectB = gradeOKSigner->getName() + " couldn't sign " +
                        scform->getName() + " because is has already signed\n";
  EXPECT_EQ(actualB, expectB);
  delete scform;
  delete gradeOKSigner;
  delete gradeTooLowSigner;
}

// BureaucratがexecuteForm()を持つ
/**Required grades:
 * ShrubberyCreationForm:  sign 145, exec 137
 * RobotomyRequestForm:    sign 72,  exec 45
 * PresidentialPardonForm: sign 25,  exec 5
 */
TEST(BureaucratMethodTest, executeFormTest) {
  // 変数宣言
  Bureaucrat* grade50 = new Bureaucrat("grade50", 50);
  ShrubberyCreationForm* scform = new ShrubberyCreationForm();
  RobotomyRequestForm* rrform = new RobotomyRequestForm();
  // 実行できる
  grade50->signForm(*scform);
  testing::internal::CaptureStdout();
  EXPECT_NO_THROW(grade50->executeForm(*scform));
  std::string actualA = testing::internal::GetCapturedStdout();
  std::string expectA =
      grade50->getName() + " executed " + scform->getName() + "\n";
  EXPECT_EQ(actualA, expectA);

  // 実行できない(未署名のため)
  scform->setIsSigned(false);
  EXPECT_THROW(grade50->executeForm(*scform), AForm::NoSignException);

  // 実行できない(grade不足のため)
  EXPECT_NO_THROW(grade50->signForm(*rrform));
  EXPECT_THROW(grade50->executeForm(*rrform), Bureaucrat::GradeTooLowException);

  delete grade50;
  delete scform;
  delete rrform;
}
