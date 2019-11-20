#include <bits/stdc++.h>

using namespace std;

unsigned long long t, a, b, res;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> t;

    while (--t != -1)
    {
        cin >> a >> b;
        res = 0;

        unsigned long long m{min(a, b)};

        b -= m;
        a -= m;

        b += a;

        res += b / 5;
        b -= (b / 5) * 5;

        res += b / 2;
        b -= (b / 2) * 2;

        cout << res + b << "\n";
    }

    return 0;
}