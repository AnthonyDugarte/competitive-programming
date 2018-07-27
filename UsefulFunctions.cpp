// some useful functions I've found interesting while solving some CP problems

int turnBitOff(int n, int b) // start counting b at 0
{
    return n & ~(1 << b);
}
int turnBitOn(int n, int b) // start counting b at 0
{
    return n | (1 << b);
}


template<typename T> // c++' % operand is not mod but remainder
T mod(T n, T m) { return (n % m + m) % m; }

template<typename T> // (a+b)%m = (a%m + b%m) %m
T modSum(T a, T b, T m) { return mod(mod(a, m) + mod(b, m), m); }

template<typename T>
T modSub(T a, T b, T m) { return mod(mod(a, m) - mod(b, m), m); }

template<typename T> // (a*b)%m = (a%m * b%m) %m
T modMul(T a, T b, T m) { return mod(mod(a, m) * mod(b, m), m); }

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

// pow formula source: from a book sended by Juan Diego Morón
template<typename T>
T pow(T n, T e)
{
    T res { 1 };

    while(e > T(0))
    {
      if (e & 1)
        res = res * n;

      e >>= 1;
      n = n * n;
    }

    return res;
}

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
T naturalSummatory(T n) { return n * (n + 1) / 2; }
template<typename T>
T naturalSummatory(T n, T m) { return modDivide(modMul(n, modSum(n, T(1), m), m), T(2), m); }

template<typename T> // 1^2 + 2^2 + 3^2 + 4 ^2+ ... + n^2
T quadraticSummatory(T n) { return n * (n + 1) * ( 2 * n + 1) / 6; }
template<typename T>
T quadraticSummatory(T n, T m)
{
    return modDivide(modMul(n, modMul(modSum(n, T(1), m),modSum(modMul(T(2), n, m), T(1) , m), m) , m), T(6), m);
}

template <typename T>  // 1 + x^1 + x^2 + x^3  + ... + x^n --> (x ^ (n + 1) - 1) / (x - 1)
T finiteGeometricSerie(T x, T n)
{
    if(x == T(1))
        return n + T(1);

    return (pow(x, n + T(1)) - T(1)) / (x - T(1));
}
template<typename T>
T finiteGeometricSerie(T x, T n, T m)
{
    if(x == T(1))
        return mod(n + 1, m);

    return modDivide(modSub(pow(x, modSum(n, T(1), m), m), T(1), m), modSub(x, T(1), m), m);
}


/* Source: http://codeforces.com/blog/entry/14516
  * put this at the beginning of your main function::  F[0] = F[1] = 1;
  */
# include <map>

using type_t = long long;

constexpr type_t M = 100000ull;
std::map<type_t, type_t> F;

type_t Fib(type_t n) // modular fibonacci
{
    if(F.count(n))
        return F[n];

    type_t k { n >> 1 };

    // F(2 * k + 1) = F(k) * F(k + 1) + F(k - 1) * F(k)
    if (n & 1)
        return F[n] = (modMul(Fib(k), Fib(k + 1), ::M) + modMul(Fib(k - 1), Fib(k), ::M)) % ::M;

    // F(2 * k) = F(k) ^ 2 + F(k - 1) ^ 2
    return F[n] = (modMul(Fib(k), Fib(k), ::M) + modMul(Fib(k - 1), Fib(k - 1), ::M)) % ::M;
}

inline type_t Fibonacci(type_t n)
{
    return n == 0 ? 0 : Fib(n - 1);
}

# include <cmath>
# include <vector>
# include <cstdint>
// source: https://stackoverflow.com/questions/9625663/calculating-and-printing-the-nth-prime-number/45656516
int32_t popCount(int32_t n)
{
    n -= (n >> 1) & 0x55555555;
    n = ((n >> 2) & 0x33333333) + (n & 0x33333333);
    n = ((n >> 4) & 0x0F0F0F0F) + (n & 0x0F0F0F0F);
    return (n * 0x01010101) >> 24;
}

int32_t nth(int32_t n)
{
    if (n < 2)
        return 2;
    if (n == 2)
        return 3;
    if (n == 3)
        return 5;

    int32_t limit, root, count = 2;
    limit =(int32_t)(n * (log(n) + log(log(n)))) + 3;
    root = (int32_t)sqrt(limit);

    switch(limit % 6)
    {
        case 0:
            limit = 2 * (limit / 6) - 1;
            break;
        case 5:
            limit = 2 * (limit / 6) + 1;
            break;

        default: limit = 2 * (limit / 6);
    }

    switch(root % 6)
    {
        case 0:
            root = 2 * (root / 6) - 1;
            break;
        case 5:
            root = 2 * (root / 6) + 1;
            break;

        default: root = 2 * (root / 6);
    }

    int32_t dim = (limit + 31) >> 5;

    std::vector<int32_t> sieve(dim);

    for(int32_t i = 0; i < root; ++i)
    {
        if ((sieve[i >> 5] & (1 << (i & 31))) == 0)
        {
            int32_t start, s1, s2;
            if ((i & 1) == 1)
            {
                start = i * ( 3 * i + 8) + 4;
                s1 = 4 * i + 5;
                s2 = 2 * i + 3;
            }
            else
            {
                start = i * (3 * i + 10) + 7;
                s1 = 2 * i + 3;
                s2 = 4 * i + 7;
            }
            for(int32_t j = start; j < limit; j += s2)
            {
                sieve[j >> 5] |= 1 << (j & 31);
                j += s1;
                if (j >= limit)
                    break;
                sieve[j >> 5] |= 1 << (j & 31);
            }
        }
    }

    int32_t i;
    for(i = 0; count < n; ++i)
        count += popCount(~sieve[i]);

    --i;
    int32_t mask = ~sieve[i];
    int32_t p;
    for(p = 31; count >= n; --p)
        count -= (mask >> p) & 1;

    return 3 * (p + (i << 5)) + 7 + (p & 1);
}

# include <iostream>

int main()
{
    using namespace std;

    F[0] = F[1] = 1; // Fibonacci's stuff

    // for a litle bit faster standar c++ input, avoid if interactive I/O
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}

// creating a vector with no duplicates and ordered, eficiently
// just to use [] instead of iterators xD
# include <vector>
# include <unordered_set>
# include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);

    size_t n; std::cin >> n;

    std::unordered_set<int> data;
    for(size_t i{}; i < n; ++i)
    {
        int d;
        std::cin >> d;

        data.insert(d);
    }

    std::vector<int> cuteData;
    cuteData.assign(data.begin(), data.end());
    std::sort(cuteData.begin(), cuteData.end());
}
