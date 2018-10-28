// Preclasificatorio Latinoamericano ACM-ICPC ULA 2018
// http://codeforces.com/group/1daWYZTt2e/contest/231528/standings/groupmates/true

# include <bits/stdc++.h>

using namespace std;

int main()
{	
    int A, B, C;

    cin >> A >> B >> C;

    while(A != 0 and B !=0 and C != 0)
    {
        int minE = max(max(A, B), C);
        int best_i = numeric_limits<int>::max();
        int best_extra = numeric_limits<int>::max();
        
        for(size_t i { 2 }; i <= minE; ++i)
        {
            vector<int> poss_best(3);
            poss_best[0] = A % i;
            poss_best[1] = B % i;
            poss_best[2] = C % i;
            
            int extra = 0;
            
            for(auto p : poss_best)
            {
                    if(p == 0)
                        continue;
                        
                    extra += i - p;
            }
            
            if(extra <= best_extra)
            {
                best_extra = extra;
                best_i = i;
            }
        }
            
        cout << best_i << " " << best_extra << endl;
        cin >> A >> B >> C;
    }
    
    

    return 0;
}