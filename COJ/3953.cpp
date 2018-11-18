#include <bits/stdc++.h>
using namespace std;

vector<bool> taken_c(256, false);

size_t k;
string s;

bool is_it_beatiful(size_t pos = 0, size_t curr_k = 1)
{
    if(curr_k == k)
    {
        cout << "YES\n";
        while(pos < s.size())
            cout << s[pos++];
        cout << "\n";
        
        return true;
    }
    
    taken_c[s[pos]] = true;
    
    for(size_t i{pos + 1}; i < s.size(); ++i)
    {
        if(taken_c[s[i]])
            continue;
        if(is_it_beatiful(i, curr_k + 1))
            return true;
    }

    return taken_c[s[pos]] = false;
}

int main()
{
    cin >> k >> s;

    if(!is_it_beatiful())
        cout << "NO\n";
    
    return 0;
}