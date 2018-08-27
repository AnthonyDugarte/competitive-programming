// http://codeforces.com/problemset/problem/319/C

#include <iostream>
#include <vector>
#include <deque>
#include <utility>

using type_t = unsigned long long;

inline type_t calcWaste(const std::pair<type_t, type_t> &a, const std::pair<type_t, type_t> &b) noexcept
{
  return (std::get<1>(b) - std::get<1>(a)) / (std::get<0>(a) - std::get<0>(b));
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  size_t N;
  std::cin >> N;

  std::vector<type_t> heights(N);
  for(auto &&val : heights)
    std::cin >> val;

  std::deque<std::pair<type_t, type_t>> bounds;

  type_t cost;
  std::cin >> cost;
  bounds.push_back({ cost, 0 }); // seed

  for(size_t i{}; ++i < N; )
  {
    while(bounds.size() > 1 and calcWaste(*(bounds.begin()), *(bounds.begin() + 1)) < heights[i])
      bounds.pop_front();

    std::cin >> cost;
    std::pair<type_t, type_t> bound{ cost, std::get<0>(bounds.front()) * heights[i] + std::get<1>(bounds.front()) };

    while(bounds.size() > 1 and calcWaste(*(bounds.rbegin() + 1), *(bounds.rbegin())) >= calcWaste(*(bounds.rbegin()), bound))
      bounds.pop_back();

    if(calcWaste(*(bounds.rbegin()), bound) <= heights.back()) /*watch this line*/
      bounds.push_back(std::move(bound));
  }

  std::cout << std::get<1>(bounds.back()) << "\n";
  return 0;
}
