#include <bits/stdc++.h>
using namespace std;

map<size_t, size_t> memo{ {1, 0} };

size_t get_val(size_t n)
{
    map<size_t, size_t>::iterator it{ memo.find(n) };
    if(it != memo.end())
        return it->second;
    
    return memo[n] = n - 1 + get_val(n - 1);
}

int main()
{
    size_t t;
    cin >> t;

    while(--t != -1)
    {
        size_t N;
        cin >> N;

        size_t res{ N };
        map<map<char, size_t>, size_t> words;

        getchar();

        while(--N != -1)
        {
            char c{'0'};
            map<char, size_t> letters;
            while(c != '\n')
            {
                c = getchar();
                ++letters[c];
            }
            ++words[move(letters)];
        }

        for(auto &l : words)
            res += get_val(l.second) << 1;
        printf("%lu\n", res);
    }

    return 0;
}