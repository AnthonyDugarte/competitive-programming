#include <iostream>

int main()
{
    // 5b + 2b^2
    // b * (5 + 2b)

    size_t b;
    std::cin >> b;

    std::cout << b * (5 + (b << 1)) << std::endl;

    return 0;
}