// Preclasificatorio Latinoamericano ACM-ICPC ULA 2018
// http://codeforces.com/group/1daWYZTt2e/contest/231528/standings/groupmates/true

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	string a, b;
	cin >> a >> b;
	
	while(a != "0" and b != "0")
	{
		while(a.size() > b.size())
			b = "0" + b;
		while(a.size() < b.size())
			a = "0" + a;
		
		string result{""};
		
		bool carry = false;
		
		for(size_t i{ a.size() - 1 }; i != -1; --i)
		{
			int res = (a[i] - '0') + (b[i] - '0');
			cout << a[i] << " + " << b[i] << endl;
			
			if(carry)
				++res;
			
			carry = false;
			
			if(res >= 10)
			{
				res -= 10;
				carry = true;
			}
			
			result = to_string(res) + result;
			
            cout << "Current: " << result << " Carry: " << (carry ? 1 : 0) << endl;
		}
		
		cin >> a >> b;
	}
		
	return 0;	
}