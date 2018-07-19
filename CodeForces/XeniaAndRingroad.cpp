/* CodeForces Problem: http://codeforces.com/problemset/problem/339/B
 *
 * Note: It was solved on "Maratón de práctica ULA 2018" but correct solution
 * was never submited, we placed third with 5 problems solved (not counting this one),
 * first place had 6 problems solved.
 */

# include <iostream>
# include <vector>

using namespace std;

int main()
{
    unsigned long long n, m;
    cin >> n >> m;

    vector<unsigned long long> tasks(m);
    unsigned long long tTime { 0ull }, pos { 1ull };

    auto goTo = [&](unsigned long long dest)
    {
        if(dest == pos)
            return;

        if(dest > pos)
        {
            tTime += (dest - pos);
            pos = dest;
        }
        else
        {
            tTime += n - pos;
            tTime += dest;
            pos = dest;
        }
    };

    for(unsigned long long i = 0; i < m; ++i)
    {
        unsigned long long aux;
        cin >> aux;

        goTo(aux);
    }

    cout << tTime << "\n";

    return 0;
}
