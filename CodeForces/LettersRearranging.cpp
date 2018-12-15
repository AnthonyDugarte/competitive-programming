// Educational Codeforces Round 56 (Rated for Div. 2)

#include <bits/stdc++.h>

using namespace std;

int charc;

map<char, pair<size_t, size_t>> chars;

bool palyndrome(const string &s)
{
    char prevc = s[0];

    size_t l{ 0 }, r{ s.size() - 1 };

    while(r >= l)
    {
        if(prevc != s[l])
            charc = l;
        else if(prevc != s[r])
            charc = r;
        
        if(s[l] != s[r])
            return false;
        
        if(r == l)
            return true;
        
        chars[s[l]] = {l, r};
        
        ++l; --r;
    }

    return true;
}


int main()
{
    size_t t;
    cin >> t;

    while(--t != -1)
    {
        charc = -1;
        chars.clear();

        string s;
        cin >> s;
        
        if(!palyndrome(s))
            cout << s;
        else if(charc == -1)
            cout << -1;
        else if(chars.size() > 1)
        {
            swap(s[chars.begin()->second.first], s[next(chars.begin())->second.second]);
            cout << s;
        }
        else{
            swap(s[chars.begin()->second.first], s[s.size() / 2]);
            cout << s;
        }

        cout << "\n";
    }

    return 0;
}