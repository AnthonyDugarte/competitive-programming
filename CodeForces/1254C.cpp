#include <bits/stdc++.h>

using namespace std;

int n;

vector<tuple<int, int, int>> v(static_cast<size_t>(1e5));

map<int, set<int>> m;

vector<int> sol(static_cast<size_t>(1e5));

int one[2]{-1, -1}, curr;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i{0}; i < n - 2; ++i)
    {
        cin >> get<0>(v[i]) >> get<1>(v[i]) >> get<2>(v[i]);

        m[get<0>(v[i])].insert(i);
        m[get<1>(v[i])].insert(i);
        m[get<2>(v[i])].insert(i);
    }

    for (pair<const int, set<int>> &p : m)
        if (p.second.size() == 1)
            (one[0] == -1 ? one[0] : one[1]) = p.first;

    curr = *m[one[0]].begin() == 0 ? one[1] : one[0];

    sol[0] = curr;

    tuple<int, int, int> &tp{v[*m[curr].begin()]};

    switch (m[get<0>(tp)].size())
    {
    case 2:
        sol[1] = get<0>(tp);
        break;

    case 3:
        sol[2] = get<0>(tp);
        break;
    }

    switch (m[get<1>(tp)].size())
    {
    case 2:
        sol[1] = get<1>(tp);
        break;

    case 3:
        sol[2] = get<1>(tp);
        break;
    }

    switch (m[get<2>(tp)].size())
    {
    case 2:
        sol[1] = get<2>(tp);
        break;

    case 3:
        sol[2] = get<2>(tp);
        break;
    }

    for (int i{3}; i < n; ++i)
    {
        set<int> &sl{m[sol[i - 3]]}, &s1{m[sol[i - 2]]}, &s2{m[sol[i - 1]]};

        int s_i{*sl.begin()};

        sl.erase(s_i);
        s1.erase(s_i);
        s2.erase(s_i);

        int s_i2{*s1.begin()};

        tuple<int, int, int> &tp{v[s_i2]};

        if (get<0>(tp) != sol[i - 1] && get<0>(tp) != sol[i - 2])
            sol[i] = get<0>(tp);
        else if (get<1>(tp) != sol[i - 1] && get<1>(tp) != sol[i - 2])
            sol[i] = get<1>(tp);
        else
            sol[i] = get<2>(tp);
    }

    for (int i{0}; i < n; ++i)
        cout << sol[i] << " ";
    cout << "\n";

    return 0;
}