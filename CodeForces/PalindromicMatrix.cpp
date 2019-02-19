#include <bits/stdc++.h>

using std::cin;
using std::cout;

void fastIO()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

template <typename T, typename U>
using p_t = std::pair<T, U>;

template <typename T>
using s_t = std::set<T>;
template <typename T>
using us_t = std::unordered_set<T>;
template <typename T>
using v_t = std::vector<T>;

template <typename T, typename U>
using m_t = std::map<T, U>;
template <typename T, typename U>
using um_t = std::unordered_map<T, U>;

using type_t = int64_t;
using utype_t = uint64_t;
using str_t = std::string;

template <typename T>
T min_val() { return std::numeric_limits<T>::max(); }
template <typename T>
T max_val() { return std::numeric_limits<T>::max(); }
type_t gcd(type_t a, type_t b) { return a == 0 ? b : gcd(b % a, a); }

constexpr char endl = '\n';
constexpr type_t module{static_cast<type_t>(1e9 + 7)};

type_t n, in, four{0}, two{0}, one{0}, odd{0};

um_t<type_t, type_t> memo;

v_t<type_t> f, t, o;

void process()
{
    four = (n - odd) >> 1;
    four *= four;

    if (odd)
        two = n - 1;
    one = odd;

    for (auto &p : memo)
    {
        while (f.size() < four && p.second >= 4)
        {
            f.push_back(p.first);
            p.second -= 4;
        }

        while (p.second >= 2)
        {
            t.push_back(p.first);
            p.second -= 2;
        }

        if (p.second & 1)
        {
            o.push_back(p.first);
            --p.second;
        }
    }

    if (four != f.size() || two != t.size() || one != o.size())
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    v_t<v_t<type_t>> m(n, v_t<type_t>(n, 0));

    type_t r{n - odd}, f_i{0}, t_i{0}, o_i{0};

    r >>= 1;

    for (type_t i{0}; i <= r; ++i)
    {
        for (type_t j{0}; j <= r; ++j)
        {
            if (!odd && (i == r || j == r))
                continue;

            type_t i2{n - (i + 1)}, j2{n - (j + 1)};

            if (i == r && j == r)
                m[i][j] = o[0];
            else if (i == r)
            {
                m[i][j] = m[i][j2] = t[t_i];
                ++t_i;
            }
            else if (j == r)
            {
                m[i][j] = m[i2][j] = t[t_i];
                ++t_i;
            }
            else
            {
                m[i][j] = m[i][j2] = m[i2][j] = m[i2][j2] = f[f_i];

                ++f_i;
            }
        }
    }

    for (size_t i{0}; i < n; ++i)
    {
        for (size_t j{0}; j < n; ++j)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // fastIO();

    cin >> n;
    odd = n & 1;

    for (type_t i{0}, r{n * n}; i < r; ++i)
    {
        cin >> in;
        ++memo[in];
    }

    process();

    return 0;
}