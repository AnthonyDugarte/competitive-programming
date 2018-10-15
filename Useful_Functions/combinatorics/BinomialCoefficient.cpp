// Binomial coefficients -> source: https://en.wikipedia.org/wiki/Recurrence_relation

#include <map>

using type_t = unsigned long long;
std::map<std::pair<type_t, type_t>, type_t> bc_memo;
type_t binomialCoefficient(type_t n, type_t k)
{
    std::map<std::pair<type_t, type_t>, type_t>::iterator search{ bc_memo.find({n, k}) };

    if(search != bc_memo.end())
        return (*search).second;
    
    if(n == k or k == 0)
        return bc_memo[{n, n}] = bc_memo[{n, 0}] = 1;
    
    return bc_memo[{n, k}] = binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}