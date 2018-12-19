// Codeforces Round #527
#include <bits/stdc++.h>

using namespace std;

int main()
{
    size_t n;
    cin >> n;

    vector<int> skills(n);
    
    for(int &s : skills)
        cin >> s;
    sort(skills.begin(), skills.end());

    size_t count{ 0 };

    for(size_t i{ 0 }; i < n; i += 2)
        count += skills[i + 1] - skills[i];
    
    cout << count << "\n";
    return 0;
}