/* CodeForces Problem: http://codeforces.com/problemset/problem/236/A
 * Made by: Anthony Dugarte and Carlos Bone on "Maratón de práctica ULA 2018"
 */

# include <iostream>
# include <vector>

using namespace std;

int main ()
{
    string str;

    cin >> str;

    vector<bool> repited(256);
    size_t counter { 0u };

    for(auto && c : str)
        if(not repited[c])
        {
            repited[c] = true;
            ++counter;
        }

    cout << (counter & 1 ? "IGNORE HIM!" : "CHAT WITH HER!") << "\n";

    return 0;
}
