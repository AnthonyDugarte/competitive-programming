// https://en.wikipedia.org/wiki/Binomial_distribution

#include <bits/stdc++.h>

using namespace std;

using type_t = unsigned long long;

using binomial_pair = pair<type_t, type_t>;
using container_t =  map<binomial_pair, type_t>;
container_t bc_memo;

type_t binomialCoefficient(type_t n, type_t k)
{
    container_t::iterator search{ bc_memo.find({n, k}) };

    if(search != bc_memo.end())
        return (*search).second;
    
    if(n == k or k == 0)
        return bc_memo[binomial_pair{n, n}] = bc_memo[binomial_pair{n, 0}] = 1;
    
    return bc_memo[binomial_pair{n, k}] = binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

double BinomialDistribution(type_t k, type_t n, double p)
{
    return binomialCoefficient(n, k) * std::pow(p, static_cast<double>(k)) * std::pow(1.0 - p, static_cast<double>(n - k));
}