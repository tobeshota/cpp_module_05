#include <gtest/gtest.h>
#include <memory>  // スマートポインタ．スコープを抜けると、自動的にメモリが解放されるポインタ
#include "Bureaucrat.hpp"

// Bureaucratがnameを持つ
TEST(BureaucratAttributeTest, nameTest) {
  std::unique_ptr<Bureaucrat> defaultName = std::make_unique<Bureaucrat>();
  EXPECT_EQ(defaultName->getName(), DEFAULT_NAME);

  Bureaucrat* byConstructor = new Bureaucrat("byConstructor", 20);
  EXPECT_EQ(byConstructor->getName(), "byConstructor");
  delete byConstructor;

  std::unique_ptr<Bureaucrat> byMethod = std::make_unique<Bureaucrat>();
  byMethod->setName("byMethod");
  EXPECT_EQ(byMethod->getName(), "byMethod");
}

// Bureaucratがgradeを持つ
TEST(BureaucratAttributeTest, gradeTest) {
  std::unique_ptr<Bureaucrat> defaultName = std::make_unique<Bureaucrat>();
  EXPECT_EQ(defaultName->getGrade(), DEFAULT_GRADE);

  Bureaucrat* byConstructor = new Bureaucrat("byConstructor", 20);
  EXPECT_EQ(byConstructor->getGrade(), 200);
  delete byConstructor;

  std::unique_ptr<Bureaucrat> byMethod = std::make_unique<Bureaucrat>();
  byMethod->setGrade(50);
  EXPECT_EQ(byMethod->getGrade(), 50);
}
