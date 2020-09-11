#include <bits/stdc++.h>
using namespace std;

template <typename T>
void f_cout(T val) { cout << val << "\n"; }
template <typename T, typename... TT>
void f_cout(T val, TT... tail) { cout << val << " : ", f_cout(tail...); }

int t, n;

int students[20];

int64_t memo[1048576];
int memo_it[1048576];

int64_t solve(int i = 0, int taken = 0)
{
    if (i == n)
        return 1;

    int &t_i{memo_it[taken]};
    int64_t &res{memo[taken]};

    if (t_i == t)
        return res;

    t_i = t;
    res = 0;

    for (int j{0}; j < n; ++j)
        if (!(taken & 1 << j) && students[i] & 1 << j)
            res += solve(i + 1, taken | 1 << j);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> t;

    while (t)
    {
        cin >> n;

        for (int i{0}; i < n; ++i)
        {
            students[i] = 0;
            for (int j{0}, aux; j < n; students[i] |= aux ? 1 << j : 0, ++j)
                cin >> aux;
        }

        cout << solve() << "\n";

        --t;
    }

    return 0;
}