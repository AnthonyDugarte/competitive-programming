// Codeforces Round #529 (Div. 3) 
#include <bits/stdc++.h>

using namespace std;

int main()
{
    size_t n, k, maxk{ 0 };
    cin >> n >> k;

    int auxn{ n };
    vector<int> powers;
    
    while(auxn)
    {
        int y = log2(auxn);
        int b = 1 << y;
        powers.push_back(b);
        auxn -= b;
    }
    
    if(powers.size() > k or k > n)
        std::cout << "NO";
    else
    {
        
        k -= powers.size();
        
        for(size_t i{ 0 }; i < powers.size(); ++i)
        {
            int p { powers[i] };
            
            while(p > 1 and k)
            {
                p >>= 1;
                --k;
                powers.push_back(p);
            }

            powers[i] = p;

            if(k == 0)
                break;
        }
        
        std::cout << "YES\n";
        for(int b : powers)
            std::cout << b << " ";
    }
    
    std::cout << endl;

    return 0;
}