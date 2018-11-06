template<typename T> // c++' % operand is not mod but remainder
T mod(T n, T m) { return (n % m + m) % m; }
template<typename T> // (a + b) % m = (a % m + b% m) % m
T modSum(T a, T b, T m) { return mod(mod(a, m) + mod(b, m), m); }
template<typename T> // (a - b) % m = (a % m - b % m) % m
T modSub(T a, T b, T m) { return mod(mod(a, m) - mod(b, m), m); }
template<typename T> // (a * b) % m = (a % m * b % m) % m
T modMul(T a, T b, T m) { return mod(mod(a, m) * mod(b, m), m); }
template<typename T>
T modDivide(T a, T b, T m);
template<typename T>
T pow(T n, T e, T m);

template <typename T>  // x^0 + x^1 + x^2 + x^3  + ... + x^n --> (x ^ (n + 1) - 1) / (x - 1)
T finiteGeometricSerie(T x, T n, T m)
{
    if(x == T(1))
        return mod(n + 1, m);
    
    return modDivide(modSub( T{ 1 }, pow(x, n + 1, m), m), modSub(T{ 1 }, x, m), m);
    
    // return modDivide(modSub(pow(x, modSum(n, T(1), m), m), T(1), m), modSub(x, T(1), m), m);
}

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    size_t t;
    std::cin >> t;
    
    while(--t != -1)
    {
        long long x, n;
        std::cin >> x >> n;
        std::cout << finiteGeometricSerie(x, n, 1000000007ll) << "\n";
    }

    return 0;
}

# include <stdexcept>

template<typename T>
T modInverse(T b, T m);

template<typename T>
T modDivide(T a, T b, T m)
{
    a = mod(a, m);
    T inv = modInverse(b, m);
    if (inv == T(-1))
       throw std::domain_error("Division not defined");

    return modMul(inv, a, m);
}

// Source:  https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
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

    // Return -1 if b and m are not co-prime,check source for details
    if (g != 1)
        return T(-1);

    return mod(x, m);
}

template<typename T>
T pow(T n, T e, T m)
{
  T res { 1 };

  while(e > T{ 0 })
  {
    if (e & 1)
      res = modMul(res, n, m);

    e >>= 1;
    n = modMul(n, n, m);
  }

  return res;
}