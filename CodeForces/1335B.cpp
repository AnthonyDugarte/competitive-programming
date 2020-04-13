#include <bits/stdc++.h>
using namespace std;
int n, a, b, t;
string s;

int main()
{

    s.reserve(2000);

    cin >> t;

    while (--t != -1)
    {
        cin >> n >> a >> b;

        for (int i{0}; i < a; ++i)
            s[i] = 'a' + min(i, b - 1);

        for (int i{0}; i < n; ++i)
            cout << s[i % a];
        cout << "\n";
    }

    return 0;
}