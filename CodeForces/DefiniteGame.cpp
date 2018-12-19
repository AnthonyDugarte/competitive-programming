// Avito Cool Challenge 2018
#include <bits/stdc++.h>

using namespace std;

int main()
{
    size_t n;
    cin >> n;

    size_t x{ n };

    while(n != 1 and --x != 1)
    {
        if((n / x ) * x != n)
            n -= x;
    }

    cout << n << '\n';
}