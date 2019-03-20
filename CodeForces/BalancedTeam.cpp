// Codeforces Round #544 (Div. 3)

#include <bits/stdc++.h>

using type_t = int64_t;
using utype_t = uint64_t;

void fastIO(bool untie)
{
    std::ios_base::sync_with_stdio(false);
    if (untie)
    {
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
    }
}

int main()
{
    fastIO(false);

    type_t n, power, dif, fac, max{0}, false_max{0};
    std::cin >> n;

    std::map<type_t, type_t> m;

    while (--n != -1)
    {
        std::cin >> power;
        ++m[power];
    }

    std::map<type_t, type_t>::iterator a, b;
    a = b = m.begin();

    while (b != m.end() && b->first - a->first <= 5)
    {
        false_max += b->second;
        ++b;
    }
    max = false_max;

    while (b != m.end())
    {
        while (a != m.end() && b->first - a->first > 5)
        {
            false_max -= a->second;
            ++a;
        }

        while (b != m.end() && b->first - a->first <= 5)
        {
            false_max += b->second;
            ++b;
        }

        max = std::max(max, false_max);
    }

    std::cout << max;

    return 0;
}
