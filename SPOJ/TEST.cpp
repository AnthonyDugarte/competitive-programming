#include <iostream>

int main()
{
  size_t n;
  while(std::cin >> n)
  {
    if(n == 42)
      break;
    std::cout << n << "\n";
  }

  return 0;
}
