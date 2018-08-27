// https://codeforces.com/contest/1015/problem/A

#include <iostream>
#include <vector>

int main()
{
  size_t n, m;
  std::cin >> n >> m;
  std::vector<bool> range(m, true);

  for(size_t i{}; ++i <= n; )
  {
    size_t a, b;
    std::cin >> a >> b;

    for(size_t k{ a - 1 }; k < b; ++k)
      range[k] = false;
  }

  std::vector<size_t> empty_points;
  for(size_t i{}; i < m; ++i)
  {
    if(range[i])
      empty_points.push_back(i + 1);
  }

  std::cout << empty_points.size() << "\n";
  for(auto &&it : empty_points)
    std::cout << it << " ";
  std::cout << "\n";

  return 0;
}
