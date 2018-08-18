# include <iostream>

int main()
{
    size_t n, steps{};
    std::cin >> n;
    bool got_a_left = false;

    auto op = [&](size_t x)
    {
        got_a_left = false;
        if(n >= x)
        {
            if(n % x != 0)
                got_a_left = true;
            steps += n / x;
            n %= x;
        }
    };

    for (size_t x = 5; x > 0; --x)
        op(x);

    std::cout << steps + (got_a_left ? 1 : 0) << "\n";

    return 0;
}
