
#include <bits/stdc++.h>
using namespace std;

template <typename T>
void f_cout(T val) { cout << val << "\n"; }
template <typename T, typename... TT>
void f_cout(T val, TT... tail) { cout << val << " : ", f_cout(tail...); }

int t{1};
string s;

int memo[25][25 * 9 + 1][25 * 9 + 1];
int memo_it[25][25 * 9 + 1][25 * 9 + 1];

int solve(int i = 0, int prev = 0, int acc = 0)
{
    if (i == s.size())
        return acc >= prev;

    if (memo_it[i][prev][acc] == t)
        return memo[i][prev][acc];
    memo_it[i][prev][acc] = t;

    int _acc = acc + s[i] - '0';
    return memo[i][prev][acc] = solve(i + 1, prev, _acc) + (_acc >= prev ? solve(i + 1, _acc, 0) : 0);
}

int main()
{
    ios_base::sync_with_stdio(false);

    s.reserve(25);

    for (; cin >> s; ++t)
    {
        if (s == "bye")
            break;

        int res = solve();

        if (all_of(s.begin(), s.end(), [](char &c) -> bool { return c == '0'; }))
            res >>= 1;

        cout << t << ". " << res << "\n";
    }

    return 0;
}
