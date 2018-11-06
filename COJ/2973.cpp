#include <bits/stdc++.h>

using namespace std;

int main()
{
    size_t N;
    
    while(cin >> N and N != 0)
    {
        vector<char> numerals;
        int zero_count{ 0 };
        
        for(size_t i{ 0 }; i < N; ++i)
        {
            char num;
            cin >> num;
            if(num == '0')
                ++zero_count;
            else numerals.push_back(num);
        }
        sort(numerals.begin(), numerals.end());

        string a{ numerals[0] } , b{ numerals[1] };
        
        size_t i = 0;
        while(zero_count > 0)
        {
            if(i & 1)
                b.push_back('0');
            else a.push_back('0');

            --zero_count;
            ++i;
        }

        for(vector<char>::iterator it{ next(numerals.begin(), 2)}; it != numerals.end(); ++it, ++i)
            if(i & 1)
                b.push_back(*it);
            else a.push_back(*it);
        
        cout << stoi(a) + stoi(b) << endl;
    }

    return 0;
}