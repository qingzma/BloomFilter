#include "../include/counter_array.h"
#include <chrono>
#include <gtest/gtest.h>
#include <iostream>

TEST(CounterArrayTest, ConstructorTest) {
  bf::CounterArray<int> ca(100);
  //   std::cout << ca.To_string() << std::endl;
};