// Preclasificatorio Latinoamericano ACM-ICPC ULA 2018
// http://codeforces.com/group/1daWYZTt2e/contest/231528/standings/groupmates/true

#include <iostream>
using namespace std;

int main(){
	int n = 1;
	cin >> n;
	
	while(n != -1)
	{
		if(n > 2)
			cout << "Yes" << endl;
		else cout << "No" << endl; 
		
        cin >> n;
	}
		
	return 0;
}