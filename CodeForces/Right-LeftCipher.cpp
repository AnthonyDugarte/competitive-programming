// Technocup 2019 - Elimination Round 4
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, res;

    cin >> s;

    size_t l{ 0 }, r{ s.size() - 1 };
    bool left{ s.size() & 1 };

    for(size_t i{ 0 }; i < s.size(); ++i)
    {
        res.insert(0, { s[left ? l : r] });
        if(left)
            ++l;
        else --r;

        left ^= true;   
    }

    cout << res << endl;

    return 0;
}