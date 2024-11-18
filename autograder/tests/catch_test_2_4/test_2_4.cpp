//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "outer_parallel.h"
using namespace std;

static void test_2_4() {
  int rows;
  int cols;
  std::cin >> rows;
  std::cin >> cols;
  
  using T = double;
  std::vector<T> v_rows;
  std::vector<T> v_cols;
  v_rows.reserve(rows);
  v_rows.reserve(cols);
  
  auto it = std::istream_iterator<T>(std::cin);
  for (int i = 0; i < rows; ++i) {
    v_rows.push_back(*it++);
  }
  
  for (int i = 0; i < cols; ++i) {
    v_cols.push_back(*it++);
  }
  
  auto result = outer_parallel(v_rows.begin(), v_rows.end(), v_cols.begin(), v_cols.end());
  
  for (const auto& row: result) {
    std::copy(row.begin(), row.end(), std::ostream_iterator<T>(std::cout, " "));
    std::cout << std::endl;
  }
}

TEST_CASE("Question #2.4") {
    execute_test("test_2_4.in", test_2_4);
}