#include <bits/stdc++.h>
using namespace std;

int length_repeating_LCS(const string &s)
{
    const size_t s_size { s.size() };
    vector<vector<int>> reps = vector<vector<int>>(s_size + 1, vector<int>(s_size + 1));

    for(size_t i{ 0 }; i <= s_size; ++i)
    {
        for(size_t j{ 0 }; j <= s_size; ++j)
        {
            if(i == 0 or j == 0)
                reps[i][j] = 0;
            // repeated LCS: just need to check index
            else if(i != j and s[i - 1] == s[j - 1])
                reps[i][j] = reps[i - 1][j - 1] + 1;
            else reps[i][j] = max<int>(reps[i - 1][j], reps[i][j - 1]);
        }
    }

    return reps[s_size][s_size];
}

string str;
map<pair<size_t, size_t>, int> memo;
int length_repeating_LCS(size_t x = str.size(), size_t y = str.size())
{
    map<pair<size_t, size_t>, int>::iterator it{ memo.find({x, y}) };
    if(it != memo.end())
        return it->second;

    if(x == 0 or y == 0)
        return memo[{x, y}] = memo[{y, x}] = 0;

    if(x != y and str[x - 1] == str[y - 1])
        return memo[{x, y}] = length_repeating_LCS(x - 1, y - 1) + 1;
    
    return memo[{x, y}] = max<int>(length_repeating_LCS(x - 1, y), length_repeating_LCS(x, y - 1));
}

int main()
{
    cin >> str;
    cout << length_repeating_LCS() << "\n";

    return 0;
}