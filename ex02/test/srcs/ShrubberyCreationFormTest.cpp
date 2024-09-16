#include <gtest/gtest.h>

#include <memory>

#include "ShrubberyCreationForm.hpp"

// AFormクラスを継承するShrubberyCreationFormクラスが存在する
TEST(ShruberryCreationFormAttributeTest, inheritAFromTest) {
  std::unique_ptr<ShrubberyCreationForm> defaultName =
      std::make_unique<ShrubberyCreationForm>();
  EXPECT_EQ(defaultName->getName(), SHRUBBERY_CREATION_FORM_NAME);
  EXPECT_EQ(defaultName->getGradeToSign(),
            SHRUBBERY_CREATION_FORM_GRADE_TO_SIGN);
  EXPECT_EQ(defaultName->getGradeToExec(),
            SHRUBBERY_CREATION_FORM_GRADE_TO_EXEC);

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
  std::unique_ptr<ShrubberyCreationForm> defaultName =
      std::make_unique<ShrubberyCreationForm>();
  EXPECT_EQ(defaultName->getTarget(), DEFAULT_TARGET);

  ShrubberyCreationForm* byConstructor =
      new ShrubberyCreationForm("byConstructor");
  EXPECT_EQ(byConstructor->getTarget(), "byConstructor");
  delete byConstructor;
}
