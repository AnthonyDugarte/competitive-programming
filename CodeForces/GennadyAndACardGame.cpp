// hello 2019
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, ss;
    cin >> s;

    for(size_t i { 0 }; i < 5; ++i)
    {
        cin >> ss;
        
        if(ss[0] == s[0] || ss[1] == s[1])
        {
            cout << "yes\n";
            return 0;
        }
    }

    cout << "no\n";
    return 0;
}