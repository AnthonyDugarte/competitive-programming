#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<unsigned long long> closed;
    unordered_set<unsigned long long> open;

    size_t n;
    cin >> n;

    while(--n != -1)
    {
        unsigned long long k;
        cin >> k;

        if(closed.find(k) != closed.end())
            continue;
        
        if(open.find(k) == open.end())
            open.insert(k);
        else
        {
            closed.insert(k);
            open.erase(k);
        }
    }

    cout << *open.begin() << endl;

    return 0;
}