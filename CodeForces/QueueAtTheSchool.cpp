// http://codeforces.com/problemset/problem/266/B

# include <iostream>
# include <cstdint>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int n, t;
    std::cin >> n >> t;

    uint64_t boys{}, one64{ 1 };

    for(int i { n - 1 }; i >= 0; --i)
    {
        char c;
        std::cin >> c;

        if(c == 'B')
            boys += (one64 << i);
    }

    for(++t; --t; )
    {
        uint64_t aux { boys };
        for(int i{ 0 }; i < n; ++i)
            if((boys & (one64 << i)) and i != 0 and !(boys & (one64 << (i - 1))))
            {
                aux &= ~(one64 << i);
                aux |= (one64 << (i - 1));
            }

        boys = aux;
    }


    for(int i{ n - 1 }; i >= 0; --i)
        std::cout << ((boys & (one64 << i)) ? "B" : "G");
    std::cout << "\n";

    return 0;
}
