// http://coj.uci.cu/24h/problem.xhtml?pid=3801

# include <iostream>
# include <map>
# include <list>

using data_t = unsigned long;

const data_t M = 1000000;

std::map<data_t, data_t> F;
data_t Fib(data_t n)
{
  if(F.count(n))
    return F[n];

  data_t k { n >> 1 };

	if (n & 1) // n=2*k+1
    return (F[n] = (Fib(k) * Fib(k+1) + Fib(k-1) * Fib(k)) % M);

  return (F[n] = (Fib(k) * Fib(k) + Fib(k-1) * Fib(k-1)) % M); // n=2*k
}

int main()
{
  F[0] = F[1] = 1;

  size_t cases;
  std::cin >> cases;

  if(cases == 0)
    return 0;

  std::list<std::pair<data_t, data_t>> answers;
  data_t N, R1, R2;

  auto pow = [M = ::M](data_t x, data_t n)->data_t
  {
    data_t res = 1;

    while(n > 0)
    {
      if (n & 1)
        res = (res * x) % M;

      n >>= 1;
      x = (x * x) % M;
    }
    return res;
  };

  for(size_t test{}; test < cases; ++test)
  {
    scanf("%lu %lu %lu", &N, &R1, &R2);

    data_t F1 { Fib(N - 3) };
    data_t F2 { Fib(N - 2) };

     R1 = pow(R1, F1);
     R2 = pow(R2, F2);

    answers.emplace_back(std::make_pair( (N - 1) * 3 + 1, (R1 * R2) % M ));
  }

  for(auto s : answers)
    printf("At week %lu we obtain %lu new rabbits.\n", s.first, s.second);
  return 0;
}
