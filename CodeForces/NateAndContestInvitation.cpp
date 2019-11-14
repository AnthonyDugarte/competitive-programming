// https://codeforces.com/group/mOroqYfSFo/contest/241199/problem/C

#include <bits/stdc++.h>
using namespace std;

int n, m, k, res{0};
string a, b;

map<string, string> ppl;
map<string, int> invs;

string &find(string &x)
{
    string &src{ppl[x]};

    if (src == x)
        return x;

    return src = find(src); // haz que su padre sea el root ?
}

void join(string &x, string &y)
{
    ppl[find(x)] = find(y);
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;

    while (--m != -1)
    {
        cin >> a >> b;

        string &a_{ppl[a]}, &b_{ppl[b]};

        if (a_.empty())
            a_ = a;
        if (b_.empty())
            b_ = b;

        join(a, b);
    }

    vector<int> a_invs;

    for (auto &p : ppl)
        ++invs[find(p.second)];

    for (auto &p : invs)
        if (p.second)
            a_invs.push_back(p.second);

    sort(a_invs.begin(), a_invs.end(), std::greater<int>());

    for (int i{0}; i < a_invs.size() && k; ++i, --k)
        res += a_invs[i];

    cout << res + min(k, n - res) << endl;

    return 0;
}