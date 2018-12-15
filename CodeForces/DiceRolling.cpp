// Educational Codeforces Round 56 (Rated for Div. 2)
# include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    size_t t;
    cin >> t;

    while(--t != - 1)
    {
        size_t x;
        cin >> x;

        size_t face{ 7 }, rolls{ 0 };

        while(x != 0)
        {
            rolls += x / face;
            x %= face;

            if(x == 1)
            {
                x += face;
                --rolls;
            }
            
            --face;
        }

        cout << rolls << "\n";
    }

    return 0;
}