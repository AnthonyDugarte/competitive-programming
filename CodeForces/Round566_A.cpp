#include <bits/stdc++.h>

using std::cin;
using std::cout;

int main()
{
    size_t n;
    cin >> n;

    if (n & 1)
        cout << 0;
    else
        cout << (1 << (n >> 1));

    return 0;
}