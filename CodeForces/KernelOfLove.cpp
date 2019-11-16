#include <bits/stdc++.h>

using namespace std;
using type_t = uint64_t;

map<type_t, type_t> memo;
type_t fib(type_t n)
{
    map<type_t, type_t>::iterator it{memo.find(n)};

    if (it != memo.end())
        return it->second;

    return n < 3 ? 1 : memo[n] = fib(n - 1) + fib(n - 2);
}

type_t gcd(type_t a, type_t b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int rr(int n)
{
    int acc{n < 3 ? 0 : 1}, l{(n - 1) / 3};
    acc += l << 1;

    if ((n - 1) % 3 == 2)
        ++acc;

    return acc;
}

int r(int n)
{
    int acc{n < 3 ? 0 : 1};

    for (int i{1}; i < n; ++i)
    {
        type_t a{fib(i)}, b{fib(i + 1)}, c{fib(i + 2)};
        if (a + b != c || !(c & 1) || gcd(a, b) > 1)
            continue;

        ++acc;
    }

    return acc;
}

int t, n;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> t;

    while (--t != -1)
    {
        cin >> n;

        cout << rr(n) << "\n";
        // cout << r(n) << "\n";
    }

    return 0;
}