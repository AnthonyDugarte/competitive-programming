// https://codeforces.com/problemset/problem/432/A

#include <iostream>

int main()
{
  std::ios_base::sync_with_stdio(false);
  
  size_t n, k, counter{ 0 }, members{ 0 };
  std::cin >> n >> k;

  k = 5 - k;

  for( ; --n != -1; )
  {
    size_t participant;
    std::cin >> participant;

    if(participant <= k)
      ++members;

    if(members == 3)
    {
      ++counter;
      members = 0;
    }
  }

  std::cout << counter << "\n";

  return 0;
}
