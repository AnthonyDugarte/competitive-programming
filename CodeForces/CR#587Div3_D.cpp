#include <bits/stdc++.h>

template <typename T>
using v_t = std::vector<T>;

template <typename T, typename U>
using p_t = std::pair<T, U>;
template <typename T, typename U>
using m_t = std::map<T, U>;
template <typename T, typename U>
using um_t = std::unordered_map<T, U>;

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

type_t gcd(type_t a, type_t b) { return b == 0 ? a : gcd(b, a % b); }

int main()
{
  std::ios_base::sync_with_stdio(false);

  size_t n;
  cin >> n;

  type_t r{0}, bg{0}, ppl{0};

  v_t<type_t> v(n);
  for (type_t &i : v)
  {
    cin >> i;
    bg = std::max(i, bg);
  }

  for (type_t &i : v)
    r = gcd(r, bg - i);
  for (type_t &i : v)
    ppl += (bg - i) / r;

  cout << ppl << " " << r << endl;

  return 0;
}