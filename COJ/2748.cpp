#include <bits/stdc++.h>
using namespace std;

int main()
{
    size_t n;
    cin >> n;

    int min_d{ 0 };

    while(--n != -1)
    {
        int a, b;
        cin >> a >> b;

        min_d = max<int>(min_d, a * a + b * b);
    }

    cout << min_d << "\n";

    return 0;
}