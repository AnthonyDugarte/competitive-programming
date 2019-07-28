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

type_t candies_at(type_t n)
{
  return (n * (n + 1)) >> 1;
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  type_t n, k;
  cin >> n >> k;

  if (candies_at(n) == k)
  {
    cout << 0 << endl;
    return 0;
  }

  type_t l{0}, r{n - 1}, step{0};

  while (l <= r)
  {
    step = ((r + l) >> 1);

    if (candies_at(step) - (n - step) > k)
      r = step - 1;
    else if (candies_at(step) - (n - step) < k)
      l = step + 1;
    else
      break;
  }

  cout << n - step << endl;

  return 0;
}