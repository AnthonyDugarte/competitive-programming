// Educational Codeforces Round 56 (Rated for Div. 2)
#include <bits/stdc++.h>

using namespace std;
using type_t = unsigned long long;

constexpr type_t M { 998244353ull };
using graph_t = unordered_map<int ,pair<type_t, unordered_set<type_t>>>;

type_t bfs(graph_t &g, type_t root)
{
    if(g.size() == 0 or g[root].first != -1)
        return 1;
    
    queue<type_t> nodes;
    nodes.push(root);
    g[root].first = 0;
    
    type_t even{ 0 }, odd{ 0 };

    while(!nodes.empty())
    {
        queue<type_t> new_lvl_nodes;

        while(!nodes.empty())
        {
            type_t n{ nodes.front() };
            int color = g[n].first;

            if(color == 1)
                ++even;
            else ++odd;

            type_t new_color = color == 1 ? 0 : 1;

            nodes.pop();
        
            for(auto &child : g[n].second)
            {
                if(g[child].first == -1)
                {
                    g[child].first = new_color;
                    new_lvl_nodes.push(child);
                }
                else if(g[child].first == color)
                    return 0; // cycle
            }
        }

        nodes = move(new_lvl_nodes);
    }

    type_t counterA{ 1 }, counterB{ 1 };

    while(--even != -1)
        (counterA <<= 1) %= ::M;
    while(--odd != -1)
        (counterB <<= 1) %= ::M;
    
    return (counterA + counterB) % M;
}


int main()
{
    type_t t;
    cin >> t;

    while(--t != -1)
    {
        graph_t g;

        type_t n, m;
        cin >> n >> m;

        for(type_t i { 0 }; i < m; ++i)
        {
            type_t a, b;
            cin >> a >> b;
            g[a].first = g[b].first = -1;

            g[a].second.insert(b);
            g[b].second.insert(a);
        }

        type_t res{ 1 };
        for(auto & it : g)
            (res *= bfs(g, it.first)) %= ::M;


        type_t sum{ 1 };
        n -= g.size();
        while(--n != -1)
            (sum *= 3) %= ::M;
        
        cout << ((sum *= res) %= ::M) << "\n";
    }

    return 0;
}