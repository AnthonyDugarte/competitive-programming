#include <bits/stdc++.h>
using namespace std;

using type_t = int;
using graph_t = map<type_t, set<type_t>>; // node - neighbours

void DFS(const graph_t& graph, set<type_t> &visited_nodes, type_t root_node)
{
    if(visited_nodes.find(root_node) != visited_nodes.end())
    {
        cout << "already visited: " << root_node << endl;
        return; // visited;
    }
    
    visited_nodes.insert(root_node);
    cout << root_node << endl;

    for(auto child : graph.at(root_node))
        DFS(graph, visited_nodes, child);
}

void DFS(const graph_t& graph)
{
    set<type_t> visited_nodes;
    DFS(graph, visited_nodes, (*graph.begin()).first);
}

int main()
{
    size_t N;
    cin >> N;
    
    graph_t graph;
    for(size_t i{ 0 }; i < N; ++i)
    {
        type_t a, b;
        cin >> a >> b;

        graph[a].insert(b);
        graph[b].insert(a); // undirected graph
    }

    DFS(graph);

    return 0;
}