#include <bits/stdc++.h>

template <typename T>
using v_t = std::vector<T>;

using type_t = int64_t;
using utype_t = uint64_t;
using str_t = std::string;

using std::cin;
using std::cout;

constexpr char endl = '\n';

template <typename T>
void debug(T val) { cout << val << endl; }
template <typename T, typename... TT>
void debug(T val, TT... tail) { cout << val << " : ", debug(tail...); }

template <typename T>
using us_t = std::unordered_set<T>;

int main()
{
  std::ios_base::sync_with_stdio(false);

  size_t n, k, given_sets{0};
  cin >> n >> k;

  us_t<size_t> drinks;

  for (size_t i{0}, k_d{0}; i < n; ++i)
  {
    cin >> k_d;
    if (drinks.find(k_d) != drinks.end())
    {
      drinks.erase(k_d);
      ++given_sets;
    }
    else
      drinks.insert(k_d);
  }

  cout << (given_sets << 1) + (drinks.size() >> 1) + (drinks.size() & 1) << endl;

  return 0;
}