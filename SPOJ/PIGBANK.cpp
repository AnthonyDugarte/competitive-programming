#include <bits/stdc++.h>

template <typename T, typename U>
using p_t = std::pair<T, U>;

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
template <typename T, typename U>
using um_t = std::unordered_map<T, U>;

template <typename T>
T max_val() { return std::numeric_limits<T>::max(); }

type_t dp(v_t<p_t<type_t, type_t>> &coins, um_t<type_t, type_t> &memo, type_t w_t, type_t t = 0)
{
  type_t lowest_t{max_val<type_t>()};

  um_t<type_t, type_t>::iterator it{memo.find(w_t)};

  if (it != memo.end())
  {
    if (it->second == max_val<type_t>())
      return it->second;

    return t + it->second;
  }

  if (w_t <= 0)
    return w_t == 0 ? t + (memo[w_t] = std::min({memo[w_t], t})) : lowest_t;

  for (p_t<type_t, type_t> &c : coins)
    lowest_t = std::min({lowest_t, dp(coins, memo, w_t - c.second, c.first)});

  memo[w_t] = lowest_t;

  if (lowest_t == max_val<type_t>())
    return lowest_t;

  return t + lowest_t;
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  type_t t;
  cin >> t;

  while (--t != -1)
  {
    type_t e, f, n;
    cin >> e >> f >> n;

    v_t<p_t<type_t, type_t>> v(n);
    for (p_t<type_t, type_t> &p : v)
      cin >> p.first >> p.second;

    um_t<type_t, type_t> memo;

    f -= e;

    type_t r{dp(v, memo, f)};
    if (r == max_val<type_t>())
      cout << "This is impossible.";
    else
      cout << "The minimum amount of money in the piggy-bank is " << r << ".";

    cout << endl;
  }

  return 0;
}