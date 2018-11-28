#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    
    size_t t{};
    cin >> t;

    while(--t != -1)
    {
        string s;
        cin >> s;
        size_t max{s.size() - 1};
        for(size_t i{ 0 }; i < max; i += 2)
            for(size_t j = s[i] - '0'; --j != -1; )
                cout << s[i + 1];
        cout << "\n";
    }
    
    return 0;
}