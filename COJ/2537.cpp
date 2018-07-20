# include <iostream>
# include <vector>
# include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    size_t T;
    std::cin >> T;

    std::vector<int> outs;

    for(++T; --T; )
    {
        size_t N;
        std::cin >> N;

        std::vector<short> cards(N);
        for(auto && c : cards)
            std::cin >> c;

        std::vector<short> playOrder(N);

        for(short n {}; n < N; ++n)
            playOrder[n] = n;

        int wins{};
        do
        {
            int plays{};

            for(int pos{}; pos < N; ++pos)
            {
                for(int k{}; k < N; ++k)
                    if(not (plays & (1 << ((cards[playOrder[pos]] + k) % N))))
                    {
                        plays += (1 << ((cards[playOrder[pos]] + k) % N));
                        break;
                    }

                if(plays & (1 << cards[0]))
                {
                    if(playOrder[pos] == 0)
                        ++wins;
                    break;
                }
            }
        }while(std::next_permutation(playOrder.begin(), playOrder.end()));

        outs.push_back(std::move(wins));
    }

    for(auto && o : outs)
        std::cout << o << "\n";

    return 0;
}
