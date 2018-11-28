#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    
    size_t t{};
    cin >> t;

    while(--t != -1)
    {
        size_t a{}, b{};
        cin >> a;
        
        bool break_p{ true };

        for(size_t i{ 1 }; i < 5; ++i)
        {
            cin >> b;
            if(a + 1 != b)
                break_p = false;
            
            a = b;
        }

        if(break_p)
            cout << "Y\n";
        else cout << "N\n";
    }
    
    return 0;
}