template<typename T> // c++' % operand is not mod but remainder
T mod(T n, T m) { return (n % m + m) % m; }

template<typename T> // (a + b) % m = (a % m + b% m) % m
T modSum(T a, T b, T m) { return mod(mod(a, m) + mod(b, m), m); }

template<typename T> // (a - b) % m = (a % m - b % m) % m
T modSub(T a, T b, T m) { return mod(mod(a, m) - mod(b, m), m); }

template<typename T> // (a * b) % m = (a % m * b % m) % m
T modMul(T a, T b, T m) { return mod(mod(a, m) * mod(b, m), m); }

template<typename T> // (a / b) % m
T modDivide(T a, T b, T m);

// source from modDivide: https://www.geeksforgeeks.org/modular-division/
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


/* functions with ugly modular form, not needed at all */

template<typename T>
T pow(T n, T e, T m)
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


template<typename T> // 1 + 2 + 3 + 4 + ... + n
T naturalSummatory(T n, T m) { return modDivide(modMul(n, modSum(n, T(1), m), m), T(2), m); }

template<typename T> // 1^2 + 2^2 + 3^2 + 4 ^2+ ... + n^2
T quadraticSummatory(T n, T m)
{
    return modDivide(modMul(n, modMul(modSum(n, T(1), m),modSum(modMul(T(2), n, m), T(1) , m), m) , m), T(6), m);
}

template<typename T>
T finiteGeometricSerie(T x, T n, T m)
{
    if(x == T(1))
        return mod(n + 1, m);

    return modDivide(modSub(pow(x, modSum(n, T(1), m), m), T(1), m), modSub(x, T(1), m), m);
}
