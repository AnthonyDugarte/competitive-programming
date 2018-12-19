// Codeforces Round #527
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    
    size_t t;
    cin >> t;

    while(--t != -1)
    {
        size_t n, k;
        cin >> n >> k;

        char c{ 'a' };
        size_t curr_k { 0 };

        while(--n != -1)
        {
            cout << c;
            ++c;
            ++curr_k;

            if(curr_k == k)
            {
                curr_k = 0;
                c = 'a';
            }
        }
        cout << "\n";
    }


    return 0;
}