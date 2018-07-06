/* CodeForces Problem: http://codeforces.com/problemset/problem/337/C
 * Made by: Anthony Dugarte through PapasFritas (codeforces.com/profile/PapasFritas)
 * Note 1: It was a problem of "Maraton de practica ULA 2018" competition.
 *
 * Note 1: you need gmp library: sudo apt-get install libgmp10.
 *      compile with flag: -lgmp
 * Note 2: This one wasn't the one that was uploaded to the plataform
 */
# include <iostream>
# include <gmp.h>

int main ()
{
  using type_t = unsigned long long;

  type_t n, m, k;
  std::cin >> n >> m >> k;

  type_t doublesNeeded{ m - (n - n / k) };

  mpz_t score;
  mpz_init_set_ui(score, 0);

  if (doublesNeeded > 0)
  {
    mpz_setbit(score, doublesNeeded + 1);
    mpz_mul_ui(score, score, k);
    mpz_sub_ui(score, score, 2* k);
  }

  if(m > 0 and doublesNeeded >= 0)
    mpz_add_ui(score, score, m - doublesNeeded * k);
  else if (doublesNeeded < 0)
      mpz_init_set_ui(score, m);

  mpz_mod_ui(score, score, 1000000009ull);
  mpz_out_str(stdout, 10, score);

  mpz_clear(score);
  return 0;
}
