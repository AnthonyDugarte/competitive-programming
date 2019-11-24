#include <bits/stdc++.h>

using namespace std;

int k, n, a, b;
string s, t;
bool broken;

int main()
{
    ios_base::sync_with_stdio(false);

    s.reserve(1e4);
    t.reserve(1e4);

    cin >> k;

    while (--k >= 0)
    {
        cin >> n;
        cin >> s >> t;

        a = b = -1;
        broken = false;

        for (int i{0}; i < n; ++i)
            if (s[i] != t[i])
            {
                if (a != -1 && b != -1)
                {
                    broken = true;
                    break;
                }

                (a == -1 ? a : b) = i;
            }

        if (a != -1 && b != -1)
        {
            if (!broken)
                broken = !(s[a] == s[b] && t[b] == t[a]);
        }
        else
            broken = true;

        cout << (!broken ? "YES" : "NO") << "\n";
    }

    return 0;
}