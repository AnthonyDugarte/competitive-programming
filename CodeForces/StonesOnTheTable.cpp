# include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    size_t counter{};
    char prev;

    for(std::cin >> prev; --n; )
    {
        char c;
        std::cin >> c;

        if(c == prev)
            ++counter;

        prev = c;
    }

    std::cout << counter << "\n";
    return 0;
}
