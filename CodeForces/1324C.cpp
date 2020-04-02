#include <bits/stdc++.h>
using namespace std;

int t, acc, aux;
string s;

int main()
{
    s.reserve(static_cast<size_t>(1e5) << 1);

    cin >> t;

    while (--t != -1)
    {
        cin >> s;
        acc = aux = 0;

        for (char &c : s)
            if (c == 'L')
                ++aux;
            else
            {
                acc = max(acc, aux + 1);
                aux = 0;
            }

        cout << max(acc, aux + 1) << "\n";
    }

    return 0;
}