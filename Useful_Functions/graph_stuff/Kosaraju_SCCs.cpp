#include<bits/stdc++.h>
using namespace std;

using type_t = size_t;
using graph_t = unordered_map<type_t, pair<set<type_t>, bool>>;

// save path into stack s
void DFS(graph_t& graph, type_t root_node, stack<type_t> &s)
{
    if(graph[root_node].second)
        return;
    graph[root_node].second = true;
    
    for(auto child : graph.at(root_node).first)
        DFS(graph, child, s);
    
    s.push(root_node);
}

// print nodes
void DFS(graph_t& graph, type_t root_node)
{
    if(graph[root_node].second)
        return;
    graph[root_node].second = true;

    cout << root_node << " ";

    for(auto child : graph.at(root_node).first)
        DFS(graph, child);
}

graph_t get_transpose(graph_t &graph)
{
    graph_t transposed;

    for(auto a : graph)
        for(auto b : a.second.first)
            transposed[b].first.insert(a.first);

    return move(transposed);
}

void Kosaraju_SCCs(graph_t &graph)
{
    for(auto & n : graph)
        n.second.second = false; // cleaning nodes
    
    stack<type_t> s;
    DFS(graph, graph.begin()->first, s); // saving path

    graph_t transposed_graph{ get_transpose(graph) };
    for(auto & n : transposed_graph)
        n.second.second = false; // cleaning nodes

    while(!s.empty())
    {
        type_t val{ s.top() };
        s.pop();

        // node not yet part of a component
        if(!transposed_graph[val].second)
        {
            // all children of val are parte of val component? wut
            DFS(transposed_graph, val);
            cout << "\n";
        }
    }
}

int main()
{
    graph_t graph;
    graph[1].first.insert(0);
    graph[0].first.insert(2);
    graph[2].first.insert(1);
    graph[0].first.insert(3);
    graph[3].first.insert(4);

    Kosaraju_SCCs(graph);
    
    return 0;
}