// http://codeforces.com/problemset/problem/337/C

# include <iostream>

using type_t = long long;

const type_t M = 1000000009ll;

type_t pow(type_t x, type_t n)
{
  type_t res = 1;

  while(n > 0)
  {
    if (n & 1)
      res = (res * x) % ::M;

    n >>= 1;
    x = (x * x) % ::M;
  }
  return res;
}

int main()
{
  type_t n, m, k;
  std::cin >> n >> m >> k;

  type_t doublesNeeded{ m - (n - n / k) };

  type_t score{};

  if(doublesNeeded > 0)
  {
    score = pow(2ull, doublesNeeded + 1);
    score *= k;
    score -= 2 * k;
  }

  if(m > 0 and doublesNeeded >=0)
  {
    score = (score + m - doublesNeeded * k) % ::M;
    if(score < 0)
     score += ::M;
  }
  else if(doublesNeeded < 0)
    score = m;

  std::cout << score << "\n";
  return 0;
}
