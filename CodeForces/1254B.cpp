#include <bits/stdc++.h>

using namespace std;

using type_t = int64_t;
type_t t, n, m, acc, aux;

int main()
{
    cin >> t;
    while (--t != -1)
    {
        cin >> n >> m;

        acc = 0;

        for (int i{0}; i < n; ++i)
        {
            cin >> aux;
            acc += aux << 1;
        }

        if (m < n || n == 2)
        {
            cout << -1 << "\n";
            continue;
        }

        cout << acc << "\n";

        cout << 1 << " " << n << "\n";
        for (int i = 1; i < n; ++i)
            cout << i << " " << i + 1 << "\n";
    }

    return 0;
}