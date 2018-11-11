#include <bits/stdc++.h>

using namespace std;

int sum_digits(int n)
{
    int res = 0;
    while(n != 0)
    {
        res += n % 10;
        n /= 10;
    }
    
    return res;
}

vector<int>vals(100001, -1);

int main()
{
    int n = 1;

    while(cin >> n and n != 0)
    {
        if(vals[n] == -1)
        {
            int first_s { sum_digits(n) };
            int res_s { -1 }, j { 10 };

            while(res_s != first_s)
                res_s = sum_digits(n * (++j));
            vals[n] = j;
        }

        cout << vals[n] << "\n";
    }   
    return 0;
}