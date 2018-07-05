/* CodeForces Problem: http://codeforces.com/problemset/problem/339/A
 * Made by: Anthony Dugarte and Carlos Bone on "Maratón de práctica ULA 2018"
 * through PapasFritas (codeforces.com/profile/PapasFritas)
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string str;

    cin >> str;

    vector<string> op;

    string aux;

    size_t counter = 0;

    for (auto && c : str)
    {
        if (c == '+')
        {
            op.push_back(aux);
            aux.clear();
            ++counter;
            continue;
        }
        aux.push_back(c);
    }

    op.push_back(aux);

    sort(op.begin(), op.end());

    for (auto & s : op)
    {
        cout << s;
        if (counter--)
            cout << '+';
    }
    cout << "\n";

    return 0;
}
