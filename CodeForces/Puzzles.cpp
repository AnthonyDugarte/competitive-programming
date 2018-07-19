/* CodeForces Problem: https://codeforces.com/problemset/problem/337/A
 * Made by: Carlos Bone and Anthony Dugarte on "Maratón de práctica ULA 2018"
 */

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;

    int k(m + 1);

    vector <int> puzzles;

    while(--k)
    {
        int aux;

        cin >> aux;

        puzzles.push_back(aux);
    }

    sort(puzzles.begin(), puzzles.end());

    int front = 0;
    int back = n - 1;

    int dif = 10001;

    for (; back < m; ++front, ++back)
    {
        int aux = puzzles[back] - puzzles[front];

        dif = min(aux, dif);
    }

    cout << dif << "\n";

    return 0;
}
