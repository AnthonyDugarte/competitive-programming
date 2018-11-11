#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    long long x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;

    long long w, h;
    cin >> w >> h;

    if(x3 - w >= x1 or x2 - w >= x4)
        cout << (y2 - h >= y1 ? "Yes" : "No") << "\n"; 
    else if(y3 - h >= y1 or y2 - h >= y4)
        cout << (x2 - w >= x1 ? "Yes" : "No") << "\n"; 
    else cout << "No\n";
    
    return 0;
}