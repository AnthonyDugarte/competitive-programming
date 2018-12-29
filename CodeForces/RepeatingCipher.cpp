// Codeforces Round #529 (Div. 3) 
#include <bits/stdc++.h>

using namespace std;

int main()
{
    size_t n;
    cin >> n;
    string s;
    cin >> s;

    for(size_t i{ 0 }, j{ 2 }; i < n; i += j, ++j)
        cout << s[i];
    cout << endl;

    return 0;
}