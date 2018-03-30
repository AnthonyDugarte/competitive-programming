#include <cstdio>

int main()
{
  size_t n;
  scanf("%lu", &n);
  unsigned long donation[n];
  for(unsigned long i = 0; i < n; ++i)
    scanf("%lu",&donation[i]);
  unsigned long q;
  scanf("%lu",&q);

  unsigned long long int Tdonated = donation[0], maxDon = 0, medDon = 0;
  unsigned long long int winners[q];

  for(unsigned long i = 0, N = 1,goal; i < q; ++i)
  {
    scanf("%lu", &goal);
    if(maxDon != 0 && goal > maxDon )
    {
      winners[i] = 0;
      continue;
    }
    if(medDon <= goal && Tdonated < medDon && medDon != 0)
    {
      Tdonated=medDon;
      N = (unsigned long)n/2 + 1;
    }else if(medDon >= goal && Tdonated > medDon && medDon != 0)
    {
      Tdonated=medDon;
      N = (unsigned long)n/2 + 1;
    }
    while(Tdonated < goal && N < n)
      Tdonated+=donation[N++];
    while(Tdonated > goal && (Tdonated - donation[N-1]) >= goal && N > 0)
      Tdonated-=donation[--N];

    if(N == (unsigned long)n/2 + 1 && medDon == 0)
      medDon = Tdonated;
    if(goal > Tdonated)
    {
      winners[i] = 0;
      if (maxDon == 0)
        maxDon = Tdonated;
    }
    else winners[i] = N;
  }

  for(size_t i = 0; i < q; ++i)
  {
    if (winners[i] == 0)
      printf("none\n");
    else printf("%lu\n",winners[i]);
  }

  return 0;
}
