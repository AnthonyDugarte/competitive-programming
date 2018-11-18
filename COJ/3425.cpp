#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    
    size_t t;
    cin >> t;
    
    while(--t != -1)
    {
        size_t n;
        cin >> n;
        string s;

        map<string, size_t> counts;

        while(--n != -1)
        {
            cin >> s >> s;
            ++counts[s];
        }
        size_t total_combs{ 0 };

        for(auto & it : counts)
            total_combs += total_combs * it.second + it.second;
        cout << total_combs << "\n";
    }

    return 0;
}