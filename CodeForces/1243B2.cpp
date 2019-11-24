#include <bits/stdc++.h>

using namespace std;

int k, n, sol_i;
string s, t;
bool broken;
vector<pair<int, int>> sol(2 * 50);

int main()
{
    ios_base::sync_with_stdio(false);

    // s.reserve(50);
    // t.reserve(50);

    cin >> k;
    while (--k >= 0)
    {
        map<char, int> m;

        cin >> n;
        cin >> s >> t;

        for (char &c : s)
            m[c]++;
        for (char &c : t)
            m[c]++;

        broken = false;
        for (pair<const char, int> &p : m)
            if (p.second & 1)
            {
                broken = true;
                break;
            }

        if (broken)
        {
            cout << "NO"
                 << "\n";
            continue;
        }

        cout << "YES"
             << "\n";

        sol_i = 0;

        for (size_t i{0}; i < n - 1; ++i)
        {
            if (s[i] == t[i])
                continue;

            size_t si{s.find(t[i], i + 1)}, ti{t.find(s[i], i + 1)},
                so{s.find(s[i], i + 1)}, to{t.find(t[i], i + 1)};

            if (to != string::npos)
            {
                sol[sol_i] = {i, to};
                swap(s[i], t[to]);
            }
            else if (so != string::npos)
            {
                sol[sol_i] = {so, i};
                swap(s[so], t[i]);
            }
            else if (si != string::npos)
            {
                sol[sol_i++] = {si, i + 1};
                swap(s[si], t[i + 1]);

                sol[sol_i] = {i, i + 1};
                swap(s[i], t[i + 1]);
            }
            else
            {
                sol[sol_i++] = {i + 1, ti};
                swap(s[i + 1], t[ti]);

                sol[sol_i] = {i + 1, i};
                swap(s[i + 1], t[i]);
            }

            ++sol_i;
        }

        cout << sol_i << "\n";
        for (int i{0}; i < sol_i; ++i)
            cout << sol[i].first + 1 << " " << sol[i].second + 1 << "\n";
    }

    return 0;
}