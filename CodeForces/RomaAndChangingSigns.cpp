// https://codeforces.com/problemset/problem/262/B

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int main()
{
   long long n, k, sum { 0ll }, lowest = 100001;
   cin >> n >> k;

   vector<long long> digits(n);

   for(size_t i = 0u; i < n; ++i)
       cin >> digits[i];

   for(int i = 0; i < n; ++i)
   {
       if(digits[i] < 0 and k > 0)
       {
           --k;
           digits[i] *= -1;
       }

       lowest = min(lowest, digits[i]);

       sum += digits[i];
   }


   if(k > 0 and (k & 1))
        sum += (lowest * -1) * 2;

   cout << sum << "\n";
   return 0;
}
