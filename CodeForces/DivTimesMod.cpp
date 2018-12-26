// Technocup 2019 - Elimination Round 4
#include <bits/stdc++.h>

using namespace std;

int main()
{
    size_t n, k;
    cin >> n >> k;

    size_t x { 1 };
    
    size_t x_c{ 0 };
    size_t k_i{ 1 };

    for(; ; ++x, ++k_i)
    {
        if(k_i == k)
        {
            k_i = 0;
            ++x_c;
            continue;
        }

        if(x_c * k_i == n)
            break;
    }

    std::cout << x << endl;
    return 0;
}