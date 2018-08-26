// https://codeforces.com/problemset/problem/116/A

#include <iostream>


int main()
{
  std::ios_base::sync_with_stdio(false);
  
  size_t n;
  std::cin >> n;

  size_t max_cap{ 0 }, cap{ 0 };

  for( ; --n != -1; )
  {
    size_t a, b;
    std::cin >> a >> b;

    cap -= a;
    cap += b;
    if(cap > max_cap)
      max_cap = cap;
  }

  std::cout << max_cap << "\n";

  return 0;
}
