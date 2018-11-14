#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if(n < 2)    
        cout << "WRONG ANSWER";
    else if(n > 3)
        cout << "RUNTIME ERROR";
    else cout << "ACCEPTED";
    
    cout << endl;

    return 0;
}