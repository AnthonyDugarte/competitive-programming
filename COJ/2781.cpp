#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    scanf("%i %i\n", &N, &M);

    vector<bool> lights(N, false);
    
    while(--M != -1)
    {
        int type, S, E, counter{ 0 };
        scanf("%i %i %i\n", &type, &S, &E);
        
        if(type == 0)
            for(--S; S < E; ++S)
                lights[S] = lights[S] ^ true;
        else for(--S; S < E; ++S)
            if(lights[S])
                ++counter;
        
        if(type == 1)
            printf("%i\n", counter);
    }

    return 0;
}