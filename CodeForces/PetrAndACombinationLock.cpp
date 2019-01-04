// hello 2019
#include <bits/stdc++.h>

using namespace std;
size_t n;
vector<int> degrees;
int counter{ 0 };

bool solve(size_t i)
{
    if(i == n)
        return counter % 360 == 0;

    counter += degrees[i];
    if(solve(i + 1))
        return true;
    
    counter -= degrees[i] << 1;
    if(solve(i + 1))
        return true;
    
    counter += degrees[i];
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    degrees = vector<int>(n);

    for(int &i : degrees)
        cin >> i;
    
    if(solve(0))
        cout << "yes\n";
    else cout << "no\n";
    
    return 0;
}