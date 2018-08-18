// https://codeforces.com/problemset/problem/750/A

#include <iostream>

int main()
{
  size_t n, curr_time;
  std::cin >> n >> curr_time;

  size_t solved{};
  const size_t t_time{ 240 };

  for(size_t i{ 1 }; i <= n; ++i)
  {
    if((curr_time += i *5) <= t_time)
      ++solved;
    else break;
  }

  std::cout << solved << "\n";

  return 0;
}
