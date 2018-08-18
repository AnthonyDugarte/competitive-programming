// https://codeforces.com/problemset/problem/701/A

#include<vector>
#include<iostream>

using namespace std;

int main()
{
  std::ios_base::sync_with_stdio(false);

  size_t n, sum{};
  std::cin >> n;

  vector<int> cards(n);
  for(size_t i{}; i < n; ++i)
  {
    std::cin >> cards[i];
    sum += cards[i];
  }

  size_t average{ sum / (n >> 1) };

  for(size_t i{}; i < n; ++i)
  {
    if(cards[i] != 0)
      for(size_t j{}; j < n; ++j)
      {
        if(cards[i] + cards[j] == average and i != j)
        {
          std::cout << i + 1 << " " << j + 1 << "\n";
          cards[i] = cards[j] = 0;
          break;
        }
      }
  }

  return 0;
}
