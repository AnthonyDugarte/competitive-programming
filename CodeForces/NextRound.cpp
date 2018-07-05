/* CodeForces Problem: http://codeforces.com/problemset/problem/158/A
 * Made by: Anthony Dugarte through PapasFritas (codeforces.com/profile/PapasFritas)
 */

# include <iostream>
# include <vector>

int main()
{
  unsigned int n, k;
  std::cin >> n >> k;

  std::vector<unsigned int> winners;
  unsigned int limit;
  bool taken = false;

  for(size_t i { 0 }; i < n; ++i)
  {
    unsigned int aux;
    std::cin >> aux;

    if(taken)
    {
      if(aux < limit)
        break;
    }
    else if(i + 1 == k )
    {
      taken = true;
      limit = aux;
    }

    winners.emplace(winners.begin(), std::move(aux));
  }

  for(auto && it { winners.begin() }; it != winners.end(); )
  {
    if(*it < limit or *it == 0u)
    {
      winners.erase(it);
      it = winners.begin();
    }
    else break;
  }

  std::cout << winners.size() << std::endl;
  return 0;
}
