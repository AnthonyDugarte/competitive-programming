#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t n, b, x{0};
    cin >> n;

    for (int64_t i{0}; i < n; ++i)
    {
        cin >> b;

        cout << b + x << " ";
        x = max(b + x, x);
    }

    cout << "\n";

    return 0;
}
