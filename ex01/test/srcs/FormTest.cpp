#include <gtest/gtest.h>

#include <memory>

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
