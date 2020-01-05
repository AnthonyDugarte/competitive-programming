#include <bits/stdc++.h>
using namespace std;

int64_t n, k, tot{0};
set<string> ss;
string s;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    s.resize(k);

    if(n < 3) {
        cout << tot << "\n";
        return 0;
    }

    for(int i{0}; i < n; ++i) {
        cin >> s;
        ss.insert(s);
    }

    for(set<string>::iterator a{ss.begin()}; a != ss.end(); ++a) {
        const string & as{*a};

        for(set<string>::iterator b{next(a)}; b != ss.end(); ++b) {
            const string & bs{*b};

            for(int i{0}; i < k; ++i) {
                if(as[i] == bs[i])
                    s[i] = as[i];
                else {
                    if((as[i] == 'S' && bs[i] == 'T') || (as[i] == 'T' && bs[i] == 'S'))
                        s[i] = 'E';
                    else if((as[i] == 'S' && bs[i] == 'E') || (as[i] == 'E' && bs[i] == 'S'))
                        s[i] = 'T';
                    else
                        s[i] = 'S';
                }
            }

            if(ss.find(s) != ss.end())
                ++tot;
        }
    }

    cout << tot / 3 << "\n";

    return 0;
}