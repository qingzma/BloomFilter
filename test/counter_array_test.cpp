#include "../include/counter_array.h"
#include <chrono>
#include <gtest/gtest.h>
#include <iostream>

TEST(CounterArrayTest, GetSetTest) {
  bf::CounterArray<int> ca(100);
  //   std::cout << ca.To_string() << std::endl;
  ca.Add(5, 0);
  ca.Adds(5, {0, 1, 2, 3, 4});
  //   std::cout << ca.To_string() << std::endl;
  EXPECT_EQ(10, ca.Get(0));
  EXPECT_EQ(5, ca.Get(1));
  EXPECT_EQ(0, ca.Get(5));

  EXPECT_EQ(5, ca.GetMin({0, 1}));
};