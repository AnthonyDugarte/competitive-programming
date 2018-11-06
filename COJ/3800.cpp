template<typename T> T
mod(T n, T m) { return (n % m + m) % m; }
template<typename T>
T modMul(T a, T b, T m) { return mod(  mod(a, m)  *  mod(b, m),    m); }

# include <stdexcept>

template<typename T>
T modInverse(T b, T m);

template<typename T>
T modDivide(T a, T b, T m)
{
    a = a % m;
    T inv = modInverse(b, m);
    if (inv == T(-1))
       throw std::domain_error("Division not defined"); // it won't entry here

    return modMul(inv, a, m);
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

    // Update x and y using results of recursive call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

template<typename T>
T modInverse(T b, T m)
{
    T x, y; // used in extended GCD algorithm
    T g = gcdExtended(b, m, &x, &y);

    // Return -1 if b and m are not co-prime
    if (g != 1)
        return T(-1);

    return mod(x, m);
}


template<typename T>
T modPow(T n, T e, T m)
{
  T res { 1 };

  while(e > T(0))
  {
    if (e & 1)
      res = modMul(res, n, m);

    e >>= 1;
    n = modMul(n, n, m);
  }

  return res;
}


template<typename T>
T serie(T x, T n, T m) // 1 + x + x^2 + x^3  + ... + x^n, it is adulterated, original on UsefulFunctions.cpp
{
    if(x == T(1))
        return mod(n, m);

    return modDivide(modPow(x, n, m) - 1, x - 1, m);
}

# include <iostream>

using namespace std;
using type_t = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    constexpr type_t M { static_cast<type_t>(10e8 + 7) };
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