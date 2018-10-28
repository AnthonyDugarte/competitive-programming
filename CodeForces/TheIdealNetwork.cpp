// Preclasificatorio Latinoamericano ACM-ICPC ULA 2018 (post contest)
// http://codeforces.com/group/1daWYZTt2e/contest/231528/standings/groupmates/true

# include <bits/stdc++.h>
using namespace std;

int main()
{
    size_t W;

    while(cin >> W and W != 0)
    {
        unordered_map<int, unordered_set<int>> graph; // node - edges

        int biggest_node { 0 };
        for(size_t i{ 0 }; i < W; ++i)
        {
            size_t N, M;
            cin >> N >> M;
            
            graph[N].insert(M);
            graph[M].insert(N);

            biggest_node = max<int>(max(N, M), biggest_node);
        }
        
        queue<int> current_nodes;
        current_nodes.push((*graph.begin()).first);
        
        vector<int> nodes_color(biggest_node + 1, -1);
        nodes_color[current_nodes.front()] = 0;
        
        bool is_it_broken { false };

        while(not current_nodes.empty())
        {
            queue<int> new_level_nodes;

            while(not current_nodes.empty())
            {
                int curr_node{ current_nodes.front() };
                current_nodes.pop();

                int curr_node_color{ nodes_color[curr_node] };

                for(int child_node : graph[curr_node] )
                {
                    // not visited
                    if(nodes_color[child_node] == -1)
                    {
                        nodes_color[child_node] = (curr_node_color == 0 ? 1 : 0);
                        new_level_nodes.push(child_node);
                    }
                    // visited: check if cicle
                    else if(nodes_color[child_node] == curr_node_color)
                    {
                        is_it_broken = true;
                        break;
                    }
                }

                if(is_it_broken)
                    break;
            }

            if(is_it_broken)
                break;

            current_nodes = move(new_level_nodes);
        }

        cout << (is_it_broken ? "no" : "yes") << endl;
    }
    
    return 0;
}