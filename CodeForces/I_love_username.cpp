// CodeForces Problem: http://codeforces.com/problemset/problem/155/A

# include <iostream>

int main()
{
  size_t n;
  std::cin >> n;

  size_t greatest;
  std::cin >> greatest;
  size_t lowest { greatest };

  auto isAmazing = [&](size_t result)->bool
  {
    if(result < lowest)
    {
      lowest = result;
      return true;
    }

    if(result > greatest)
    {
      greatest = result;
      return true;
    }
    return false;
  };

  size_t amazingPlays{};

  for( ; --n; )
  {
    size_t result;
    std::cin >> result;

    if(isAmazing(result))
      ++amazingPlays;
  }


  std::cout << amazingPlays << "\n";
  return 0;
}
