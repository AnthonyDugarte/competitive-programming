#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, aux, sum, x, y;
    set<int> x_set;
    set<int> y_set[100];

    cin >> t;

    for (int k{1}; k <= t; ++k)
    {
        sum = x = y = 0;

        cin >> n;

        for (int i{0}; i < n; ++i)
        {
            x_set.clear();

            for (int j{0}; j < n; ++j)
            {
                if (i == 0)
                    y_set[j].clear();

                cin >> aux;

                x_set.insert(aux);
                y_set[j].insert(aux);

                if (i == j)
                    sum += aux;
            }

            if (x_set.size() < n)
                ++x;
        }

        for (int i{0}; i < n; ++i)
            if (y_set[i].size() < n)
                ++y;

        cout << "Case #" << k << ": " << sum << " " << x << " " << y << "\n";
    }

    return 0;
}