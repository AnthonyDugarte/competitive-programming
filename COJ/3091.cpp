#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void seek(size_t& deadline, int64_t warlocks_p, vector<size_t>& power, size_t& harry_p, int64_t& track)
{
  size_t it{0};

  if((warlocks_p  += power[it++]) > harry_p)
    return;

  while((warlocks_p  += power[it++]) <= harry_p and it <= deadline);

  if(--it > 15)
    --track += static_cast<int64_t>(1 << (it - 15)) *  1 << 15;
  else --track += 1 << it;

  for(it; it < deadline; warlocks_p  += power[++it])
  {
    size_t it_aux {0};
    int64_t warlocks_p_aux{warlocks_p};

    if((warlocks_p_aux -= power[it_aux]) <= harry_p)
    	++track;

    while(++it_aux < it)
      if((warlocks_p_aux -= power[it_aux]) <= harry_p)
        seek(it_aux, warlocks_p_aux, power, harry_p, ++track);
  }
}

int main()
{
  size_t warlocks_n, harry_power;
  cin >> warlocks_n >> harry_power;

  vector<size_t> warlocks(warlocks_n);
  for(auto& damage : warlocks)
    cin >> damage;

  sort(warlocks.begin(), warlocks.end());
  while(warlocks.back() > harry_power)
    warlocks.pop_back();

  int64_t track{0};
  seek(warlocks_n, 0, warlocks, harry_power, track);
  cout << track << endl;

  return 0;
}

