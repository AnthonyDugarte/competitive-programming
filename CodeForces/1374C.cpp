#include <bits/stdc++.h>

using namespace std;

template <typename T>
void f_cout(T val) { cout << val << endl; }
template <typename T, typename... TT>
void f_cout(T val, TT... tail) { cout << val << " : ", f_cout(tail...); }

int64_t t, n, l, r, o, acc;
string s;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> t;

    for (int ti{0}; ti < t; ++ti)
    {
        cin >> n;
        cin >> s;

        l = r = o = acc = 0;

        for (int i{0}; i < n; ++i)
        {
            if (s[i] == '(')
                ++o;
            else
                --o;

            if (o == -1)
            {
                ++acc;
                ++o;
            }
        }

        cout << acc << "\n";
    }

    return 0;
}