#include <bits/stdc++.h>
using namespace std;

using type_t = unsigned long long;

type_t term(type_t n, type_t d)
{
    return n == 1 ? 1 : term(1, d) + (n - 1) * d;
}


type_t natural_sommatory_with_d(type_t n, type_t d)
{
    return n *(term(1, d) + term(n, d)) / 2;
}

int main()
{
    size_t n = 1;

    while(cin >> n and n != 0)
        cout << natural_sommatory_with_d(n, n + 1) << "\n";

    return 0;
}