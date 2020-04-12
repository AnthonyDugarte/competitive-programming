#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, a[(int)(1e5)], b[(int)(1e5)], av[2];
    bool valid;

    cin >> t;
    while (--t != -1)
    {
        cin >> n;
        valid = true;

        av[0] = av[1] = 0;

        for (int i{0}; i < n; ++i)
            cin >> a[i];

        for (int i{0}; i < n; ++i)
            cin >> b[i];

        valid = a[0] == b[0];

        for (int i{0}; i < n; ++i)
        {
            if ((a[i] < b[i] && !av[1]) || (a[i] > b[i] && !av[0]))
            {
                valid = false;
                break;
            }

            if (a[i] == 1)
                av[1] = 1;
            else if (a[i] == -1)
                av[0] = 1;
        }

        cout << (valid ? "YES" : "NO") << "\n";
    }
    return 0;
}