#include <bits/stdc++.h>

using std::cin;
using std::cout;
constexpr char endl = '\n';

template <typename T>
void debug(T val) { cout << val << endl; }
template <typename T, typename... TT>
void debug(T val, TT... tail) { cout << val << " : ", debug(tail...); }

using type_t = unsigned long long;

size_t steps_i{0};

type_t dp(std::vector<type_t> &v, std::vector<type_t> &memo, size_t i = 0, type_t acc = 0)
{
  if (i >= v.size())
    return acc;
  if (memo[i] != -1)
    return acc + memo[i];
  return acc + (memo[i] = std::max(dp(v, memo, i + 2, v[i]), dp(v, memo, i + 3, v[i])));
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  size_t t{0}, n{0};
  cin >> t;

  for (size_t i{0}; i < t; ++i)
  {
    cin >> n;

    std::vector<type_t> v(n), v_(n, -1);

    for (type_t &i_ : v)
      cin >> i_;

    cout << "Case " << i + 1 << ": " << std::max(dp(v, v_, 0), dp(v, v_, 1)) << endl;
  }

  return 0;
}