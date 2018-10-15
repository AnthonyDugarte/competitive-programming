// https://en.wikipedia.org/wiki/Ordered_Bell_number

#include <map>

using type_t = unsigned long long;
constexpr type_t mod = static_cast<type_t>(1e6 + 3);

type_t binomialCoefficient(type_t n, type_t k);

std::map<type_t, type_t> obm_memo{ {0, 1} };
type_t orderedBellNumber(type_t n)
{
    std::map<type_t, type_t>::iterator search{ obm_memo.find(n) };
    if(search != obm_memo.end())
        return (*search).second;
    
    type_t res{ 0 };
    
    for(type_t i{ 1 }; i <= n; ++i)
        res = (res + ( binomialCoefficient(n, i) * orderedBellNumber(n - i))) % mod;
    return obm_memo[n] = res;
}

std::map<std::pair<type_t, type_t>, type_t> bc_memo;
type_t binomialCoefficient(type_t n, type_t k)
{
    std::map<std::pair<type_t, type_t>, type_t>::iterator search{ bc_memo.find({n, k}) };

    if(search != bc_memo.end())
        return (*search).second;
    
    if(n == k or k == 0)
        return bc_memo[{n, n}] = bc_memo[{n, 0}] = 1;
    
    return bc_memo[{n, k}] = (binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k)) % mod;
}