#include <bits/stdc++.h>
using namespace std;

template <typename T>
void f_cout(T val) { cout << val << "\n"; }
template <typename T, typename... TT>
void f_cout(T val, TT... tail) { cout << val << " : ", f_cout(tail...); }

int t;
string a, b;

int memo[2000][2000];
int mem_it[2000][2000];

int solve(int i = 0, int j = 0)
{
    if (i == a.size() || j == b.size())
        return (a.size() - i) + (b.size() - j);
    if (a[i] == b[j])
        return solve(i + 1, j + 1);

    if (mem_it[i][j] == t)
        return memo[i][j];

    mem_it[i][j] = t;

    return memo[i][j] = 1 + min({
                                solve(i + 1, j),
                                solve(i, j + 1),
                                solve(i + 1, j + 1),
                            });
}

int main()
{
    ios_base::sync_with_stdio(false);

    a.reserve(2000);
    b.reserve(2000);

    cin >> t;

    while (t)
    {
        cin >> a >> b;

        cout << solve() << "\n";

        --t;
    }

    return 0;
}
