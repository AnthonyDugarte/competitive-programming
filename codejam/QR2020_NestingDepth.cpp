#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int t, opened;
    cin >> t;

    string s;
    s.reserve(100);

    for (int j{1}; j <= t; ++j)
    {
        cout << "Case #" << j << ": ";
        opened = 0;

        cin >> s;

        for (int i{0}; i < s.size(); ++i)
        {
            while (opened < s[i] - '0')
            {
                cout << "(";
                ++opened;
            }

            while (opened > s[i] - '0')
            {
                cout << ")";
                --opened;
            }

            cout << s[i];
        }

        while (opened)
        {
            cout << ")";
            --opened;
        }

        cout << "\n";
    }

    return 0;
}