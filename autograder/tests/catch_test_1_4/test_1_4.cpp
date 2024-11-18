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

static void test_1_4() {
  vector vr = {0.5, 2.2, 3.3, 4.1};
  vector vc = {1, 2, 3, 4};
  auto result = outer(vr.begin(), vr.end(), vc.begin(), vc.end());
  for (const auto& row: result) {
    std::copy(row.begin(), row.end(), std::ostream_iterator<double>(std::cout, " "));
    std::cout << std::endl;
  }
}

TEST_CASE("Question #1.4") {
    execute_test("test_1_4.in", test_1_4);
}