#include <bits/stdc++.h>
using namespace std;

template <typename T>
void f_cout(T val) { cout << val << "\n"; }
template <typename T, typename... TT>
void f_cout(T val, TT... tail) { cout << val << " : ", f_cout(tail...); }

int t, n, arr[int(1e5) << 1], memo[int(1e5) << 1][2], memo_it[int(1e5) << 1][2];

int solve(int i = 0, bool frnd = true)
{
    if (i >= n)
        return 0;

    if (memo_it[i][frnd] == t)
        return memo[i][frnd];

    memo_it[i][frnd] = t;

    return memo[i][frnd] = min(
               (arr[i] && frnd) + (arr[i + 1] && frnd) + solve(i + 2, !frnd),
               (arr[i] && frnd) + solve(i + 1, !frnd));
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> t;

    while (t)
    {
        cin >> n;

        for (int i{0}; i < n; ++i)
            cin >> arr[i];

        cout << solve();
        cout << "\n";

        --t;
    }

    return 0;
}