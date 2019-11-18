#include <bits/stdc++.h>
using namespace std;

using type_t = int64_t;

string s;
type_t n, score{0};

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> s >> n;

    s = s + s.substr(0, n - 1);
    for (type_t r{0}, l{0}, e{-1}; r < s.size(); ++r)
    {
        if (r >= n)
            ++l;

        if (s[r] == 'E')
            e = r;

        if (e >= l && r >= n - 1)
            score += e - l + 1;
    }

    cout << score << "\n";

    return 0;
}