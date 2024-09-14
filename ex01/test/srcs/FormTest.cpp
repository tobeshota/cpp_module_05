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
