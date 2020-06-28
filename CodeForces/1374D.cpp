#include <bits/stdc++.h>
using namespace std;

template <typename T>
void f_cout(T val) { cout << val << endl; }
template <typename T, typename... TT>
void f_cout(T val, TT... tail) { cout << val << " : ", f_cout(tail...); }

int t;
uint64_t n, k, x, acc, arr[200000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> t;

    for (int ti{0}; ti < t; ++ti)
    {
        cin >> n >> k;

        priority_queue<pair<uint64_t, uint64_t>, vector<pair<uint64_t, uint64_t>>, greater<pair<uint64_t, uint64_t>>> que;
        map<uint64_t, uint64_t> m;

        x = acc = 0;

        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
            ++m[arr[i] % k == 0 ? 0 : k - arr[i] % k];
        }

        for (const auto &p : m)
            if (p.first != 0)
                que.push(p);

        if (que.empty())
        {
            cout << 0 << "\n";
            continue;
        }

        while (!que.empty())
        {
            auto p = que.top();

            que.pop();

            if (p.first == x)
            {
                x++;
                acc++;
                p.second--;
            }
            else
            {
                acc += p.first - x + 1;
                x = p.first + 1;
                p.second--;
            }

            if (p.second)
                que.push({p.first + k, p.second});
        }
        cout << acc << "\n";
    }

    return 0;
}