#include <bits/stdc++.h>

using namespace std;

size_t m;
vector<pair<vector<int>, int>> words;
vector<bool> visited;

size_t solve(size_t curr_score, size_t curr_best, size_t curr_i)
{
    for(size_t i{ 0 }; i < m; ++i)
    {
        if(curr_i != -1 and (visited[i] or words[i].first[0] != words[curr_i].first[1]))
            continue;
        visited[i] = true;

        size_t temp_score = curr_score + words[i].second;
        curr_best = solve(temp_score, max(temp_score, curr_best), i);

        visited[i] = false;
    }

    return curr_best;
}
 
int main()
{
    iostream::sync_with_stdio(false);
    
    size_t t;
    cin >> t;

    while(--t != -1)
    {
        cin >> m;
        // just first and last letters are going to be saved

        map<vector<int>, int> saved_words;

        for(size_t i{ 0 }; i < m; ++i)
        {
            string s;
            cin >> s;

            vector<int> curr_s{ *s.begin(), *s.rbegin() };

            map<vector<int>, int>::iterator it{ saved_words.find(curr_s) };

            if(it != saved_words.end())
                words[it->second].second += s.size();
            else
            {
                words.push_back({curr_s, s.size()});

                if(curr_s[0] == curr_s[1])
                    saved_words[move(curr_s)] = words.size() - 1;
            }
        }

        m = words.size();

        visited = vector<bool>(m, false);
        cout << solve(0, 0, -1) << "\n";

        words.clear();
    }

    return 0;
}