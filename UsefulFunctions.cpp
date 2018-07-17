// some useful functions I've found interesting while solving some CP problems

// main idea from: https://stackoverflow.com/questions/11630321/why-does-c-output-negative-numbers-when-using-modulo
template<typename T>
T module(T n, T m) // c++' % operand is not module but remainder
{
    T res { n % m };

    return res < T(0) ? res + m : res; // if remainder is negative, we just sum m to get module
}

// formulae source: https://www.hackerearth.com/practice/notes/get-the-modulo-of-a-very-large-number-that-cannot-be-stored-in-any-data-type-in-cc-1/
template<typename T>
T modularSum(T a, T b, T m) // (a+b)%m = (a%m + b%m) %m
{
    return module(  module(a, m)   +  module(b, m),    m);
}

// formulae source: https://www.hackerearth.com/practice/notes/get-the-modulo-of-a-very-large-number-that-cannot-be-stored-in-any-data-type-in-cc-1/
template<typename T>
T modularMul(T a, T b, T m) // (a*b)%m = (a%m * b%m) %m
{
    return module(  module(a, m)  *  module(b, m),    m);
}

/* pow formula source: from a book sended by Juan Diego Morón
  * Note: modular part was added by me
  */
template<typename T>
T modularPow(T n, T e, T m)
{
  T res { 1 };

  while(e > T(0))
  {
    if (e & 1)
      res = modularMul(res, n, m);

    e >>= 1;
    n = modularMul(n, n, m);
  }

  return res;
}


/* Source: http://codeforces.com/blog/entry/14516
  * put this at the beginning of your main function::  F[0] = F[1] = 1;
  */
# include <map>

using type_t = unsigned long long;

constexpr type_t M = 100000ull;
std::map<type_t, type_t> F;

type_t Fibonacci(type_t n) // modular fibonacci, call it like  Fibonacci(n - 1), Fibonacci(0) is not valid
{
    if(F.count(n))
        return F[n];

    type_t k { n >> 1 };

    if (n & 1) // n = 2 * k + 1
        return F[n] = (modularMul(Fibonacci(k), Fibonacci(k + 1), ::M) + modularMul(Fibonacci(k - 1), Fibonacci(k), ::M)) % ::M;
    // n = 2 * k
    return F[n] = (modularMul(Fibonacci(k), Fibonacci(k), ::M) + modularMul(Fibonacci(k - 1), Fibonacci(k - 1), ::M)) % ::M;
}



inline type_t naturalSummatory(type_t n) // 1 + 2 + 3 + 4 + ... + n
{
    return n * (n + 1) >> 1;
}

inline type_t quadraticSummatory(type_t n) // 1^2 + 2^2 + 3^2 + 4 ^2+ ... + n^2
{
    return n * (n + 1) * ( 2 * n + 1) / 6;
}


int main()
{
    F[0] = F[1] = 1; // for Fibonacci

    return 0;
}
