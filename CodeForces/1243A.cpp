#include <bits/stdc++.h>

using namespace std;

int k, n, a[1000], res;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> k;

    while (--k >= 0)
    {
        cin >> n;
        for (int i{0}; i < n; ++i)
            cin >> a[i];
        sort(a, a + n, greater<int>());

        res = 0;
        for (int i{0}; i < n; ++i)
            res = max(res, min(i + 1, a[i]) * min(i + 1, a[i]));

        cout << static_cast<int>(sqrt(res)) << "\n";
    }

    return 0;
}