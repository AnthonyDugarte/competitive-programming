#include <bits/stdc++.h>
using namespace std;

using type_t = uint64_t;
int n, m;

int main()
{
    cin >> n >> m;

    vector<type_t> v(n);
    for (type_t &i : v)
        cin >> i;

    sort(v.begin(), v.end());

    for (int i{1}; i < n; ++i)
        v[i] += v[i - 1];
    for (int i{m}; i < n; ++i)
        v[i] += v[i - m];

    for (int i{0}; i < n; ++i)
        cout << v[i] << " ";
    cout << "\n";

    return 0;
}
