// Codeforces Round #544 (Div. 3)

#include <bits/stdc++.h>

using type_t = int64_t;
using utype_t = uint64_t;

int main()
{
    type_t n, k, in;
    std::cin >> n >> k;

    std::map<size_t, size_t> s;
    std::set<size_t> taken;

    while (--n != -1)
    {
        std::cin >> in;
        ++s[in % k];
    }

    size_t t{0};

    for (auto &p : s)
    {
        size_t more{std::min(p.second, s[(k - p.first) % k])};

        p.second -= more;
        s[k - p.first] -= more;

        t += more;

        if ((p.first << 1) % k == 0)
        {
            t += p.second >> 1;
            p.second -= (p.second >> 1) << 1;
        }
    }

    std::cout << (t << 1);

    return 0;
}
