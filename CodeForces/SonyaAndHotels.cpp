// CodeForces Problem: http://codeforces.com/problemset/problem/1004/A
# include <iostream>

int main()
{
  short n;
  unsigned long d;

  std::cin >> n >> d;

  long long prevCoord{};
  std::cin >> prevCoord;


  auto distance = [](long long val1, long long val2)->long long
  {
    return std::max(val1, val2) - std::min(val1, val2);
  };

  unsigned long out{ 2 };
  for(size_t i{ 1 }; i < n; ++i)
  {
    long long coord;
    std::cin >> coord;

    long long dd = distance(coord, prevCoord);

    if(dd == d << 1)
      ++out;
    else if(dd > d << 1)
      out += 2;
    prevCoord = coord;
  }

  std::cout << out << std::endl;

  return 0;
}
