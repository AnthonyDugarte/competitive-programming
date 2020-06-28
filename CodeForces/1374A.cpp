#include <bits/stdc++.h>

using namespace std;

template <typename T>
void f_cout(T val) { cout << val << endl; }
template <typename T, typename... TT>
void f_cout(T val, TT... tail) { cout << val << " : ", f_cout(tail...); }

int64_t t, x, y, n, k;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> t;

    for (int ti{0}; ti < t; ++ti)
    {
        cin >> x >> y >> n;

        k = (n / x) * x + y;

        while (k > n)
            k -= x;

        cout << k << "\n";
    }

    return 0;
}