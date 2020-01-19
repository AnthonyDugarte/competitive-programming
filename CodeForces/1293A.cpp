#include <bits/stdc++.h>

using namespace std;

int t, n, s, k, aux;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> t;

    while (--t != -1)
    {
        cin >> n >> s >> k;

        vector<bool> kk(n, true);

        for (int i{0}; i < k; ++i)
        {
            cin >> aux;
            kk[aux - 1] = false;
        }

        --s;
        for (int i{0}; i < n; ++i)
        {
            if ((s + i < n && kk[s + i]) || (s - i >= 0 && kk[s - i]))
            {
                cout << i << "\n";
                break;
            }
        }
    }

    return 0;
}