#include <bits/stdc++.h>

using namespace std;

char revert_encrypt(char c)
{
  if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
  {
    if(c == 'A')
      return 'Z';

    if (c == 'a')
      return 'z';

    return c - 1;
  }

  return c;
}

void revert_encrypt(const string &src, size_t l, size_t r, size_t &pos)
{
  if(l > r)
    return;

  size_t m{ (l + r) >> 1 };

  char c { revert_encrypt(src[pos]) };

  revert_encrypt(src, l, m - 1, ++pos);
  printf("%c", c);
  revert_encrypt(src, m + 1, r, pos);
}

int main()
{
  ios_base::sync_with_stdio(false);
  
  string s;
  s.reserve(20000);

  while(getline(cin, s))
  {
    size_t pos{};

    revert_encrypt(s, 1, s.size(), pos);
    printf("\n");
  }
  return 0;
}