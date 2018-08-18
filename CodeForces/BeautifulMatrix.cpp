#include <iostream>

int main()
{
    auto abs = [](int n)->int{ return n < 0 ? -n : n; };

    for(int y{}; y < 5; ++y)
        for(int x{}; x < 5; ++x)
        {
            int n;
            std::cin >> n;
            if(n == 1)
            {
                std::cout << abs(x - 2) + abs(y - 2) << "\n";
                return 0;
            }
        }

    std::cout << 0 << "\n"; // ._.
    return 0;
}
