#include <bits/stdc++.h>

template <typename T>
using v_t = std::vector<T>;

template <typename T, typename U>
using p_t = std::pair<T, U>;

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

int main()
{
  std::ios_base::sync_with_stdio(false);

  size_t n, shoots{0};
  cin >> n;

  v_t<p_t<int, int>> v(n);

  for (size_t i{0}; i < n; v[i].second = (++i) /* WTF, gave WA without () */)
    cin >> v[i].first;

  std::sort(v.begin(), v.end(), [](p_t<int, int> &a, p_t<int, int> &b) { return a.first > b.first; });

  for (size_t i{0}; i < n; ++i)
    shoots += v[i].first * i + 1;

  cout << shoots << endl;
  for (p_t<int, int> &p : v)
    cout << p.second << " ";
  cout << endl;

  return 0;
}