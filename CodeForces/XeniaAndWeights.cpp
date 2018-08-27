// https://codeforces.com/problemset/problem/339/C

# include <iostream>
# include <string>
# include <vector>

std::vector<short int> weights;
short int m;

short int playN{};
unsigned int LeftScale{}, RightScale{};
std::vector<short int> plays;

bool win(short int play, bool isRightPlay, short int lastPlay)
{
  // is it a consecutive play?
  if(play == lastPlay)
    return false;
  else if(isRightPlay) // right scale checking
  {
    if(::RightScale + play <= ::LeftScale)
      return false;
    ::RightScale += play;
  }
  else // left scale checking
  {
    if(::LeftScale + play <= ::RightScale)
      return false;
    ::LeftScale += play;
  }

  ++::playN;
  ::plays.push_back(play);

  // if it is our winning weight
  if(::playN == ::m)
  {
    std::cout << "YES\n";
    for(auto && p : ::plays) // we print our weights
      std::cout << p << " ";
    std::cout << "\n";
    return true;
  }

  // now, if it is not our winning play
  for(auto && weight : ::weights)
    if(win(weight, !isRightPlay, play))
      return true;

  // if we did not found our winning weight, we take our weigh out
  --::playN;
  if(isRightPlay)
    ::RightScale -= play;
  else ::LeftScale -= play;

  ::plays.pop_back();
  return false;
}


int main()
{
  std::string str;
  std::cin >> str;

  for(size_t i{}; i < 10; ++i)
    if(str[i] == '1')
      ::weights.push_back(i + 1);

  std::cin >> ::m;

  for(auto && weight : ::weights)
    if(win(weight, false, 0))
      return 0;

  std::cout << "NO\n";
  return 0;
}
