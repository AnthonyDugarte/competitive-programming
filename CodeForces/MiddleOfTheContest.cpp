// Codeforces Round #544 (Div. 3)
#include <bits/stdc++.h>

using type_t = int64_t;
using utype_t = uint64_t;

int main()
{
    type_t hh1, mm1, hh2, mm2;
    char c;
    std::cin >> hh1 >> c >> mm1 >> hh2 >> c >> mm2;

    type_t dif = std::abs((hh1 * 60 + mm1) - (hh2 * 60 + mm2)) >> 1;

    while (dif >= 60)
    {
        ++hh1;
        dif -= 60;
    }

    mm1 += dif;

    if (mm1 >= 60)
    {
        ++hh1;
        mm1 -= 60;
    }

    if (hh1 < 10)
        std::cout << 0;
    std::cout << hh1 << ":";

    if (mm1 < 10)
        std::cout << 0;
    std::cout << mm1;

    return 0;
}
