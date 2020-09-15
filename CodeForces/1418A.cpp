#include <bits/stdc++.h>
using namespace std;

template <typename T>
void f_cout(T val) { cout << val << "\n"; }
template <typename T, typename... TT>
void f_cout(T val, TT... tail) { cout << val << " : ", f_cout(tail...); }

int64_t t, x, y, k, r;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> t;

    while (--t != -1)
    {
        cin >> x >> y >> k;

        r = ceil((long double)(y * k + k - 1) / (x - 1)) + k;

        cout << r << "\n";
    }

    return 0;
}
