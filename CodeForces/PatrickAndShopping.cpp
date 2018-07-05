/* CodeForces Problem: https://codeforces.com/problemset/problem/599/A
 * Made by: Anthony Dugarte and Carlos Bone on "Maratón de práctica ULA 2018"
 * through PapasFritas (codeforces.com/profile/PapasFritas)
 */

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int main ()
{
    unsigned long long d1, d2, d3, df;
    cin >> d1 >> d2 >> d3;

    if(d1 == d2 and d2 == d3)
        df = d1 * 3;
    else
    {
        auto intermedios = d1 * 2 + d2 * 2;
        auto caminito1 = d1 * 2 + d3 * 2;
        auto caminito2 = d2 * 2 + d3 * 2;
        auto vuelta = d1 + d2 + d3;

        auto min1 = intermedios < caminito1 ? intermedios : caminito1;
        auto min2 = vuelta < caminito2 ? vuelta : caminito2;

	df = min1 < min2 ? min1 : min2;
    }


    cout << df << "\n";

    return 0;
}
