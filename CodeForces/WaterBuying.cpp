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

int main()
{
    // fastIO();

    type_t n, a, b, t;
    cin >> t;

    while (--t != -1)
    {
        cin >> n >> a >> b;

        b *= n >> 1;
        if (n & 1)
            b += a;

        a *= n;

        cout << std::min(a, b) << endl;
    }

    return 0;
}