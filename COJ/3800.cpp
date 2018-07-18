template<typename T> T
mod(T n, T m) { return (n % m + m) % m; }

template<typename T>
T modInverse(T b, T m);

template<typename T>
T modDivide(T a, T b, T m)
{
    a = a % m;
    T inv = modInverse(b, m);

    return (inv * a) % m;
}

template<typename T>
T gcdExtended(T a, T b, T *x, T *y)
{
    // Base Case
    if (a == T(0))
    {
        *x = T(0);
        *y = T(1);
        return b;
    }

    T x1, y1; // To store results of recursive call
    T gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

template<typename T>
T modInverse(T b, T m)
{
    T x, y; // used in extended GCD algorithm
    T g = gcdExtended(b, m, &x, &y);

    return x % m;
}

template<typename T>
T modPow(T n, T e, T m)
{
  T res { 1 };

  while(e > T(0))
  {
    if (e & 1)
      res = (res * n) % m;

    e >>= 1;
    n = (n * n) % m;
  }

  return res;
}

template<typename T>
T serie(T x, T n, T m) // 1 + x + x^2 + x^3  + ... + x^n, it is adulterated, original on UsefulFunctions.cpp
{
    if(x == T(1))
        return n % m;

    return modDivide(modPow(x, n, m) - 1, x - 1, m);
}

# include <iostream>

using type_t = long long;
using namespace std;

int main()
{
    constexpr type_t M { static_cast<type_t>(10e8 + 7) };

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    type_t N, K, res{};

    cin >> N >> K;

    for(type_t i{}, zeroes{}; i < K; ++i)
    {
        type_t L;
        cin >> L;

        if(not (i & 1))
        {
            zeroes += L;
            continue;
        }

        res = (res + (L * serie(N, zeroes, M)) % M) % M;
    }

    cout << res << "\n";
    return 0;
}
