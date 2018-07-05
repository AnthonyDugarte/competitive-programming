/* CodeForces Problem: http://codeforces.com/problemset/problem/71/A
 * Made by: Anthony Dugarte through PapasFritas (codeforces.com/profile/PapasFritas)
 */

# include <string>
# include <iostream>
# include <vector>

int main()
{
  int its;
  std::cin >> its;
  ++its;

  std::string str;
  std::vector<std::string> newWords;

  while(--its)
  {
    std::cin >> str;

    if(str.size() <= 10)
    {
      newWords.push_back(str);
      continue;
    }

    newWords.push_back({ str[0] + std::to_string(str.size() - 2) + str.back() });
  }

  for(auto && words : newWords)
    std::cout << words << "\n";

  return 0;
}
