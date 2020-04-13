#include <bits/stdc++.h>
using namespace std;

int t, s[int(1e5) << 1], n, us[int(1e5) << 1];
map<int, int> skills;

int main()
{
    cin >> t;
    while (--t != -1)
    {
        skills.clear();

        cin >> n;
        for (int i{0}; i < n; ++i)
        {
            cin >> s[i];
            if (++skills[s[i]] == 1)
                us[skills.size() - 1] = s[i];
        }

        sort(us, us + skills.size(), [](const int &a, const int &b) {
            return skills[a] > skills[b];
        });

        if (skills[us[0]] > skills.size())
            cout << skills.size();
        else if (skills[us[0]] == skills.size())
            cout << skills.size() - 1;
        else if (skills[us[0]] < skills.size())
            cout << skills[us[0]];
        cout << "\n";
    }

    return 0;
}