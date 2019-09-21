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

int main()
{
  std::ios_base::sync_with_stdio(false);

  size_t n, changes{0};
  str_t s;
  cin >> n >> s;

  for (size_t i{0}; i < n; i += 2)
    if (s[i] == s[i + 1])
    {
      ++changes;

      if (s[i] == 'a')
        ++s[i];
      else
        --s[i];
    }

  cout << changes << endl
       << s << endl;

  return 0;
}