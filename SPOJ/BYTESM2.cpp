#include <bits/stdc++.h>

template <typename T, typename U>
using p_t = std::pair<T, U>;

template <typename T>
using s_t = std::set<T>;
template <typename T>
using us_t = std::unordered_set<T>;
template <typename T>
using v_t = std::vector<T>;
template <typename T>
using vv_t = std::vector<std::vector<T>>;

template <typename T, typename U>
using m_t = std::map<T, U>;
template <typename T, typename U>
using um_t = std::unordered_map<T, U>;

using type_t = int64_t;
using utype_t = uint64_t;
using str_t = std::string;

using vt = v_t<type_t>;
using vut = v_t<utype_t>;
using vstr = v_t<str_t>;

using vvt = vv_t<type_t>;
using vvut = vv_t<utype_t>;
using vvstr = vv_t<str_t>;

using std::cin;
using std::cout;

constexpr char endl = '\n';
constexpr type_t M{static_cast<type_t>(1e9 + 7)};

template <typename T>
void debug(T val) { cout << val << endl; }
template <typename T, typename... TT>
void debug(T val, TT... tail) { cout << val << " : ", debug(tail...); }

template <typename T>
T min_val() { return std::numeric_limits<T>::min(); }
template <typename T>
T max_val() { return std::numeric_limits<T>::max(); }

type_t gcd(type_t a, type_t b) { return a == 0 ? b : gcd(b % a, a); }

int dp(v_t<v_t<int>> &m, v_t<v_t<int>> &memo, int i = 0, int j = 0)
{
  if (i == m.size() || j < 0 || j >= m[0].size())
    return 0;

  int &ii{memo[i][j]};

  if (ii > 0)
    return ii;

  return ii = m[i][j] + std::max({dp(m, memo, i + 1, j - 1), dp(m, memo, i + 1, j), dp(m, memo, i + 1, j + 1)});
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  size_t t;
  cin >> t;

  while (--t != -1)
  {
    size_t r, c;
    cin >> r >> c;

    v_t<v_t<int>> m(r, v_t<int>(c));

    for (v_t<int> &h : m)
      for (int &w : h)
        cin >> w;

    v_t<v_t<int>> memo(r, v_t<int>(c, 0));
    int best{0};

    for (size_t j{0}; j < c; ++j)
      best = std::max(best, dp(m, memo, 0, j));

    cout << best << endl;
  }

  return 0;
}

// 5 6
// 3 2 1 2 2 5
// 1 1 2 2 1 2
// 7 3 2 1 4 7
// 4 1 1 5 4 5
// 2 1 8 3 4 1