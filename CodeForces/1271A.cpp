#include <bits/stdc++.h>

int a, b, c, d, e, f, r{0};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin >> a >> b >> c >> d >> e >> f;

    int s2{std::min({b, c})};

    if (e >= f)
    {
        r += std::min(a, d) * e;
        d -= std::min(a, d);

        std::cout << r + std::min(s2, d) * f << "\n";
    }
    else
    {
        r += std::min(s2, d) * f;
        d -= std::min(s2, d);

        std::cout << r + std::min(a, d) * e << "\n";
    }

    return 0;
}