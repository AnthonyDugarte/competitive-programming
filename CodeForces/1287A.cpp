#include <bits/stdc++.h>

using namespace std;

int64_t t, n, c, m;
string s;
bool angry;

int main() {
    s.reserve(100);
    ios_base::sync_with_stdio(false);
    cin >> t;

    while(--t != -1) {
        cin >> n >> s;

        c = m = 0;
        angry = false;

        for(char & cc : s) {
            if(cc == 'P' && angry)
                ++c;
            else if(cc == 'A') {
                angry = true;
                m = max(m, c);
                c = 0;
            }
        }

        

        cout << max(m, c) << "\n";
    } 

    return 0;
}