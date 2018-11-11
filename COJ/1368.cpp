#include <bits/stdc++.h>
using namespace std;

using point_t = pair<int, int>;

double distance(const point_t &pa, const point_t &pb)
{
    return sqrt(((pa.first - pb.first) * (pa.first - pb.first)) + ((pa.second - pb.second) * (pa.second - pb.second)));
}

using graph_t = vector<vector<double>>;

vector<bool> visited_nodes;
int n;
double res{ numeric_limits<double>::max() };

void dfs(const graph_t &graph, int nodes_count, int parent, double curr_res)
{
    if(visited_nodes[parent])
        return;
    if(nodes_count == n)
    {
        res = min(res, curr_res);
        return;
    }

    visited_nodes[parent] = true;
    ++nodes_count;

    for(size_t i{ 0 }; i < n; ++i)
    {
        if(i == parent)
            continue;
        dfs(graph, nodes_count, i, curr_res + graph[parent][i]);
    }

    visited_nodes[parent] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> ::n;
    
    graph_t graph(n, vector<double>(n, -1));
    ::visited_nodes = vector<bool>(n, false);

    vector<point_t> points(n);
    
    for(auto &p : points)
        cin >> p.first >> p.second;
    
    for(size_t i{ 0 }; i < n; ++i)
        for(size_t j{ i + 1 }; j < n; ++j)
            graph[i][j] = graph[j][i] = distance(points[i], points[j]);
    
    for(size_t i{ 0 }; i < n; ++i)
        dfs(graph, 1, i, 0.00);
    
    cout << fixed << setprecision(2) << res << "\n";
    
    return 0;
}




/* kruskall



using point_t = pair<int, int>;
using subset_t = pair<int, int>; // first -> parent, second -> rank
using weighted_edge = pair<point_t, double>; // first -> (a , b) second -> weight

double distance(const point_t &pa, const point_t &pb)
{
    return sqrt(((pa.first - pb.first) * (pa.first - pb.first)) + ((pa.second - pb.second) * (pa.second - pb.second)));
}

struct compare_f
{
    bool operator()(const weighted_edge &pa, const weighted_edge &pb)
    {
        return pa.second < pb.second;
    }
};

int find_dsj(vector<subset_t> &subsets, int i)
{
    // find root and make root as parent of i (path compression) 
    if (subsets[i].first != i)
        subsets[i].first = find_dsj(subsets, subsets[i].first); 
  
    return subsets[i].first; 
}

void union_dsj(vector<subset_t> &subsets, int x, int y) 
{
    int xroot = find_dsj(subsets, x); 
    int yroot = find_dsj(subsets, y); 
  
    // Attach smaller rank tree under root of high rank tree 
    // (union by Rank)
    if (subsets[xroot].second < subsets[yroot].second) 
        subsets[xroot].first = yroot; 
    else if (subsets[xroot].second > subsets[yroot].second) 
        subsets[yroot].first = xroot; 
  
    // If ranks are same, then make one as root and increment 
    // its rank by one 
    else
    {
        subsets[yroot].first = xroot; 
        ++subsets[xroot].second; 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    size_t n;
    cin >> n;
    
    vector<point_t> points(n);
    vector<subset_t> subset(n);
    vector<int> connections(n, 0);
    
    for(auto &p : points)
        cin >> p.first >> p.second;
    
    vector<weighted_edge> distance_heap;
    
    for(size_t i{ 0 }; i < n; ++i)
    {
        subset[i].first = i; // n subsets of nodes
        subset[i].second = 0;
        
        for(size_t j{ i + 1 }; j < n; ++j)
            distance_heap.push_back({{i, j}, distance(points[i], points[j])});
    }

    sort(distance_heap.begin(), distance_heap.end(), compare_f());
    
    float res = 0;
    
    for(size_t e{ 0 }, i{ 0 }; e < n - 1; ++i)
    {
        int a_root{ find_dsj(subset, distance_heap[i].first.first) };
        int y_root{ find_dsj(subset, distance_heap[i].first.second) };

        if(a_root != y_root) // not cycle
            // and connections[distance_heap[i].first.first] < 2 and connections[distance_heap[i].first.second] < 2)
        {
            ++e;
            res = res + distance_heap[i].second;
            union_dsj(subset, a_root, y_root);
            ++connections[distance_heap[i].first.first];
            ++connections[distance_heap[i].first.second];
        }
    }

    cout << fixed << setprecision(2) << res << "\n";

    return 0;
}*/