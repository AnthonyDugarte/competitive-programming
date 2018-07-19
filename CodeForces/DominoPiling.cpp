/* CodeForces Problem: http://codeforces.com/problemset/problem/50/A
 */

# include <iostream>

int main ()
{
  int X, Y;

  std::cin >> X >> Y;

  if(X == 1 and Y == 1)
  {
    std::cout << "0\n";
    return 0;
  }

  int res;

  auto doTheJob = [&](int A, int B) ->void
  {
    int maxA, maxB;

    if(A & 1)
      maxA = (A - 1) >> 1;
    else maxA = A >> 1;

    A -= maxA << 1;
    maxB = B;

    res = maxA * maxB;

    if(A == 1 and B > 1)
      res += B & 1 ? (B - 1) >> 1 : B >> 1;
  };

  if(Y == 1)
    doTheJob(X, Y);
  else doTheJob(Y, X);

  std::cout << res << std::endl;
  return 0;
}
