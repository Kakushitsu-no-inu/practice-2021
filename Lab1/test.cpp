#include "array.h"
#include <gtest/gtest.h>
#include <vector>

class ArrayTest : public ::testing::Test {};

TEST_F(ArrayTest, size_not_odd) {
  array a(4);
  std::vector<int> b = {-1, 5, 3, 3};
  a.copy_from_vec(b);
  auto [sum1, sum2, pos1, pos2] = a.func();
  EXPECT_EQ(sum1, 4);
  EXPECT_EQ(sum2, 6);
  EXPECT_EQ(pos1, 1);
  EXPECT_EQ(pos2, 2);
}

TEST_F(ArrayTest, size_odd) {
  array a(5);
  std::vector<int> b = {-1, 5, 3, 3, -5};
  a.copy_from_vec(b);
  auto [sum1, sum2, pos1, pos2] = a.func();
  EXPECT_EQ(sum1, 4);
  EXPECT_EQ(sum2, 1);
  EXPECT_EQ(pos1, 1);
  EXPECT_EQ(pos2, 2);
}