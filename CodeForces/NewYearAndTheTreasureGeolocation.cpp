// Good Bye 2018
#include <bits/stdc++.h>

using namespace std;
using point_t = pair<int, int>;

int main()
{
    size_t n;
    cin >> n;

    vector<point_t> obelisks(n), clues(n);

    for(point_t &p : obelisks)
        cin >> p.first >> p.second;
    for(point_t &p : clues)
        cin >> p.first >> p.second;

    point_t treasure;
    map<point_t, size_t> finds;

    for(point_t &ob : obelisks)
        for(point_t &cl : clues)
        {
            point_t p{ ob.first + cl.first, ob.second + cl.second };
            size_t &c{++finds[p]};

            if(c == n)
            {
                cout << p.first << " " << p.second << endl;
                return 0;
            }
        }

    return 0;
}