/* CodeForces Problem: http://codeforces.com/problemset/problem/282/A
 * Made by: Anthony Dugarte through PapasFritas (codeforces.com/profile/PapasFritas)
 */

# include <iostream>

int main()
{
  int N, X { 0 };
  std::cin >> N;
  ++N;

  while(--N)
  {
    std::string str;
    std::cin >> str;

    if(str.find("++") != std::string::npos)
      ++X;
    else --X;
  }

  std::cout << X << std::endl;
  return 0;
}
