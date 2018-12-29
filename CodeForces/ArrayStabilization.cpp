// Codeforces Round #529 (Div. 3) 

#include <bits/stdc++.h>

using namespace std;

int main()
{
    size_t n;
    cin >> n;
    vector<int> v(n);
    for(int &val : v)
        cin >> val;
    sort(v.begin(), v.end());

    if(v.size() == 2)
        cout << "0";
    else
    {
        if(v[1] - v[0] > v[v.size() - 1] - v[v.size() - 2])
            cout << v[v.size() - 1] - v[1];
        else cout << v[v.size() - 2] - v[0];
    }
    cout << endl;
    return 0;
}