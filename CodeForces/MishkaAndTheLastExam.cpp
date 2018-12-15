#include <bits/stdc++.h>

using namespace std;
using type_t = long long;
using vt = vector<type_t>;

// Educational Codeforces Round 56 (Rated for Div. 2)

size_t n;
size_t  n_f;

bool solve(vt &a, const vt &b, size_t i)
{
    if(i == n_f)
        return true;
    
    a[i] = i != 0 ? a[i - 1] : 0;
    a[n - i - 1] = b[i] - a[i];
    
    
    if(i != 0 and a[n - i - 1] > a[n - i])
    {
        type_t diff{ a[n - i - 1] - a[n - i] };
        a[n - i - 1] -= diff;
        a[i] += diff;
    }

    while(a[n - i - 1] >= a[i])
    {
        if(solve(a, b, i + 1))
            return true;
        
        --a[n - i - 1];
        ++a[i];
    }
    
    a[n - i - 1] = 0;
    a[i] = 0;
    
    return false;
}

int main()
{
    cin >> n;
    n_f = n >> 1;

    vector<type_t> b(n >> 1), a(n, 0);

    for(type_t &val : b)
        cin >> val;

    solve(a, b, 0);

    for(type_t val : a)
        cout << val << " ";
    cout << "\n";

    return 0;
}