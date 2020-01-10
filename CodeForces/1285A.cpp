#include <bits/stdc++.h>

using namespace std;

int n{0}, l{0}, r{0};
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    s.resize(static_cast<size_t>(1e5));

    cin >> n >> s;

    for (int i{0}; i < n; ++i)
        ++(s[i] == 'L' ? l : r);

    cout << l + r + 1 << "\n";

    return 0;
}