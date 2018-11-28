#include <vector>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    size_t t;
    cin >> t;

    while(--t != -1)
    {
        size_t n, swaps{ 0 };
        string s;
        cin >> n >> s;

        for(size_t i{ 0 }; i < n - 1; )
        {
            if(s[i] == '>' and s[i + 1] == '<')
            {
                swap(s[i], s[i + 1]);

                ++swaps;
                if(i > 0)
                    --i;
            }
            else ++i;
        }

        cout << swaps << "\n";
    }

    return 0;
}