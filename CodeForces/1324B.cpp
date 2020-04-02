#include <bits/stdc++.h>
using namespace std;

template <typename T>
void debug(T t) { cout << t << "\n"; }
template <typename T, typename... TT>
void debug(T t, TT... tail) { cout << t << " : ", debug(tail...); }

int t, arr[5000][2], memo[5000], n, aux;
bool success;

int main()
{
    cin >> t;

    for (int j{t}; j > 0; --j)
    {
        cin >> n;
        success = false;

        for (int i{0}; i < n; ++i)
        {
            cin >> aux;

            if (memo[--aux] != j)
            {
                arr[aux][0] = arr[aux][1] = -1;
                memo[aux] = j;
            }

            if (arr[aux][0] == -1)
                arr[aux][0] = i;
            else if (arr[aux][1] == -1)
            {
                arr[aux][1] = i;
                if (arr[aux][1] - arr[aux][0] > 1)
                    success = true;
            }
            else
                success = true;
        }

        cout << (success ? "YES" : "NO") << "\n";
    }

    return 0;
}