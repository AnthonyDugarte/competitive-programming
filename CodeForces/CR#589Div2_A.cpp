#include <bits/stdc++.h>

template <typename T, typename U>
using p_t = std::pair<T, U>;

template <typename T>
using s_t = std::set<T>;
template <typename T>
using us_t = std::unordered_set<T>;
template <typename T>
using v_t = std::vector<T>;
template <typename T>
using vv_t = std::vector<std::vector<T>>;

template <typename T, typename U>
using m_t = std::map<T, U>;
template <typename T, typename U>
using um_t = std::unordered_map<T, U>;

using type_t = int64_t;
using utype_t = uint64_t;
using str_t = std::string;

using vt = v_t<type_t>;
using vut = v_t<utype_t>;
using vstr = v_t<str_t>;

using vvt = vv_t<type_t>;
using vvut = vv_t<utype_t>;
using vvstr = vv_t<str_t>;

using std::cin;
using std::cout;

constexpr char endl = '\n';
constexpr type_t M{static_cast<type_t>(1e9 + 7)};

template <typename T>
void debug(T val) { cout << val << endl; }
template <typename T, typename... TT>
void debug(T val, TT... tail) { cout << val << " : ", debug(tail...); }

template <typename T>
T min_val() { return std::numeric_limits<T>::min(); }
template <typename T>
T max_val() { return std::numeric_limits<T>::max(); }

type_t gcd(type_t a, type_t b) { return b == 0 ? a : gcd(b, a % b); }

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int l, r;

    cin >> l >> r;

    for (int i{l}; i <= r; ++i)
    {
        str_t s{std::to_string(i)};
        v_t<bool> memo(10, false);
        bool f{true};

        for (const char &c : s)
            if (memo[c - '0'])
            {
                f = false;
                break;
            }
            else
                memo[c - '0'] = true;

        if (f)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}