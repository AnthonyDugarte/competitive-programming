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

type_t gcd(type_t a, type_t b) { return a == 0 ? b : gcd(b % a, a); }

type_t get_it(type_t a, type_t b, type_t c, type_t day)
{
    type_t days{0};

    while (a >= 0 && b >= 0 && c >= 0)
    {
        if (day == 0 || day == 3 || day == 6)
            if (--a < 0)
                break;
        if (day == 1 || day == 5)
            if (--b < 0)
                break;
        if (day == 2 || day == 4)
            if (--c < 0)
                break;

        ++day;
        ++days;
        day %= 7;
    }

    return days;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    type_t a, b, c, days{0};
    cin >> a >> b >> c;

    type_t safe{std::min(a / 3, std::min(b >> 1, c >> 1))};

    safe -= 2;
    while (safe < 0)
        ++safe;

    // debug("safe", safe);

    a -= safe * 3;
    b -= safe * 2;
    c -= safe * 2;
    days += safe * 7;

    type_t max_days{0};

    for (size_t i{0}; i < 7; ++i)
        max_days = std::max(max_days, get_it(a, b, c, i));

    // debug(a, b, c);

    // debug("days", days);
    // debug("max days", max_days);
    cout << days + max_days << endl;

    return 0;
}