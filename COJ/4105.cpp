#include<iostream>

int main()
{
    long N{ 0 };
    std::cin >> N;
    long k{ N };
    ((++N) *= k) >>= 1;
    
    while(std::cin >> k && (N -= k));
    
    std::cout << N;
    return 0;
}