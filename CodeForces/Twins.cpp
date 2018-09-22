// https://codeforces.com/problemset/problem/160/A

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  size_t n, twin1{}, twin2{};
  std::cin >> n;

  std::vector<size_t> coins(n);

  for(auto &&c : coins)
  {
    std::cin >> c;
    twin2 += c;
  }

  std::sort(coins.begin(), coins.end(), [](auto &&a, auto &&b){ return a > b; });

  size_t n_coins{};

  for(auto &&c : coins)
  {
    twin1 += c;
    twin2 -= c;
    ++n_coins;

    if(twin1 > twin2)
      break;
  }

  std::cout << n_coins << "\n";

  return 0;
}
