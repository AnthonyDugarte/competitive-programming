/* CodeForces Problem: http://codeforces.com/problemset/problem/262/A
 * Made by: Anthony Dugarte
 * through PapasFritas (codeforces.com/profile/PapasFritas)
 */

# include <iostream>

int main ()
{
  int n, m;
  std::cin >> n >> m;
  ++n;

  int total {};
  while(--n)
  {
    int count{};

    std::string str;
    std::cin >> str;

    for(auto && c : str)
    {
      if(c == '4' or c == '7')
      {
        ++count;
        if(count > m)
          break;
      }
    }

    if(count <= m)
      ++total;
  }

  std::cout << total << std::endl;
  return 0;
}
