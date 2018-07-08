// CodeForces Problem: http://codeforces.com/problemset/problem/621/A

# include <iostream>

int main()
{
  unsigned long long sum{}, highest{ 1000000001ull }, lowest{ highest };

  size_t n;
  std::cin >> n;

  for(size_t i{}; ++i <= n; )
  {
    unsigned long long val;
    std::cin >> val;

    sum += val;

    if(val & 1 and val < lowest)
      lowest = val;
  }

  if(sum & 1)
  {
    if(lowest == highest)
      sum = 0;
    else sum -= lowest;
  }

  std::cout << sum << std::endl;
  return 0;
}
