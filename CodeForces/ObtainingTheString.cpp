// https://codeforces.com/contest/1015/problem/B

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <list>

int main()
{
  std::ios_base::sync_with_stdio(false);
  // std::cin.tie(nullptr);
  // std::cout.tie(nullptr);

  size_t N;
  std::cin >> N;

  std::string S, T;
  std::cin >> S >> T; // obtain T from S

  std::map<char, int> reps;

  for(auto c : S) // O(N * ln N)
    ++reps[c];

  for(auto &&c : T) // O(N * ln N)
  {
    auto &&it{ reps.find(c) }; // O(ln N)

    if(it != reps.end())
      --std::get<1>(*it); // O(1)

    if(it == reps.end() or std::get<1>(*it) < 0) // O(1)
    {
      std::cout << "-1\n";
      return 0;
    }
  }

  if(std::any_of(reps.begin(), reps.end(), [](auto &&data){ return std::get<1>(data) != 0; } )) // O(N)
  {
    std::cout << "-1\n";
    return 0;
  }

  // Checking for bad string: O(N * ln N) + O(N * ln N) + O(N) => O(N * ln N)

  std::list<int> swaps;

  for(size_t i{}; i < N; ++i) // O(N * N)
  {
    if(S[i] == T[i])
      continue;

    size_t pos{ S.rfind(T[i]) }; // Linear O(N)

    for( ; pos > i; --pos) // O(N)
    {
      swaps.push_back(pos); // O(1)
      std::swap(S.at(pos), S.at(pos - 1)); // O(1)
    }
  }

  std::cout << swaps.size() << "\n";
  for(auto it { swaps.cbegin() }; it != swaps.cend(); ++it)
  {
    std::cout << *it;

    if(std::distance(swaps.cbegin(), it) < swaps.size() - 1)
      std::cout << " ";
    else std::cout << "\n";
  }

  return 0;
}
