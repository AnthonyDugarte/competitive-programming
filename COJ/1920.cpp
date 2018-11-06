#include <bits/stdc++.h>
using namespace std;

using graph_t = unordered_map<int, unordered_map<int, int>>; // [node][arc] -> reps

unordered_map<int, unordered_map<int, int>> paths; // from key I can acces children nodes

// bool to update parent - current
bool DFS(graph_t &graph, unordered_set<int> &visited_nodes, int parent, int current, int target)
{
    if(visited_nodes.find(current) != visited_nodes.end())
        return false;
    
    visited_nodes.insert(current);

    if(current == target)
    {
        ++graph[parent][current];
        ++graph[current][parent];
        return true;
    }

    unordered_map<int, int>::iterator path_search { paths[current].find(target) };
    if(path_search != paths[current].end())
    {
        ++graph[parent][current];
        ++graph[current][parent];
        return DFS(graph, visited_nodes, current, (*path_search).second, target);
    }

    for(auto child : graph[current])
        if(DFS(graph, visited_nodes, current, child.first, target))
        {
            paths[current][target] = child.first;
            ++graph[parent][current];
            ++graph[current][parent];
            return true;
        }
    
    visited_nodes.erase(current);
    return false;
}

/*
void BFS(graph_t &graph, int source, int target)
{
           //visited - parent
    unordered_map<int, int> visited_nodes;
    visited_nodes[source] = -1; // source is visited, -1 for some sort of root
    
    queue<int> curr_nodes;
    curr_nodes.push(source);

    bool target_found{ false };

    while(//not curr_nodes.empty() and
        not target_found)
    {
        int curr_node{ curr_nodes.front() };
        curr_nodes.pop();

        for(auto &child : graph[curr_node])
        {
            if(visited_nodes.find(child.first) != visited_nodes.end())
                continue;
            
            visited_nodes[child.first] = curr_node;

            if(child.first == target)
            {
                target_found = true;
                break;
            }
            
            curr_nodes.push(child.first);
        }
    }

    // path from source - to target
    while(visited_nodes[target] != -1)
    {
        ++graph[target][visited_nodes[target]];
        ++graph[visited_nodes[target]][target];

        target = visited_nodes[target];
    }
}*/


/*// source: a b, target: a, b
double EuclideanDistance(int x1, int y1, int x2, int y2) // heuristic
{
    return static_cast<double>(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void A_start(graph_t &graph, int source, int target)
{
    vector<int> closedSet;
    vector<int> openSet;
    openSet.push_back(source);

    // openSet.insert(source);

    unordered_map<int, double> gScore;
    gScore[source] = 0.0;
    
    unordered_map<int, double> fScore;
    fScore[source] = EuclideanDistance(source, target, target, source);

    unordered_map<int, int> path;

    while(not openSet.empty())
    {
        int curr_node = *openSet.begin();
        int curr_f = fScore[curr_node];

        for(int k : openSet)
            if(fScore[k] < curr_f)
            {
                curr_f = fScore[k];
                curr_node = k;
            }
        
        if(curr_node == target)
        {
            while(target != source)
            {
                ++graph[target][path[target]];
                ++graph[path[target]][target];

                target = path[target];
            }
            return;
        }

        vector<int>::iterator position{ find(openSet.begin(), openSet.end(), curr_node) };
        openSet.erase(position);
        closedSet.push_back(curr_node);
        
        // approach with set
        // openSet.erase(curr_node);
        // closedSet.insert(curr_node);

        for(auto &child : graph[curr_node])
        {
            position = std::find(closedSet.begin(), closedSet.end(), child.first);

            if(position != closedSet.end())
            // if(closedSet.find(child.first) != closedSet.end())
                continue;
            
            double temp_gScore{ gScore.at(curr_node) + EuclideanDistance(curr_node, child.first, child.first, curr_node) };

            position = std::find(openSet.begin(), openSet.end(), child.first);

            if(position == openSet.end())
            // if(openSet.find(child.first) == openSet.end())
                openSet.push_back(child.first);
                //openSet.insert(child.first);
            else if (temp_gScore >= gScore.at(child.first))
                continue;
            
            path[child.first] = curr_node;
            gScore[child.first] = temp_gScore;
            fScore[child.first] = gScore[child.first] + EuclideanDistance(child.first, target, target, child.first);
        }
    }
}
*/

int main()
{
    ios_base::sync_with_stdio(false);

    size_t N, M;
    cin >> N >> M;

    graph_t graph;

    for(size_t i { 0 }; i < N - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        
        graph[a][b] = graph[b][a] = 0;
    }

    // constexpr char Planting = 'P';
    constexpr char Query = 'Q';

    for(size_t i{ 0 }; i < M; ++i)
    {
        char action;
        int a, b;
        
        cin >> action >> a >> b;
        
        if(action == Query)
            cout << graph[a][b] << "\n";
        else
        {
            // BFS(graph, a, b);
            
            // A_start(graph, a, b);

            unordered_set<int> visited_nodes;
            visited_nodes.insert(a);
        
            for(auto child : graph[a])
                if(DFS(graph, visited_nodes, a, child.first, b))
                    break;
        }
    }

    return 0;
}