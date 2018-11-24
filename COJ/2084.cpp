#include<bits/stdc++.h>

using namespace std;
using bvv = vector<vector<bool>>;

size_t solve(set<pair<size_t, size_t>> &lands, const pair<size_t, size_t> &pos)
{
    size_t counter{ 0 };
    set<pair<size_t, size_t>>::iterator it{ lands.find(pos) };

    if(it == lands.end())
        return counter;
    
    lands.erase(it);

    counter += solve(lands, {pos.first + 1, pos.second});
    counter += solve(lands, {pos.first - 1, pos.second});
    counter += solve(lands, {pos.first, pos.second + 1});
    counter += solve(lands, {pos.first, pos.second - 1});
    
    counter += solve(lands, {pos.first + 1, pos.second + 1});
    counter += solve(lands, {pos.first - 1, pos.second - 1});
    counter += solve(lands, {pos.first - 1, pos.second + 1});
    counter += solve(lands, {pos.first + 1, pos.second - 1});

    return ++counter;
}


int main()
{
    size_t n;
    while(cin >> n and n != 0)
    {
        set<pair<size_t, size_t>> lands;

        for(size_t x{ 0 }; x < n; ++x)
        {
            getchar();
            for(size_t y{ 0 }; y < n; ++y)
            {
                char c = getchar();

                if(c == 'l')
                    lands.insert({x, y});
            }
        }
        
        size_t smallest{ numeric_limits<size_t>::max() };
        size_t largest{ numeric_limits<size_t>::min() };
        size_t islands{ 0 };

        while(!lands.empty())
        {
            size_t counter{ solve(lands, *lands.begin()) };

            ++islands;
            smallest = min(counter, smallest);
            largest = max(counter, largest);
        }


        if(islands == 0)
            cout << "0 0 0\n";
        else cout << islands << " " << smallest << " " << largest << "\n";
    }


    return 0;
}