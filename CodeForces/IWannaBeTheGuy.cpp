// https://codeforces.com/problemset/problem/469/A

#include <iostream>
#include <vector>

int main()
{
  size_t n{ 0 }, passed{ 0 }, p;
  std::cin >> n;

  std::vector<bool> lvls_passed(100, false);

  for(size_t xy = 0; xy < 2; ++xy)
  {
    std::cin >> p;
    for(size_t i{ 0 }, aux; i < p; ++i)
    {
      std::cin >> aux;

      if(not lvls_passed[--aux])
      {
        lvls_passed[aux] = true;
        ++passed;
      }
    }
  }

  std::cout << (n == passed ? "I become the guy." : "Oh, my keyboard!") << "\n";

  return 0;
}
