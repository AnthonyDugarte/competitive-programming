// https://codeforces.com/contest/1015/problem/C

#include <iostream>
#include <set>
#include <functional>

int main()
{
  using type_t = unsigned long long;

  type_t n, m, a_total{ 0 }, b_total{ 0 };
  std::cin >> n >> m;

  std::multiset<type_t, std::greater<type_t>> compressed_songs;

  for(size_t i{}; i < n; ++i)
  {
    type_t a, b;
    std::cin >> a >> b;

    a_total += a;
    b_total += b;

    compressed_songs.insert(a - b);
  }

  if(b_total < m)
  {
    type_t compressed_n { 0 };

    while(a_total > m)
    {
      a_total -= *compressed_songs.begin();
      compressed_songs.erase(compressed_songs.begin());
      ++compressed_n;
    }

    std::cout << compressed_n;
  }
  else if(b_total == m)
    std::cout << n;
  else std::cout << -1;

  std::cout << "\n";

  return 0;
}
