#include <bits/stdc++.h>
using namespace std;

template <typename T>
void f_cout(T val) { cout << val << "\n"; }
template <typename T, typename... TT>
void f_cout(T val, TT... tail) { cout << val << " : ", f_cout(tail...); }

int n, t{0};
tuple<int, int, int> blocks[30 * 3];

map<tuple<int64_t, int, int>, int> memo;
map<tuple<int64_t, int, int>, int> memo_it;

int solve(int x = 2501, int y = 2501, int64_t taken = 0)
{
    int max_z{0};

    int &it{memo_it[{taken, x, y}]}, &mem{memo[{taken, x, y}]};

    if (it == t)
        return mem;
    it = t;

    for (int j{0}; j < n * 3; ++j)
    {
        int64_t ii{int64_t(1) << j};
        if (taken & ii)
            continue;

        int &xx{get<0>(blocks[j])},
            &yy{get<1>(blocks[j])},
            &zz{get<2>(blocks[j])};

        if ((xx < x && yy < y) || (yy < x && xx < y))
            max_z = max(max_z, zz + solve(xx, yy, taken & ii));
    }

    return mem = max_z;
}

int main()
{
    ios_base::sync_with_stdio(false);

    while (cin >> n)
    {
        ++t;

        if (!n)
            break;

        for (int i{0}, x, y, z; i < n; ++i)
        {
            cin >> x >> y >> z;

            tuple<int, int, int> *b{blocks + i * 3};

            get<0>(*b) = get<1>(*(b + 1)) = get<2>(*(b + 2)) = x;
            get<1>(*b) = get<2>(*(b + 1)) = get<0>(*(b + 2)) = y;
            get<2>(*b) = get<0>(*(b + 1)) = get<1>(*(b + 2)) = z;
        }

        cout << solve() << "\n";
    }
    return 0;
}
