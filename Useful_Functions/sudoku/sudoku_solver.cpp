#include <iostream>
#include <vector>
#include <cmath>
#include <utility>

using type_t = unsigned short;

using vi_t = std::vector<type_t>;

size_t subrid_size(const std::vector<vi_t> &table)
{
  return static_cast<size_t>(std::sqrt(table.size()));
}

// puting number on that row(x) and col(y) is valid?
bool validPlay(int n, int row, int col, const std::vector<vi_t> &table)
{
  if(table[row][col] != 0)
    return false;

  size_t size { subrid_size(table) };
  size_t row_start{ static_cast<size_t>(row / size) };
  size_t col_start{ static_cast<size_t>(col / size) };

  // checking subgrid
  for(size_t x{ row_start * size }; x < (row_start + 1) * size; ++x)
  {
    for(size_t y{ col_start * size }; y < (col_start + 1) * size; ++y)
      if(table[x][y] == n)
        return false;
  }

  // checking row
  for(size_t y{ 0 }; y < table.size(); ++y)
    if(table[row][y] == n)
      return false;

  // checking column
  for(size_t x{ 0 }; x < table.size(); ++x)
    if(table[x][col] == n)
      return false;

  // n is not repeated in subgrid, row or col;
  return true;
}

// puting number on that row(x) and col(y) is valid?
bool solve(std::vector<vi_t> &table, size_t row, size_t col)
{
  if(col == table.size())
    return solve(table, ++row, 0);

  if(row == table.size())
    return true; // ??????

  // busy position
  if(table[row][col] != 0)
    return solve(table, row, ++col);

  for(size_t n{ 1 }; n <= table.size(); ++n)
  {
    if(validPlay(n, row, col, table))
    {
      table[row][col] = n;
      bool solved { solve(table, row, col +1) };

      if(solved)
        return solved;
      else table[row][col] = 0; // backtracking uwu
    }
  }

  // could not solve
  return false;
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

  if (not solve(table, 0, 0))
    std::cout << "could not solve sudoku\n";
  else for(auto &row : table)
  {
    for(auto &col : row)
      std::cout << col << " ";
    std::cout << "\n";
  }

  return 0;
}
