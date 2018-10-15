/* Fibonacci function source: http://codeforces.com/blog/entry/14516
  * Time complexity: O(log n * log(log n))
  */
#include <map>
using type_t = long long;

constexpr type_t M = 1000007ll;
std::map<type_t, type_t> Found_F{ { 0, 1 }, { 1, 1 } }; // initial values

type_t Fib(type_t n) // modular fibonacci
{
  auto item { Found_F.find(n) }; // log n

  if(item != Found_F.end())
    return std::get<1>(*item);

  type_t k { n >> 1 };

    // F(2 * k + 1) = F(k) * F(k + 1) + F(k - 1) * F(k)
    if(n & 1)
        return Found_F[n] = (Fib(k) * Fib(k + 1) + Fib(k - 1) * Fib(k)) % ::M;

    // F(2 * k) = F(k) ^ 2 + F(k - 1) ^ 2
    return Found_F[n] = (Fib(k) * Fib(k) + Fib(k - 1) * Fib(k - 1)) % ::M;
}

type_t Fibonacci(type_t n)
{
    return n == 0 ? 0 : Fib(n - 1);
}

#include <iostream>

int main()
{
  for(size_t i{}; i < 100; ++i)
    std::cout << Fibonacci(i) << "\n";

  return 0;
}
