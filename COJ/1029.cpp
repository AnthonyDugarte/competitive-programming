#include <bits/stdc++.h>

using type_t = long long;
constexpr type_t mod { 1000003 };

// Extended Euclidean algorithm
type_t xGCD(type_t a, type_t b, type_t &x, type_t &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    type_t x1, y1, gcd{ xGCD(b, a % b, x1, y1) };
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// factorial of n modulo mod
type_t modfact(type_t n) {
    type_t result = 1;
    while (n > 1) {
        (result *= n) %= mod;
        --n;
    }
    return result;
}

type_t modf(type_t n, type_t m) 
{
    return (n % m + m) % m; 
}

// inverse of a modulo mod
type_t inverse(type_t a) {
    type_t x, y;
    xGCD(a, mod, x, y);
    
    return modf(x, mod);
}

// binomial coefficient nCk modulo mod
type_t binomialCoeff(type_t n, type_t k)
{
    return modfact(n) * inverse(modfact(k)) * inverse(modfact(n - k)) % mod;
}

type_t pow(type_t n, type_t e)
{
    type_t res { 1 };

    while(e > type_t{0})
    {
      if (e & 1)
        (res *= n) %= mod;

      e >>= 1;
      (n *= n) %= mod;
    }

    return res;
}

double f(type_t N, type_t R, type_t K)
{
    return (binomialCoeff(R, K) * pow((N << 1) - 1, R - K)) % mod;
}

int main()
{
    size_t t;
    std::cin >> t;

    while(--t != -1)
    {
        type_t N, R, K;
        std::cin >> N >> R >> K;
        std::cout << f(N, R, K) << std::endl;
    }
    
    return 0;
}