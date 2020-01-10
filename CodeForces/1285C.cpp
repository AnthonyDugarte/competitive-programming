#include <bits/stdc++.h>

using namespace std;

int64_t x;

pair<int64_t, int64_t>
sum(vector<int64_t> &p, size_t i = 0, int64_t aa = 1, int64_t bb = 1)
{
    if (i == p.size())
        return {aa, bb};

    pair<int64_t, int64_t> p1{sum(p, i + 1, aa * p[i], bb)};
    pair<int64_t, int64_t> p2{sum(p, i + 1, aa, bb * p[i])};

    int64_t m1{max(p1.first, p1.second)};
    int64_t m2{max(p2.first, p2.second)};

    return min(m1, m2) == m1 ? p1 : p2;
}

pair<int64_t, int64_t> solve(int64_t x)
{
    vector<int64_t> p;

    if (!(x & 1))
    {
        p.push_back(1);
        while (!(x & 1))
        {
            x >>= 1;
            p[0] <<= 1;
        }
    }

    for (int64_t i{3}; i * i <= x; i += 2)
    {
        if (!(x % i))
        {
            p.push_back(i);
            x /= i;
        }
        int64_t &aux{*p.rbegin()};

        while (!(x % i))
        {
            x /= i;
            aux *= i;
        }
    }

    if (x > 2)
        p.push_back(x);

    return sum(p);
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> x;

    pair<int64_t, int64_t> p{solve(x)};
    std::cout << p.first << " " << p.second << "\n";

    return 0;
}