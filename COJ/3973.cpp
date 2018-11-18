#include <bits/stdc++.h>
using namespace std;

string s;

map<string, size_t> memo;
map<string, set<size_t>> memo_starts;

void fill_memo()
{
    map<string, size_t> dirty_memo;
    map<string, set<size_t>> dirty_memo_starts;

    for(size_t i{ 0 }; i < s.size(); ++i)
    {
        ++dirty_memo[string{s[i]}];
        dirty_memo_starts[string{s[i]}].insert(i);
    }

    for(auto &a : dirty_memo)
        if(a.second > 1)
        {
            memo[a.first] = a.second;
            memo_starts[a.first] = dirty_memo_starts[a.first];
        }
}

size_t max_length(size_t a, size_t b)
{
    size_t counter{ 0 };

    while(a < s.size() and b < s.size() and s[a] == s[b])
    {
        ++a;
        ++b;
        ++counter;
    }

    return counter;
}

size_t clean_starts()
{
    size_t greater { 0 };
    
    for(auto & p : memo_starts)
    {
        vector<size_t> positions(p.second.begin(), p.second.end());
        
        for(size_t i{ 0 }; i < positions.size(); ++i)
            for(size_t j{ i + 1 }; j < positions.size(); ++j)
                greater = max<size_t>(greater, max_length(positions[i], positions[j]));
    }

    return greater;
}

int main()
{
    cin >> s;

    fill_memo();
    cout << clean_starts() << "\n";

    return 0;
}
