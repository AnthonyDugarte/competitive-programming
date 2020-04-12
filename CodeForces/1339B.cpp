#include <bits/stdc++.h>

using namespace std;

int t, n, arr[(int)(1e5)];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> t;
    while (--t != -1)
    {
        cin >> n;
        for (int i{0}; i < n; ++i)
            cin >> arr[i];
        sort(arr, arr + n, less<int>());

        for (int i{1}, r{n >> 1}, s{(n & 1) ? 1 : -1}; i <= n; ++i)
        {
            cout << arr[r] << " ";
            r += i * s;
            s *= -1;
        }
        cout << "\n";
    }

    return 0;
}
