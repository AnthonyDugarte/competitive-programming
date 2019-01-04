// hello 2019
#include <bits/stdc++.h>

using namespace std;
size_t n;

using s_t = string;
using vs_t = vector<s_t>;
using vi_t = vector<int>;
using pii_t = pair<int, int>;
using vp_t = vector<pii_t>;

constexpr size_t MAX = 100000;

vs_t vs;
vi_t complete_tags;
map<int, set<int>> opening;
map<int, set<int>> closing;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;

    vs = vs_t(n);
    
    for(size_t i{ 0 }; i < n; ++i)
    {
        cin >> vs[i];
        
        int l{ 0 }, r{ 0 }, missing_l{ 0 }, missing_r{ 0 };

        for(char &c : vs[i])
        {
            if(c == '(')
                ++l;
            else if(c == ')')
            {
                if(l)
                    --l;
                else ++missing_l;
            }
        }
        missing_r = l;
        
        if(missing_l != 0 and missing_r != 0)
            continue;
        if(missing_l)
            opening[missing_l].insert(i);
        else if(missing_r)  
            closing[missing_r].insert(i);
        else complete_tags.push_back(i);
    } 
    
    size_t res{ 0 };
    res += (complete_tags.size() - (complete_tags.size() & 1 ? 1 : 0)) >> 1;

    for(auto &p : opening)
        res += min(p.second.size(), closing[p.first].size());
    
    cout << res << "\n";
    return 0;
}