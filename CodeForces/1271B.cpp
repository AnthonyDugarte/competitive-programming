#include <bits/stdc++.h>

int n, w{0}, b{0}, n_ops{0}, ops[3 * 200];
char s[200];

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::cin >> n;

    for (int i{0}; i < n; ++i)
    {
        std::cin >> s[i];

        ++(s[i] == 'W' ? w : b);

        if (i > 0 && s[i - 1] == 'B')
        {
            s[i - 1] = 'W';
            s[i] = (s[i] == 'W' ? 'B' : 'W');
            ops[n_ops++] = i;
        }
    }

    if (!((w + b) & 1) && (w & 1))
    {
        std::cout << -1 << "\n";
        return 0;
    }

    if (s[n - 1] == 'B')
        for (int i{1}; i < n - 1; i += 2)
            ops[n_ops++] = i;

    std::cout << n_ops << "\n";
    for (int i{0}; i < n_ops; ++i)
        std::cout << ops[i] << " ";

    if (n_ops)
        std::cout << "\n";

    return 0;
}