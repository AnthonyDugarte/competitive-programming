// http://coj.uci.cu/24h/problem.xhtml?pid=2763

#include <iostream>
#include <vector>
#include <queue>

void move(const std::vector<size_t> &arr, std::queue<std::pair<size_t, size_t>> mem)
{
    std::queue<std::pair<size_t, size_t>> new_mem;

    while(not mem.empty())
    {
        std::pair<size_t, size_t> e{ mem.front() };
        mem.pop();

        size_t middle{ (e.first + e.second) >> 1 };
        
        std::cout << arr[middle] << " ";

        if(middle != e.first)
        {
            new_mem.push({ e.first, middle - 1 });
            new_mem.push({ middle + 1, e.second });
        }
    }
    
    std::cout << "\n";

    if(not new_mem.empty())
        move(arr, new_mem);
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    size_t n;
    std::cin >> n;
    n = 1 << n;
    
    std::vector<size_t> arr(--n);
    for(auto & val : arr)
        std::cin >> val;
    
    std::queue<std::pair<size_t, size_t>> mem;
    mem.push({0, n});

    move(arr, mem);
    
    return 0;
}