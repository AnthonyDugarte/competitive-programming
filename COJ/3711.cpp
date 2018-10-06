#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>

using type_t = unsigned short;
using vi_t = std::vector<type_t>;

template<typename T> // 1 + 2 + 3 + 4 + ... + n
T naturalSummatory(T n) { return n * (n + 1) / 2; }

type_t correct_sum;
bool check_eq(type_t val)
{
  return val == correct_sum;
}

// O(n * n) + O(2n) + O(n * n) = O(n * n)
bool is_sudoku_ok(const std::vector<vi_t> &table)
{
  // checking rows and cols
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

  correct_sum = naturalSummatory(table.size());

  if (not (std::all_of(row_sums.begin(), row_sums.end(), &check_eq) &&
              std::all_of(col_sums.begin(), col_sums.end(), &check_eq)))
    return false;

  // validating subgrids
  size_t grid_size { static_cast<size_t>(std::sqrt(table.size())) };

  for(size_t x_grid{ 0 }; x_grid != table.size(); x_grid += grid_size)
  {
    for(size_t y_grid{ 0 }; y_grid != table.size(); y_grid += grid_size)
    {
      size_t row_start{ static_cast<size_t>(x_grid / grid_size) };
      size_t col_start{ static_cast<size_t>(y_grid / grid_size) };

      std::vector<bool> reps(grid_size, false);

      for(size_t x{ row_start * grid_size }; x < (row_start + 1) * grid_size; ++x)
      {
        for(size_t y{ col_start * grid_size }; y < (col_start + 1) * grid_size; ++y)
        {
          if(reps[table[x][y]] == true)
            return false;

          reps[table[x][y]] = true;
        }
      }
    }
  }

  // grids all are well placed
  return true;
}

std::vector<vi_t> getTable(size_t n)
{
  std::vector<vi_t> table(n, vi_t(n, 0));

  for(auto &row : table)
    for(auto &col : row)
      std::cin >> col;

  return std::move(table);
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  size_t tests;
  std::cin >> tests;


  while(--tests != -1)
  {
    size_t n;
    std::cin >> n;

    std::cout << (is_sudoku_ok(getTable(n)) ? "yes" : "no") << "\n";
  }

  return 0;
}
