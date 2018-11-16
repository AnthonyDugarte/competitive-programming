#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    size_t t;
    cin >> t;

    while(--t != -1)
    {
        int correct{ 0 };

        for(size_t i{ 0 }; i < 5; ++i)
        {
            int X, Y, Z;
            cin >> X >> Y >> Z;

            if(X + Y == Z or X * Y == Z or X - Y == Z)
                ++correct;
            else if(Y != 0 and X / Y == Z and X % Y == 0)
                ++correct;
        }

        cout << correct << "\n";
    }
    
    return 0;
}