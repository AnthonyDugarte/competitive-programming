// CodeForces Problem: http://codeforces.com/problemset/problem/96/A


# include <iostream>

int main()
{
  char c, prev{'2'};
  unsigned reps{};

  while(c != '\n')
  {
    c = getchar();

    if(c != prev)
      reps = 0;

    if(++reps == 7)
    {
      std::cout << "YES\n";
      return 0;
    }

    prev = c;
  }

  std::cout << "NO\n";
  return 0;
}
