#include <bits/stdc++.h>
using namespace std;

int main()
{
    size_t n;
    cin >> n;
    unordered_set<unsigned long> vals;
    
    while(--n != -1)
    {
        int c;
        cin >> c;

        while(--c != -1)
        {
            unsigned long val;
            cin >> val;
            vals.insert(val);
        }
    }

    cout << vals.size() << "\n";

    return 0;
}