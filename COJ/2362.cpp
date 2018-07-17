# include <iostream>
# include <vector>

inline size_t formulae(size_t n)
{
    return n * (n + 1) * 2;
}

int main()
{
    using namespace std;

    ios_base::sync_with_stdio(false);

    size_t tests, n;
    cin >> tests;

    vector<size_t> outs(tests);

    for(size_t i{}; i < tests; ++i)
    {
        cin >> n;
        outs[i] = 1 + formulae(n - 1);
    }

    for(auto && it : outs)
        cout << it << "\n";
}
