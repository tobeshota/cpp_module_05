#include <gtest/gtest.h>

#include <memory>  // スマートポインタ．スコープを抜けると、自動的にメモリが解放されるポインタ

#include "Bureaucrat.hpp"

// Bureaucratがnameを持つ
TEST(BureaucratTest, nameTest) {
  std::unique_ptr<Bureaucrat> defaultName = std::make_unique<Bureaucrat>();
  EXPECT_EQ(defaultName->getName(), DEFAULT_NAME);

  Bureaucrat* NamedByConstructor = new Bureaucrat("NamedByConstructor", 20);
  EXPECT_EQ(NamedByConstructor->getName(), "NamedByConstructor");

  std::unique_ptr<Bureaucrat> NamedbyMethod = std::make_unique<Bureaucrat>();
  NamedbyMethod->setName("NamedByConstructor");
  EXPECT_EQ(NamedbyMethod->getName(), "NamedByConstructor");

  delete NamedByConstructor;
}

// Bureaucratがgradeを持つ
