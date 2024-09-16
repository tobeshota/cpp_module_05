#include <gtest/gtest.h>

#include <memory>  // スマートポインタ．スコープを抜けると、自動的にメモリが解放されるポインタ

#include "Bureaucrat.hpp"

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
  std::unique_ptr<Bureaucrat> defaultName = std::make_unique<Bureaucrat>();
  EXPECT_EQ(defaultName->getName(), DEFAULT_NAME);

  Bureaucrat* byConstructor = new Bureaucrat("byConstructor", 20);
  EXPECT_EQ(byConstructor->getName(), "byConstructor");
  delete byConstructor;
}

// Bureaucratがgradeを持つ
TEST(BureaucratAttributeTest, gradeTest) {
  std::unique_ptr<Bureaucrat> defaultGrade = std::make_unique<Bureaucrat>();
  EXPECT_EQ(defaultGrade->getGrade(), DEFAULT_GRADE);

  Bureaucrat* byConstructor = new Bureaucrat("byConstructor", 20);
  EXPECT_EQ(byConstructor->getGrade(), 20);
  delete byConstructor;

  std::unique_ptr<Bureaucrat> byMethod = std::make_unique<Bureaucrat>();
  byMethod->setGradeSafely(50);
  EXPECT_EQ(byMethod->getGrade(), 50);
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

/* AFormが抽象クラスよりインスタンスを生成できないためコメントアウト
// BureaucratがsignAForm()を持つ
TEST(BureaucratMethodTest, beSignedTest) {
  AForm* formA = new AForm("formA", 20, DEFAULT_GRADE_TO_EXEC);
  AForm* formB = new AForm("formB", 15, DEFAULT_GRADE_TO_EXEC);
  Bureaucrat* signerA = new Bureaucrat("signerA", 20);
  Bureaucrat* signerB = new Bureaucrat("signerB", 20);

  // signerA(grade: 20) signed formA(grade: 20)
  testing::internal::CaptureStdout();
  signerA->signAForm(*formA);
  std::string actual = testing::internal::GetCapturedStdout();
  std::string expect =
      signerA->getName() + " signed " + formA->getName() + "\n";
  EXPECT_EQ(actual, expect);

  // signerA(grade: 20) cannot sign formB(grade: 15)
  EXPECT_THROW(signerA->signAForm(*formB), AForm::GradeTooLowException);

  // signerB(grade: 20) couldn't sign formA(grade: 20) because formA has already
  // signed
  testing::internal::CaptureStdout();
  formA->setIsSigned(true);
  signerB->signAForm(*formA);
  std::string actualB = testing::internal::GetCapturedStdout();
  std::string expectB = signerB->getName() + " couldn't sign " +
                        formA->getName() + " because is has already signed\n";
  EXPECT_EQ(actualB, expectB);
  delete formA;
  delete formB;
  delete signerA;
  delete signerB;
}
 */
