#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> memo{{0, 1}};

int factorial(int n)
{
    unordered_map<int, int>::iterator it{ memo.find(n) };
    
    if(it != memo.end())
        return it->second;
    return memo[n] = n * factorial(n- 1);
}

int main()
{
    size_t t;
    cin >> t;

    for(size_t i{ 1 }; i <= t; ++i)
    {
        size_t n;
        cin >> n;

        cout << "Case #" << i << ": " << factorial(n) << "\n";
    }
    return 0;
}