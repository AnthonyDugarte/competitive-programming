#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int t, n;

    cin >> t;

    while (--t != -1)
    {
        cin >> n;

        if (n == 1)
            cout << -1 << "\n";
        else
        {
            int threes = 1 + ((n - 1) % 3 == 0);

            for (int i{0}; i < n - threes; ++i)
                cout << 2;
            for (int i{0}; i < threes; ++i)
                cout << 3;
            cout << "\n";
        }
    }

    return 0;
}