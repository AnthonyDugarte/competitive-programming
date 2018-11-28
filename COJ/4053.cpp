// #include <bits/stdc++.h>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%i\n", &t);
    
    while(--t != -1)
    {
        int r, c;
        char in;
        scanf("%i %i\n", &r, &c);

        vector<int> cols(c, 0);

        for(size_t x{ 0 }; x < r; ++x)
        {
            int r_xs{ 0 };

            for(size_t y{ 0 }; y < c; ++y)
            {
                in = getchar();

                if(in == '1')
                {
                    ++r_xs;
                    ++cols[y];
                }
            }
            getchar();
            printf("%i ", r_xs);
        }
        printf("\n");

        for(int &val : cols)
            printf("%i ", val);
        printf("\n");
    }

    return 0;
}