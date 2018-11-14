#include <cstdio>

int main()
{
  unsigned int girls, boys;
  while(true)
  {
    scanf("%u %u", &girls, &boys);

    if(not girls & not boys)
      break;

    printf("%d\n", girls += boys);
  }

  return 0;
}