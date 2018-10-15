// http://coj.uci.cu/24h/problem.xhtml?pid=3377
// https://stackoverflow.com/questions/31270226/how-to-calculate-smallest-number-with-certain-number-of-divisors
// http://www.primepuzzles.net/problems/prob_019.htm

#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <cstdint>
#include <limits>
#include <algorithm>

std::vector<size_t> get_primeFactors(size_t n)
{
    std::vector<size_t> prime_ns;

    // evens out
    while(n % 2 == 0) { prime_ns.push_back(2); n >>= 1; }

    // odds out
    for(size_t i { 3 }, end{ static_cast<size_t>(std::sqrt(n)) }; i <= end; i += 2)
        while(n % i == 0) { prime_ns.push_back(i); n /= i; }

    // n is already prime, sooo...
    if(n > 2) prime_ns.push_back(n);
    
    return prime_ns;
}

using type_t = unsigned long long;

int32_t nth_prime(int32_t n); //  [1] => 2, [2] => 3 ...
type_t f_pow(type_t n, type_t e);

size_t get_lowest(std::vector<size_t> primes, std::set<std::vector<size_t>> &memo, type_t curr_lowest = std::numeric_limits<type_t>::max())
{
    std::sort(primes.begin(), primes.end(), std::greater<size_t>());

    memo.insert(primes); // already did this calculation
    
    type_t res { 1ull };
    for(size_t i{ 0 }; i < primes.size(); ++i)
        res *= f_pow(nth_prime(i + 1), primes[i] - 1);
    
    if(curr_lowest < res)
        res = curr_lowest;
    
    for(size_t j{ 0 }; j < primes.size(); ++j)
    {
        for(size_t k{ 0 }; k < primes.size(); ++k)
        {
            if(j == k)
                continue;
            
            std::vector<size_t> new_comb(1, primes[j]);

            for(size_t i{ 0 }; i < primes.size(); ++i)
            {
                if(i == j)
                    continue;
                if(i == k)
                    new_comb[0] *= primes[i];
                else new_comb.push_back(primes[i]);
            }
            
            if(memo.find(new_comb) == memo.end()) // if already did this, don't do it again xD
                res = get_lowest(new_comb, memo, res);
        }
    }
    
    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    size_t T;
    std::cin >> T;

    while(--T != -1)
    {
        std::set<std::vector<size_t>> memo;

        size_t n; std::cin >> n;
        std::cout << get_lowest(get_primeFactors(n), memo) << "\n";
    }

    return 0;
}

type_t f_pow(type_t n, type_t e)
{
    type_t res { 1 };

    while(e > 0ull)
    {
      if (e & 1) res = res * n;

      e >>= 1;
      n = n * n;
    }

    return res;
}


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