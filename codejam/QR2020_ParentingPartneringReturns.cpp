#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int t, n, c, j;
    bool allright;
    pair<pair<int, int>, int> schedules[1000];
    string s;

    s.reserve(1000);

    cin >> t;
    for (int k{1}; k <= t; ++k)
    {
        c = j = -1;
        allright = true;

        cin >> n;
        s.resize(n);

        for (int i{0}; i < n; ++i)
        {
            schedules[i].second = i;
            cin >> schedules[i].first.first;
            cin >> schedules[i].first.second;
        }

        sort(schedules, schedules + n, [](pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b) {
            return a.first.first < b.first.first;
        });

        for (int i{0}; i < n; ++i)
            if (c == -1 || schedules[i].first.first >= schedules[c].first.second)
            {
                s[schedules[i].second] = 'C';
                c = i;
            }
            else if (j == -1 || schedules[i].first.first >= schedules[j].first.second)
            {
                s[schedules[i].second] = 'J';
                j = i;
            }
            else
            {
                allright = false;
                break;
            }

        cout << "Case #" << k << ": " << (allright ? s : "IMPOSSIBLE") << "\n";
    }

    return 0;
}