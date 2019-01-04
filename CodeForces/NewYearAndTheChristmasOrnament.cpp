// Good Bye 2018
#include <bits/stdc++.h>

using namespace std;

int main()
{
    size_t y, b, r;
    cin >> y >> b >> r;

    if(r > b)
        r = b + 1;
    else if(r == b)
        --b;
    else if(r < b)
        b = r - 1;
    
    if(b > y)
    {
        b = y + 1;
        r = b + 1;
    }
    else if(b == y)
        --y;
    else if(b < y)
        y = b - 1;
    
    cout << y + b + r << endl;
    return 0;
}