// Preclasificatorio Latinoamericano ACM-ICPC ULA 2018
// http://codeforces.com/group/1daWYZTt2e/contest/231528/standings/groupmates/true

# include <bits/stdc++.h>
using namespace std;

bool correct(size_t num, size_t zeroes, size_t digits)
{
	size_t l_zeroes{ 0 };
	size_t sum{ 0 };
	
	while(num != 0)
	{
		size_t m = num % 10;
		
		sum += m;
		
		if(m == 0)
			++l_zeroes;
		
		num /= 10;
	}
	
	return sum == digits and zeroes <= l_zeroes;
}

int main(){
	size_t K, D, Z, I;
	
	cin >> D >> K >> Z >> I;
	
	while(K != 0 or D != 0 or Z != 0 or I != 0)
	{
		string s = "1" + std::string(K - 1, '0');
		
		for(size_t i = stoi(s), t = 0; t != I; ++i)
		{
			if(correct(i, Z, D))
				++t;
			
			if(t == I)
				cout << i << endl;
		}
		
		cin >> D >> K >> Z >> I;
	}
	
	
	
	return 0;
}