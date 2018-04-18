#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  size_t cases;

  cin >> cases;
  vector<size_t> winners;

  do
  {
    size_t candidates;
    size_t regions;
    cin >> candidates >> regions;
    vector<size_t> votes(candidates);

    do
    {
      for(size_t candidate {0}; candidate < candidates; ++candidate)
      {
        size_t votes_achieved;
        cin >> votes_achieved;
        votes[candidate] += votes_achieved;
      }
    }while(--regions);

    size_t winner{0};
    for(size_t it {0}; it < candidates; ++it)
      if(votes[it] > votes[winner])
        winner = it;

    winners.push_back(move(++winner));
  }while(--cases);

  for(auto& it : winners)
    cout << it << "\n";
  return 0;
}
