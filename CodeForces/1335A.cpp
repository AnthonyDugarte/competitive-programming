#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;

    cin >> t;
    while (--t != -1)
    {
        cin >> n;

        if (n <= 2)
            cout << 0;
        else
            cout << (n >> 1) - !(n & 1);
        cout << "\n";
    }

    return 0;
}