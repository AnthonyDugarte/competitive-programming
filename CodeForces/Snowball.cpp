// Codeforces Round #530 (Div. 2) 

#include <bits/stdc++.h>

using namespace std;

using pss_t = pair<int, int>;

int main() {
    int w, h;
    cin >> w >> h;

    vector<pss_t> stones(2);

    for (pss_t &s : stones)
        cin >> s.first >> s.second;

    while (h > 0) {
        w += h;
        if (h == stones[0].second) {
            w -= stones[0].first;
        } else if (h == stones[1].second) {
            w -= stones[1].first;
        }

        if (w < 0)
            w = 0;

        --h;
    }

    cout << w << "\n";
    
    return 0;
}
