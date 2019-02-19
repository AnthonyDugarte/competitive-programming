// Educational Codeforces Round 59 (Rated for Div. 2)

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

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

constexpr type_t module{static_cast<type_t>(1e9 + 7)};

int main()
{
    fastIO();

    size_t n, t;
    cin >> t;

    while (--t != -1)
    {
        cin >> n;
        v_t<int> v(n);

        bool different{false};

        for (int &i : v)
        {
            char c;
            cin >> c;
            i = c - '0';

            if (i != v[0])
                different = true;
        }

        if (n & 1)
        {
            cout << "YES\n2\n";
            for (size_t i{0}; i < (n >> 1); ++i)
                cout << v[i];
            cout << " ";
            for (size_t i{n >> 1}; i < n; ++i)
                cout << v[i];
        }
        else if (n == 2)
        {
            if (v[0] >= v[1])
            {
                cout << "NO";
            }
            else
            {
                cout << "YES\n2\n";
                cout << v[0] << " " << v[1];
            }
        }
        else
        {
            cout << "YES\n2\n";
            for (size_t i{0}; i < (n >> 1) - 1; ++i)
                cout << v[i];
            cout << " ";
            for (size_t i{(n >> 1) - 1}; i < n; ++i)
                cout << v[i];
        }

        cout << "\n";
    }

    return 0;
}