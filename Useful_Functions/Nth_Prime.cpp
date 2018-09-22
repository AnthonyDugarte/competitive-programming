// source: https://stackoverflow.com/questions/9625663/calculating-and-printing-the-nth-prime-number/45656516
# include <cmath>
# include <vector>
# include <cstdint>

int32_t popCount(int32_t n)
{
    n -= (n >> 1) & 0x55555555;
    n = ((n >> 2) & 0x33333333) + (n & 0x33333333);
    n = ((n >> 4) & 0x0F0F0F0F) + (n & 0x0F0F0F0F);
    return (n * 0x01010101) >> 24;
}

int32_t nth_prime(int32_t n)
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

#include <iostream>

int main()
{
  // https://m.wolframalpha.com/input/?i=10%2C000%2C000th+prime
  std::cout << nth_prime(10000000) << "\n";

  return 0;
}
