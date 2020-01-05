#include <bits/stdc++.h>

using std::cin;
using std::cout;
constexpr char endl = '\n';

int64_t n, m, q, y;
std::string s[20], t[20];

int main(){
     std::ios_base::sync_with_stdio(false);

     cin >> n >> m;
     for(int i{0}; i < n; ++i)
          cin >> s[i];
     for(int i{0}; i < m; ++i)
          cin >> t[i];
     cin >> q;

     while(--q != -1) {
          cin >> y;
          cout << s[(y - 1) % n] << t[(y - 1) % m] << endl;
     }
     
     return 0;
}