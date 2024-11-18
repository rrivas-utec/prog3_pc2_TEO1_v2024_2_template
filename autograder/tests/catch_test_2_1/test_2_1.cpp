//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "outer_parallel.h"
#include <fstream>
#include <iterator>
using namespace std;

static void test_2_1() {
  int rows;
  int cols;
  std::cin >> rows;
  std::cin >> cols;
  
  std::vector<int> v_rows;
  std::vector<double> v_cols;
  v_rows.reserve(rows);
  v_rows.reserve(cols);
  
  auto it_int = std::istream_iterator<int>(std::cin);
  for (int i = 0; i < rows; ++i) {
    v_rows.push_back(*it_int++);
  }

  auto it_double = std::istream_iterator<double>(std::cin);
  for (int i = 0; i < cols; ++i) {
    v_cols.push_back(*it_double++);
  }
  
  auto result = outer_parallel(v_rows.begin(), v_rows.end(), v_cols.begin(), v_cols.end());

  for (const auto& row: result) {
    std::copy(row.begin(), row.end(), std::ostream_iterator<double>(std::cout, " "));
    std::cout << std::endl;
  }
}

TEST_CASE("Question #2.1") {
    execute_test("test_2_1.in", test_2_1);
}