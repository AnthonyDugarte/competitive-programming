#include <iostream>
#include <map>
#include <cassert>

using type_t = unsigned long long;
constexpr type_t mod = static_cast<type_t>(1e6 + 3);

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

std::map<type_t, type_t> func_memo{ {0, 1} };
type_t func(type_t n)
{
    std::map<type_t, type_t>::iterator search{ func_memo.find(n) };
    if(search != func_memo.end())
        return (*search).second;
    
    type_t res{ 0 };
    
    for(type_t i{ 1 }; i <= n; ++i)
        res = (res + ( binomialCoefficient(n, i) * func(n - i))) % mod;
    return func_memo[n] = res;
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    type_t t;
    std::cin >> t;

    while(--t != -1)
    {
        type_t n;
        std::cin >> n;
        std::cout << func(n) << "\n";
    }
    
    return 0;
}