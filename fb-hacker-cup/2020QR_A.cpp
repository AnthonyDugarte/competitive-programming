#include <bits/stdc++.h>
using namespace std;

template <typename T>
void f_cout(T val) { cout << val << "\n"; }
template <typename T, typename... TT>
void f_cout(T val, TT... tail) { cout << val << " : ", f_cout(tail...); }

int t, n, acc;
char c;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> t;

    for (int tt{0}; tt < t; ++tt, acc = 0)
    {
        cin >> n;

        for (int i{0}; i < n; ++i)
        {
            cin >> c;
            if (c == 'A')
                ++acc;
            else
                --acc;
        }

        cout << "Case #" << tt + 1 << ": " << (acc == 1 || acc == -1 ? 'Y' : 'N') << "\n";
    }

    return 0;
}
