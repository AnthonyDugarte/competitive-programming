#include <iostream>

int main()
{
    char c = getchar();
    printf("%c", toupper(c));

    while((c = getchar()) != '\n')
        printf("%c", c);

    return 0;
}
