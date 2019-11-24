#include <bits/stdc++.h>

using namespace std;

uint64_t n, res{0};

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;

    while (!(n & 1))
    {
        n >>= 1;
        res = 2;
    }

    for (uint64_t i{3}; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            if (res) // 2+ primes composition
            {
                cout << 1 << "\n";
                return 0;
            }

            res = i;
            while (n % i == 0)
                n /= i;
        }
    }

    if (res == 0)
        cout << n; // prime already
    else if (n == 1)
        cout << res; // prime power factored
    else
        cout << 1; // 2 prime Composite number
    cout << "\n";

    return 0;
}