#include <stdio.h>

int main()
{
    int t;
    scanf("%i", &t);
    
    while(--t != -1)
    {
        int i;
        float d, va, vb, vf;

        scanf("%i %f %f %f %f\n", &i, &d, &va, &vb, &vf);
        printf("%i %.2f\n", i, vf * (d / (va + vb)));
    }

    return 0;
}