#include <gtest/gtest.h>

// String Comparison Test
TEST(HelloTest, StringComparison) {
  std::string str1 = "hello";
  std::string str2 = "hello";
  EXPECT_EQ(str1, str2);
}

// Array Content Test
TEST(HelloTest, ArrayContent) {
  int arr[] = {1, 2, 3, 4, 5};
  EXPECT_EQ(arr[0], 1);
  EXPECT_EQ(arr[4], 5);
}
