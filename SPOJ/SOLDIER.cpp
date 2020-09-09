#include <bits/stdc++.h>
using namespace std;

template <typename T>
void f_cout(T val) { cout << val << "\n"; }
template <typename T, typename... TT>
void f_cout(T val, TT... tail) { cout << val << " : ", f_cout(tail...); }

int n, t;

constexpr int INF = 10001 * 101 * 10;

tuple<int, int> data[6][101];
int sz[6];

int solve(int i, int acc, int pre = INF)
{
    if (acc < 0)
        return 0;
    if (i == 6)
        return pre;

    int res = 0;
    for (int ii{0}; ii < sz[i]; ++ii)
        res = max(res, solve(i + 1, acc - get<0>(data[i][ii]), get<1>(data[i][ii])));

    return min(res, pre);
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> t;

    for (int i{0}, aux; i < n; ++i, ++sz[aux - 1])
        cin >> aux >> get<0>(data[aux - 1][sz[aux - 1]]) >> get<1>(data[aux - 1][sz[aux - 1]]);

    for (int i{0}; i < 6; ++i)
        if (!sz[i])
        {
            cout << 0 << "\n";
            return 0;
        }

    cout << solve(0, t) << "\n";

    return 0;
}
