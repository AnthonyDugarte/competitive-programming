
#include <bits/stdc++.h>

using namespace std;

template <typename T>
void f_cout(T val) { cout << val << endl; }
template <typename T, typename... TT>
void f_cout(T val, TT... tail) { cout << val << " : ", f_cout(tail...); }

int64_t t, n, acc;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> t;

    for (int ti{0}; ti < t; ++ti)
    {
        cin >> n;

        bool flag = true;
        acc = 0;

        while (true)
        {
            if (n == 1)
                break;
            ++acc;

            if (n % 6)
            {
                n *= 2;
                ++acc;
            }

            if (n % 6 == 0)
                n /= 6;
            else
            {
                flag = false;
                break;
            }
        }

        cout << (flag ? acc : -1) << endl;
    }

    return 0;
}