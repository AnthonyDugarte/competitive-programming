#include <bits/stdc++.h>
using namespace std;

template <typename T>
void f_cout(T val) { cout << val << "\n"; }
template <typename T, typename... TT>
void f_cout(T val, TT... tail) { cout << val << " : ", f_cout(tail...); }

int t, o, n, s;

tuple<int, int, int> data[1000];

int w_memo[1000][22][80];
int w_mem_it[1000][22][80];

int solve(int i, int acc_o, int acc_n)
{
    if (acc_o == 0 && acc_n == 0)
        return 0;
    if (i == s)
        return 800 * 10000;

    int &mem{w_memo[i][acc_o][acc_n]};
    int &mem_it{w_mem_it[i][acc_o][acc_n]};

    if (mem_it == t)
        return mem;

    mem_it = t;
    return mem = min(
               get<2>(data[i]) + solve(i + 1, max(0, acc_o - get<0>(data[i])), max(0, acc_n - get<1>(data[i]))),
               solve(i + 1, acc_o, acc_n));
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> t;

    while (t)
    {
        cin >> o >> n >> s;
        for (int i{0}; i < s; ++i)
            cin >> get<0>(data[i]) >> get<1>(data[i]) >> get<2>(data[i]);
        cout << solve(0, o, n) << "\n";

        --t;
    }

    return 0;
}
