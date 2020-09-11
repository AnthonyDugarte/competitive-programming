#include <bits/stdc++.h>
using namespace std;

template <typename T>
void f_cout(T val) { cout << val << "\n"; }
template <typename T, typename... TT>
void f_cout(T val, TT... tail) { cout << val << " : ", f_cout(tail...); }

int t{1}, n;
int mixs[100];

constexpr int INF{100 * 100 * 100};

tuple<int, int64_t> memo[100][100];
int memo_it[100][100];

tuple<int, int64_t> solve(int l, int r)
{
    if (l == r)
        return {mixs[l], 0};

    int &it{memo_it[l][r]};
    tuple<int, int64_t> &sol{memo[l][r]};

    if (it == t)
        return sol;

    it = t, sol = {INF, INF};

    for (int i{0}; l + i < r; ++i)
    {
        tuple<int, int64_t> a{solve(l, l + i)}, b{solve(l + i + 1, r)};

        tuple<int, int64_t> tmp_sol{
            (get<0>(a) + get<0>(b)) % 100,
            get<1>(a) + get<1>(b) + get<0>(a) * get<0>(b)};

        if (get<1>(sol) > get<1>(tmp_sol) || get<1>(sol) == get<1>(tmp_sol) && get<0>(sol) > get<0>(tmp_sol))
            sol = tmp_sol;
    }

    return sol;
}

int main()
{
    ios_base::sync_with_stdio(false);

    while (cin >> n)
    {
        for (int i{0}; i < n; ++i)
            cin >> mixs[i];

        cout << get<1>(solve(0, n - 1)) << "\n";

        ++t;
    }

    return 0;
}
