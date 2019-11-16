#include <bits/stdc++.h>

using namespace std;
int n, lday{-1}, aux, t{0};
set<int> s;
set<int> entered;
vector<int> days;

int main()
{
    cin >> n;

    if (n & 1)
    {
        cout << "-1\n";
        return 0;
    }

    for (size_t i{0}; i < n; ++i)
    {
        cin >> aux;

        if (aux > 0)
        {
            if (entered.find(aux) != entered.end())
            {
                cout << "-1\n";
                return 0;
            }

            s.insert(aux);
            entered.insert(aux);
        }
        else
        {
            if (s.find(aux * -1) == s.end())
            {
                cout << "-1\n";
                return 0;
            }

            s.erase(aux * -1);
        }

        if (s.empty())
        {
            entered.clear();
            days.push_back(i - lday);
            t += i - lday;

            lday = i;
        }
    }

    if (t != n)
    {
        cout << "-1\n";
        return 0;
    }

    cout << days.size() << "\n";

    for (int &i : days)
        cout << i << " ";
    cout << "\n";

    return 0;
}