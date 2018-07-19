/* CodeForces Problem: http://codeforces.com/problemset/problem/4/A
 */

# include <cstdio>

int main()
{
	unsigned N;
	scanf("%u", &N);

  bool state { false };

  if(N <= 3)
    state = false;

  else if (N % 2 == 0)
  {
    // if halfs are even...
    if ((N / 2) % 2 == 0)
      state = true;
    else for(unsigned i { (N / 2u) - 1u }; i <= N; i += 2)
      if(i == N)
        state = true;
  }

  printf("%s\n", (state ? "YES" : "NO"));
	return 0;
}
