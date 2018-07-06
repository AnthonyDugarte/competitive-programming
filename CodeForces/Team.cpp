// CodeForces Problem: http://codeforces.com/problemset/problem/231/A

# include <iostream>

int main ()
{
  size_t N;
  std::cin >> N;
  size_t problemsToSolve{};

  for(++N ; --N ; )
  {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if(a + b + c > 1)
      ++problemsToSolve;
  }

  std::cout << problemsToSolve << std::endl;
  return 0;
}
