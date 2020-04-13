#include <bits/stdc++.h>
using namespace std;

int t;
string s[9];

int main()
{
    cin >> t;
    for (int i{0}; i < 9; ++i)
        s[i].reserve(9);

    while (--t != -1)
    {
        for (int i{0}; i < 9; ++i)
            cin >> s[i];

        s[0][0] = s[s[8][0] == s[0][0] ? 7 : 8][0];
        s[1][3] = s[0][3];
        s[2][6] = s[0][6];

        s[3][1] = s[0][1];
        s[4][4] = s[0][4];
        s[5][7] = s[0][7];

        s[6][2] = s[0][2];
        s[7][5] = s[0][5];
        s[8][8] = s[0][8];

        for (int i{0}; i < 9; ++i)
            cout
                << s[i] << "\n";
    }

    return 0;
}