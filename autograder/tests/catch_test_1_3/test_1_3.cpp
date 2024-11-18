//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "outer.h"
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

static void test_1_3() {
  vector v1 = {1, 2, 3, 4};
  vector v2 = {0.5, 2.2, 3.3, 4.1};
  auto result = outer(v1.begin(), v1.end(), v2.begin(), v2.end());
  for (const auto& row: result) {
    std::copy(row.begin(), row.end(), std::ostream_iterator<double>(std::cout, " "));
    std::cout << std::endl;
  }
}

TEST_CASE("Question #1.3") {
    execute_test("test_1_3.in", test_1_3);
}