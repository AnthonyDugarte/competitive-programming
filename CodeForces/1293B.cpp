#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    long double s{0.0};

    for (long double i = n; i >= 1.0; i -= 1)
        s += 1.0L / i;

    cout << setprecision(10) << s << "\n";
    return 0;
}