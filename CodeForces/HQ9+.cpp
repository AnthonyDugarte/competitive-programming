// http://codeforces.com/contest/133/problem/A

 #include <iostream>

int main()
{
	char c{ 'a' };

	while(c != '\n')
	{
		c = getchar();
		if(c == 'H' or c == 'Q' or c == '9')
		{
			std::cout << "YES\n";
			return 0;
		}
	}

	std::cout << "NO\n";
	return 0;
}
