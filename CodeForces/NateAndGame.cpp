#include <bits/stdc++.h>
using namespace std;

int n, x0, y00, x1, y11, x2, y2, mn, mx, res{0}, cnt{0};

vector<pair<int, bool>> v;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i{0}; i < n; ++i)
    {
        cin >> x0 >> y00 >> x1 >> y11 >> x2 >> y2;

        mn = min<int>({y00, y11, y2});
        mx = max<int>({y00, y11, y2});

        v.push_back({mn, false});
        v.push_back({mx, true});
    }

    sort(v.begin(), v.end(), [](pair<int, bool> &a, pair<int, bool> &b) -> bool { return a.first == b.first ? !a.second : a.first < b.first; });

    for (auto &p : v)
    {
        if (p.second)
            --cnt;
        else
            ++cnt;

        res = max(cnt, res);
    }

    cout << res << "\n";

    return 0;
}