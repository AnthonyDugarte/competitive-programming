#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    
    size_t counter{ 0 };
    char c;

    while(cin >> c)
        if(c != 'a' and c != 'e' and c != 'i' and c != 'o' and c != 'u')
            counter += c - 'a' + 1  ;
    
    cout << counter << endl;
    
    return 0;
}