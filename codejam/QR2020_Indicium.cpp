#include <bits/stdc++.h>

using namespace std;

int t, n, k;
int arr[50][50], i_items[50], j_items[50];

// Naive
bool p(int i = 0, int j = 0, int acc = 0)
{
    if (i == n)
        return acc == k;

    if (j == 0)
        i_items[i] = 0;
    if (i == 0)
        j_items[j] = 0;

    for (int l{0}; l < n; ++l)
    {
        if (!((i_items[i] & (1 << l)) || (j_items[j] & (1 << l))))
        {
            arr[i][j] = l + 1;
            i_items[i] |= 1 << l;
            j_items[j] |= 1 << l;

            if (p(
                    j == n - 1 ? i + 1 : i,
                    j == n - 1 ? 0 : j + 1,
                    acc + (i == j ? l + 1 : 0)))
                return true;

            i_items[i] &= ~(1 << l);
            j_items[j] &= ~(1 << l);
            arr[i][j] = 0;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> t;

    for (int l{1}; l <= t; ++l)
    {
        cin >> n >> k;

        cout << "Case #" << l << ": ";

        if (!p())
            cout << "IMPOSSIBLE\n";
        else
        {
            cout << "POSSIBLE\n";

            for (int i{0}; i < n; ++i)
            {
                for (int j{0}; j < n; ++j)
                    cout << arr[i][j] << " ";
                cout << "\n";
            }
        }
    }

    return 0;
}