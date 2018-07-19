/* CodeForces Problem: http://codeforces.com/problemset/problem/118/A
 */

# include <string>
# include <iostream>
# include <locale>

int main()
{
  std::string str, out;

  auto isVowel = [](char & c)->bool
  {
    switch (c)
    {
      case 'A': case 'a':
      case 'E': case 'e':
      case 'I': case 'i':
      case 'O': case 'o':
      case 'U': case 'u':
      case 'Y': case 'y': // wtf ??
        return true;
      default:
        return false;
    }
  };

  std::cin >> str;
  std::locale myLocale;

  for(auto && c : str)
  {
    if(isVowel(c))
      continue;

    out += ".";
    out += std::use_facet<std::ctype<char>>(myLocale).tolower(c); // fancy C++
  }

  std::cout << out << std::endl;
  return 0;
}
