#include <stdio.h>

int main(){
  unsigned short int n, q;

  scanf("%hu %hu",&n, &q);

  short int note[n];

  for(unsigned short int b = 0; b < n; b++)
    scanf("%hd", &note[b]);

  short int auxT = note[0]-1, N = 1;

  for(unsigned short int i = 0, question = 0; i < q; i++){
    scanf("%hd", &question);
    while(auxT < question && N < n)
      auxT+=note[N++];
    while((auxT > question && (auxT - note[N-1]) >= question) && N > 0)
      auxT-=note[--N];
    printf("%hd\n", N);
  }
  return 0;
}
