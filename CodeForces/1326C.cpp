#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    uint64_t n, k;
    cin >> n >> k;

    uint64_t t{1}, acc{0}, aux{0};

    for(int i{0}; i < n; ++i) {
        cin >> aux;

        if(aux > n - k) {
            if(acc)
                (t *= acc ) %= 998244353ul;
            acc = 1;
        } else if(acc)
            ++acc;
    }

    cout << ((n * (n + 1)) >> 1) - (((n - k) * ((n - k) + 1)) >> 1) << " " << t << "\n";
    
    return 0;
}