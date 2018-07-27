# include <iostream>
# include <vector>
# include <set>
# include <algorithm>

std::vector<char> stages;

size_t best{ static_cast<size_t>(-1) }, n, k;

int weight(char c)
{
    return c - 'a' + 1;
}

void getBest(size_t pos, size_t current_k, size_t score, char prevChar)
{
    while(pos < n and current_k < k)
    {
        if(weight(stages[pos]) - weight(prevChar) <= 1)
        {
            getBest(pos + 1, current_k, score,  prevChar);
            getBest(pos + 1, current_k, score - weight(prevChar) + weight(stages[pos]), stages[pos]);
            return;
        }

        score += weight(stages[pos]);
        prevChar = stages[pos];
        ++current_k;
        ++pos;
    }

    if(current_k == k and score < best)
            best = score;
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    std::cin >> n >> k;

    std::set<char> t_stages;
    for(size_t i{}; i < n; ++i)
    {
        char c;
        std::cin >> c;

        t_stages.insert(c);
    }

    stages.assign(t_stages.begin(), t_stages.end());
    n = stages.size();

    getBest(1, 1, weight(stages[0]), stages.at(0));

    std::cout << static_cast<long>(best) << "\n";
    return 0;
}
