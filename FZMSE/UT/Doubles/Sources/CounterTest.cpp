/*
 * CounterTest.hpp
 *
 *  Created on: 17 lip 2015
 *      Author: pkozuch
 */

#include <iostream>
using namespace std;
#include "gtest/gtest.h"

#include "Counter.h"

TEST(Counter, Increment) {
  Counter c;

  EXPECT_EQ(0, c.Increment());
  EXPECT_EQ(1, c.Increment());
  EXPECT_EQ(2, c.Increment());

  cout << "Congratulations, you have just run a test :-)" << endl;
}

int main(int argc, char **argv) {
   ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}