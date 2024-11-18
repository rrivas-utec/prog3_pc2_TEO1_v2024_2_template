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

static void test_1_1() {
  vector vr = {1, 2, 3, 4};
  vector vc = {4, 5};
  auto result = outer(vr.begin(), vr.end(), vc.begin(), vc.end());
  for (const auto& row: result) {
    std::copy(row.begin(), row.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
  }
}

TEST_CASE("Question #1.1") {
    execute_test("test_1_1.in", test_1_1);
}