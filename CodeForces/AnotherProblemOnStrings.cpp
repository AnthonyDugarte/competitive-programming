// http://codeforces.com/problemset/problem/165/C

# include <iostream>
# include <vector>

int main()
{
  using type_t = unsigned long long;
  type_t k;
  std::cin >> k;
  getchar();

  std::vector<type_t> arr;
  type_t counter{};
  type_t oneCounter{};

  for(char c{ '2' }; c != '\n'; )
    if((c = getchar()) == '0')
      ++counter;
    else
    {
      if(counter > 0)
      {
        arr.push_back(counter);
        counter = 0;
      }
      if(c == '1')
      {
        ++oneCounter;
        arr.push_back(0);
      }
    }

  if(oneCounter < k)
  {
    std::cout << "0\n";
    return 0;
  }

  if(oneCounter == 0)
    arr.push_back(0);

  auto && Lit = arr.begin();
  auto && Rit = arr.begin();

  counter = 0;

  if(*Lit)
  {
    ++Lit;
    ++Rit;
  }

  if(k > 0)
    for(type_t i{}, lim{ k - 1}; i < lim; )
      if(++Rit != arr.end() and *(Rit) == 0)
      {
        --oneCounter;
        ++i;
      }

  auto sumUp = [&]()
  {
    type_t L{ Lit != arr.begin() ? *(Lit - 1) : 0 },
                 R{ Rit + 1 != arr.end() ? *(Rit +1) : 0 };
    if(k == 0)
    {
      if(L & 1)
        counter += 1;
      while(L >= 2)
      {
        counter += (L << 1) - 1;
        L -= 2;
      }
    }
    else counter += L and R ? ++L * ++R : L + R + 1;
  };

  sumUp();

  while(oneCounter > 0 and --oneCounter)
  {
    ++Lit;
    if(*Lit)
      ++Lit;

    ++Rit;
    if(Rit != arr.end() and *Rit)
      ++Rit;

    if(Rit != arr.end())
      sumUp();
  }

  if(k == 0 and arr.back())
  {
    auto val = arr.back();

    if(val & 1)
      counter += 1;

    while(val >= 2)
    {
      counter += (val << 1) - 1;
      val -= 2;
    }
  }

  std::cout << counter << std::endl;
  return 0;
}
