// CodeForces Problem: http://codeforces.com/problemset/problem/112/A
# include <iostream>
# include <cctype>
# include <algorithm>

int main()
{
  std::string str1, str2;
  std::cin >> str1 >> str2;

  for(size_t i{} ; i < str1.size(); ++i)
  {
    str1[i] = tolower(str1[i]);
    str2[i] = tolower(str2[i]);
  }

  if(str1 == str2)
    std::cout << "0\n";
  else if(std::lexicographical_compare(str1.begin(), str1.end(), str2.begin(), str2.end()))
    std::cout << "-1\n";
  else std::cout << "1\n";
  return 0;
}
