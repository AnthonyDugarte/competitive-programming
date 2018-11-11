#include <bits/stdc++.h>

using namespace std;
using type_t = unsigned long long;

int main()
{
    size_t t;
    cin >> t;

    while(--t != -1)
    {
        type_t N, n;
        cin >> N;

        map<type_t, type_t> numbers; // number - reps

        while(--N != -1)
        {
            cin >> n;
            
            if(n == 0)
                continue;
            type_t count{ 1 };

            while(!(n & 1))
            {
                count <<= 1;
                n >>= 1;
            }
            
            numbers[n] += count;
        }

        for(auto k : numbers)
            if((k.second >>= 1) != 0)
                numbers[k.first << 1] += k.second;
        
        cout << numbers.rbegin()->first << "\n";
    }

    return 0;
}