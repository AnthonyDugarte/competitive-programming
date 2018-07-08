// http://codeforces.com/problemset/problem/672/A

# include <iostream>
# include <string>

int main ()
{
  size_t n;
  std::cin >> n;

  std::string str;

  for(size_t i{ 1 }; str.size() < n; ++i)
    str += std::to_string(i);

  std::cout << str[n - 1] << "\n";

  return 0;
}
