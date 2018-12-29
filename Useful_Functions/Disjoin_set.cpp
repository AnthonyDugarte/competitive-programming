#include <bits/stdc++.h>

using namespace std;
using type_t = unsigned long long;

type_t ds_find(vector<type_t> &parent, type_t u)
{
    if (u != parent[u])
        parent[u] = ds_find(parent, parent[u]); 
    return parent[u];
}

// Union by rank 
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

void initit_ds(vector<type_t> &parent, vector<type_t> &rank, type_t n)
{
    parent = vector<type_t>(n + 1);
    rank = vector<type_t>(n + 1);
    for(size_t i { 0 }; i <= n; ++i)
    {
        rank[i] = 0; 
        parent[i] = i; 
    }
}