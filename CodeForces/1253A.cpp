#include <bits/stdc++.h>

using namespace std;

int t, n, a[static_cast<int>(1e5)], b[static_cast<int>(1e5)], l, r, k;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> t;

    while (--t != -1)
    {
        cin >> n;

        for (int i{0}; i < n; ++i)
            cin >> a[i];

        for (int i{0}; i < n; ++i)
            cin >> b[i];

        bool f{false};

        l = r = -1;
        k = 0;

        for (int i{0}; i < n; ++i)
        {
            if (a[i] != b[i])
            {
                if (r != -1)
                {
                    f = true;
                    break;
                }

                if (l == -1)
                {
                    l = i;
                    k = b[i] - a[i];
                }

                if (k < 0 || b[i] - a[i] != k)
                {
                    f = true;
                    break;
                }
            }
            else
            {
                if (l != -1)
                    r = i;
            }
        }

        cout << (f ? "NO" : "YES") << "\n";
    }

    return 0;
}