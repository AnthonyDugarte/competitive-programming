#include <bits/stdc++.h>

using namespace std;

double my_c{ acos(0.0) * 2.0 - 2.0 };

// side = sin45 * (r * 2.0)
// res = my_pi * r * r - side * side;
// if we simplify, we get: r * r * (pi - 2.0)

int main()
{
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(2);
    size_t t;
    cin >> t;

    while(--t != -1)
    {
        double r;
        cin >> r;

        cout << r * r * my_c << "\n";
    }
    return 0;
}