#include <iostream>
#include <string>

// #define ENCRYPT
#define REVERSE_ENCRYPT

#ifdef ENCRYPT
char encrypt(char c)
  {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
      if(c == 'Z')
        return 'A';

      if (c == 'z')
        return 'a';

      return c + 1;
    }

    return c;
  }

  std::string encrypt(const std::string &str, size_t l, size_t r)
  {
    if(l > r)
      return std::string("");

    size_t m{ (l + r) >> 1 };

    return encrypt(str[m - 1]) + encrypt(str, l, m - 1) + encrypt(str, m + 1, r);
  }

  std::string encrypt(const std::string &str)
  {
    return encrypt(str, 1, str.size());
  }
#endif // ENCRYPT


#ifdef REVERSE_ENCRYPT
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

  void revert_encrypt(const std::string &src, std::string &tgt, size_t l, size_t r, size_t &pos)
  {
    if(l > r)
      return;

    size_t m{ (l + r) >> 1 };

    tgt[m - 1] = revert_encrypt(src[pos]);
    ++pos;

    revert_encrypt(src, tgt, l, m - 1, pos);
    revert_encrypt(src, tgt, m + 1, r, pos);
  }

  std::string revert_encrypt(const std::string &str)
  {
    std::string s;
    s.resize(str.size());
    size_t pos{};

    revert_encrypt(str, s, 1, str.size(), pos);

    return std::move(s);
  }
#endif // REVERSE_ENCRYPT

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::string s;

  #ifdef ENCRYPT
    while(s != "end.")
    {
      std::getline(std::cin, s, '\n');
      std::cout << encrypt(s) << "\n";
    }
  #endif // ENCRYPT

  #ifdef REVERSE_ENCRYPT
    while(s != "ofe.")
    {
      std::getline(std::cin, s, '\n');
      std::cout << revert_encrypt(s) << "\n";
    }
  #endif // REVERSE_ENCRYPT

  return 0;
}
