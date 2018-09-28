// https://www.spoj.com/problems/ACODE/

#include <iostream>
#include <string>
#include <map>

size_t num_from_c(char c)
{
  return c - '0';
}

size_t count(std::string &s, std::string::iterator &s_it, std::map<size_t, size_t> memo /*map<code, n_variations>*/)
{
  if(memo.empty())
    return 0;

  if(s_it == s.end())
  {
    size_t counter{ 0 };

    for(auto &&it : memo)
      counter += std::get<1>(it);

    return counter;
  }

  std::map<size_t, size_t> new_memo;
  size_t code { num_from_c(*(s_it)) };

  for(auto &&it : memo)
  {
    if(code != 0)
      new_memo[code] += std::get<1>(it);

    size_t new_code{ std::get<0>(it) * 10 + code };

    if(new_code > 0 and new_code <= 26)
      new_memo[new_code] += std::get<1>(it);
  }

  return count(s, ++s_it, std::move(new_memo));
}

int main()
{
  std::string s;
  std::ios_base::sync_with_stdio(false);

  while(std::cin >> s)
  {
    if(s == "0")
      break;

    auto it = s.begin();

    std::map<size_t, size_t> memo{ { num_from_c(*it), 1 } }; // seed: first code with 1 variation

    std::cout << count(s, ++it, std::move(memo)) << "\n";
  }

  return 0;
}
