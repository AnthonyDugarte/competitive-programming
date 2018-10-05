#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>

using type_t = unsigned short;
using vi_t = std::vector<type_t>;

template<typename T> // 1 + 2 + 3 + 4 + ... + n
T naturalSummatory(T n) { return n * (n + 1) / 2; }

// O(n * n) + O(2n) = O(n * n)
bool is_sudoku_ok(const std::vector<vi_t> &table)
{
  vi_t row_sums(table.size(), 0);
  vi_t col_sums(table.size(), 0);

  for(size_t row{ 0 }; row < table.size(); ++row)
  {
    for(size_t col{ 0 }; col < table.size(); ++col)
    {
      row_sums[row] += table[row][col];
      col_sums[col] += table[row][col];
    }
  }

  auto check_eq = [correct_sum = naturalSummatory(table.size())](auto &&val)
  { return val == correct_sum; };

  return (std::all_of(row_sums.begin(), row_sums.end(), check_eq) &&
              std::all_of(col_sums.begin(), col_sums.end(), check_eq));
}

std::vector<vi_t> getTable(size_t n = 9)
{
  std::vector<vi_t> table(n, vi_t(n, 0));

  for(auto &row : table)
    for(auto &col : row)
      std::cin >> col;

  return std::move(table);
}

int main()
{
  auto table { getTable(9) };

  if(is_sudoku_ok(table))
    std::cout << "correct!";
  else std::cout << "incorrect!";

  std::cout << std::endl;

  return 0;
}
