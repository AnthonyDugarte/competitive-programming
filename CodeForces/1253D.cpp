#include <bits/stdc++.h>

using namespace std;

vector<int> v(static_cast<size_t>(2e5), -1);

int &findF(int &x)
{
    if (v[x] == -1)
        return x;

    return v[x] = findF(v[x]);
}

void joinF(int &x, int &y)
{
    int &src{findF(x)}, &dst{findF(y)};

    if (src != dst) // cycle
        v[src] = dst;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n, m, x, y;
    cin >> n >> m;

    for (int i{0}; i < m; ++i)
    {
        cin >> x >> y;
        joinF(--x, --y);
    }

    map<int, int> r;
    set<int> l;
    vector<pair<int, bool>> vs; // bool -> r?

    for (int i{0}; i < n; ++i)
    {
        int &src{findF(i)};

        set<int>::iterator l_i{l.find(src)};
        if (l_i == l.end())
        {
            l.insert(src);
            vs.push_back({i, false});
        }

        r[src] = i;
    }

    for (auto &p : r)
        vs.push_back({p.second, true});

    sort(vs.begin(), vs.end(), [](pair<int, bool> &a, pair<int, bool> &b) -> bool {
        if (a.first == b.first)
            return !a.second;
        return a.first < b.first;
    });

    int res{0}, acc_p{0}, acc{0};

    for (auto &p : vs)
    {
        if (!p.second)
        {
            ++acc;
            ++acc_p;
        }
        else
            --acc;

        if (acc == 0)
        {
            if (acc_p > 1)
                res += acc_p - 1;
            acc_p = 0;
        }
    }

    cout << res << "\n";

    return 0;
}

// 14 9 1 2 7 2 3 4 3 7 7 5 8 3 8 6 11 12 2 14