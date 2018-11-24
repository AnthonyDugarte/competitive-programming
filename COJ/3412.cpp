#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    
    vector<int>classrooms(N);
    for(int &c : classrooms)
        cin >> c;
    
    int curr_n{ 0 }, prev_i{ -1 }, best{ 0 };

    for(int i{ -1 }; i < M; )
    {
        curr_n += classrooms[++i];

        while(curr_n > M)
            curr_n -= classrooms[++prev_i];
        
        best = max(curr_n, best);
        if(curr_n == M)
            break;
    }

    cout << best << "\n";

    return 0;
}