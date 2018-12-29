// Codeforces Round #529 (Div. 3) 
#include <bits/stdc++.h>

using namespace std;

using type_t = unsigned long long;
using p_t = pair<type_t, type_t>;

type_t ds_find(vector<type_t> &parent, type_t u)
{
    if (u != parent[u])
        parent[u] = ds_find(parent, parent[u]); 
    return parent[u];
}

void ds_union(vector<type_t> &parent, vector<type_t> &rnk, type_t x, type_t y) 
{
    x = ds_find(parent, x), y = ds_find(parent, y);

    if (rnk[x] > rnk[y]) 
        parent[y] = x; 
    else
        parent[x] = y; 

    if (rnk[x] == rnk[y]) 
        ++rnk[y];
}

int main()
{
    type_t n, m;
    cin >> n >> m;

    type_t coins[n];
    cin >> coins[0];
    
    type_t min_coin{ coins[0] }, min_pos{ 0 };
    for(size_t i{ 1 }; i < n; ++i)
    {
        cin >> coins[i];

        if(min_coin > coins[i])
        {
            min_coin = coins[i];
            min_pos = i;
        }
    }
    
    vector<pair<type_t, p_t>> edges;
    for(type_t i{ 0 }; i < n; ++i)
    {
        if(i == min_pos)
            continue;
        edges.push_back({coins[i] + min_coin, {i, min_pos}});
    }

    for(type_t i{ 0 }; i < m; ++i)
    {
        type_t x, y, m;
        cin >> x >> y >> m;
        if(coins[x - 1] + coins[y - 1] > m)
            edges.push_back({m, {x - 1, y - 1}});
    }

    sort(edges.begin(), edges.end(), [](const pair<type_t, p_t> &a, const pair<type_t, p_t> &b){
        return a.first < b.first;
    });


    vector<type_t> dis_set(n + 1);
    vector<type_t> rnk(n + 1);
    for(size_t i { 0 }; i <= n; ++i)
    {
        rnk[i] = 0; 
        dis_set[i] = i; 
    }

    type_t t_coins{ 0 };
    for(pair<type_t, p_t> &it : edges)
    {
        type_t a { ds_find(dis_set, it.second.first) }; 
        type_t b { ds_find(dis_set, it.second.second) }; 
        
        if (a != b)
        {
            t_coins += it.first; 
            ds_union(dis_set, rnk, a, b); 
        }
    }

    cout << t_coins << endl;

    return 0;
}