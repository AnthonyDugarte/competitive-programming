#include <bits/stdc++.h>
using namespace std;

template <typename T>
void f_cout(T val) { cout << val << "\n"; }
template <typename T, typename... TT>
void f_cout(T val, TT... tail) { cout << val << " : ", f_cout(tail...); }

int t, n;
string I, O;
char m[50][50];

void p(int i, int j, int delta)
{
    if (j == i)
        m[i][j] = 'Y';
    else if (I[j] == 'N' || O[j + delta] == 'N' || m[i][j + delta] == 'N')
        m[i][j] = 'N';
    else
        m[i][j] = 'Y';
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> t;

    I.reserve(50);
    O.reserve(50);

    for (int tt{0}; tt < t; ++tt)
    {
        cin >> n >> I >> O;

        for (int i{0}; i < n; ++i)
        {
            for (int j{i}; j < n; ++j)
                p(i, j, -1);
            for (int j{i}; j >= 0; --j)
                p(i, j, 1);
        }

        cout << "Case #" << tt + 1 << ":\n";
        for (int i{0}; i < n; ++i, cout << "\n")
            for (int j{0}; j < n; ++j)
                cout << m[i][j];
    }

    return 0;
}
