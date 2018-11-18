#include <bits/stdc++.h>
using namespace std;

int main()
{
    size_t n, sum{ 0 }, count{ 0 }, it{ 0 };
    cin >> n;

    vector<int> coins(n);
    for(int &c : coins)
    {
        cin >> c;
        sum += c;
    }

    sort(coins.begin(), coins.end(), greater<int>());

    while(count <= sum)
    {
        count += coins[it];
        sum -= coins[it];
        ++it;
    }

    cout << it << "\n";

    return 0;
}