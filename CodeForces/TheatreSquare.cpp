/* CodeForces Problem: http://codeforces.com/problemset/problem/1/A
 * Made by: Anthony Dugarte through PapasFritas (codeforces.com/profile/PapasFritas)
 */

# include <cstdio>

int main()
{
  unsigned long long n, m, a;
  scanf("%llu %llu %llu", &n, &m, &a);

  unsigned long long aux;
  aux = n / a;
  unsigned long long xFlagStones = aux * a < n ? aux + 1 : aux;


  aux = m / a;
  unsigned long long yFlagStones = aux * a < m ? aux + 1 : aux;

  printf("%llu\n", xFlagStones * yFlagStones);
  return 0;
}
