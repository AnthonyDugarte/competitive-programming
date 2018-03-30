#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>

using namespace std;

int main()
{
  size_t initial_force,
           initital_mass,
           total_pieces;
  cin >> initial_force >> initital_mass >> total_pieces;

  vector<tuple<size_t, size_t>> pieces(total_pieces);


  size_t total_combinations(move(pow(2,total_pieces)));


  double best_aceleration = move(static_cast<double>(initial_force) / initital_mass);
  size_t best_comb(0);

  size_t combination_n(1),
           car_piece(1),
           prefinal_combinations;
  double aux_aceleration;
  size_t aux_force,
           aux_mass;
  do
  {
    prefinal_combinations = move(combination_n << 1);

    cin >> get<0>(pieces[car_piece - 1]) >> get<1>(pieces[car_piece - 1]);

    while(combination_n < prefinal_combinations)
    {
      aux_force = initial_force;
      aux_mass = initital_mass;

      for(size_t piece_n = 0; piece_n < car_piece; ++piece_n)
        if(1 << piece_n & combination_n)
        {
          aux_force+= get<0>(pieces[piece_n]);
          aux_mass+= get<1>(pieces[piece_n]);
        }

      aux_aceleration = move(static_cast<double>(aux_force) / aux_mass);
      if(aux_aceleration > best_aceleration)
      {
        best_aceleration = move(aux_aceleration);
        best_comb = combination_n;
      }
      ++combination_n;
    }
    ++car_piece;
  }while(prefinal_combinations != total_combinations);


  if (best_comb == 0)
  {
    cout << "NONE" << endl;
    return 0;
  }

  for(size_t piece_n = 0; piece_n < total_pieces; ++piece_n)
    if(1 << piece_n & best_comb)
      cout << piece_n + 1 << endl;
  return 0;
}
