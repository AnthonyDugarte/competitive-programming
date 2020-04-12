
#include <bits/stdc++.h>
using namespace std;
int t, n, aux, p, r, d;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> t;
    while (--t != -1)
    {
        cin >> n;
        r = d = 0;
        for (int i{0}; i < n; ++i)
        {
            cin >> aux;
            if (!i)
                p = aux;
            else if (aux < p)
            {
                ++d;
                r = max(r, (int)floor(log2(abs(p - aux))));
            }
            p = max(p, aux);
        }
        cout << r + (!!d) << "\n";
    }

    return 0;
}