#include <gtest/gtest.h>

#include "Sample.hpp"

TEST(SampleTest, HelloSample) {
  Sample hoge;
  EXPECT_EQ("hello", "hello");
}
