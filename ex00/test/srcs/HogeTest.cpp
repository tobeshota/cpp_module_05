#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HogeTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

// Basic Addition Test
TEST(HogeTest, Addition) {
  int a = 2;
  int b = 3;
  EXPECT_EQ(a + b, 5);
}
