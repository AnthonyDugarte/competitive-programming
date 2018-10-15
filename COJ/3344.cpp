// http://coj.uci.cu/24h/problem.xhtml?pid=3344

#include <iostream>
#include <vector>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<int> vals(15);
    std::stack<int> islands;

    while(--n != -1)
    {
        size_t idx;
        std::cin >> idx;
        
        size_t total_islands{ 0 };

        for(auto &val : vals)
            std::cin >> val;
        
        for(size_t i{ 0 }; i < 14; ++i)
            if(vals[i] < vals[i + 1])
                ++total_islands;
        
        std::cout << idx << " " << total_islands << "\n";
    }
    
    return 0;
}