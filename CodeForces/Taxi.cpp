#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);

    size_t n, aux, res{};
    std::cin >> n;

    std::vector<size_t> groups(4, 0);

    for(++n; --n; )
    {
        std::cin >> aux;
        if(aux == 4)
            ++res;
        else ++groups[aux];
    }

    res += groups[3];
    if(groups[3] >= groups[1])
        groups[1] = 0;
    else groups[1] -= groups[3];


    groups[2] += groups[1] >> 1;
    groups[1] -= (groups[1] >> 1) << 1;

    res += groups[2] >> 1;
    if(groups[2] % 2 != 0)
    {
        if(groups[1] > 0)
            --groups[1];
        ++res;
    }

    res += groups[1];

    std::cout << res << "\n";
    return 0;
}
