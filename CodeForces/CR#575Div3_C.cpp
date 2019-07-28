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

constexpr type_t L{static_cast<type_t>(1e5)};

int main()
{
    std::ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    type_t t;
    cin >> t;

    while (--t != -1)
    {
        type_t n, up{L}, down{-L}, left{-L}, right{L};

        bool failed{false};

        cin >> n;

        while (--n != -1)
        {
            // debug("BOX", left, up, right, down);

            type_t xi, yi, c_left, c_up, c_right, c_down;
            cin >> xi >> yi >> c_left >> c_up >> c_right >> c_down;

            if (failed)
                continue;

            if (!c_left)
            {
                if (right < xi)
                {
                    cout << 0 << endl;
                    failed = true;
                    continue;
                }

                if (left < xi)
                    left = xi;
            }

            if (!c_right)
            {
                if (left > xi)
                {
                    cout << 0 << endl;
                    failed = true;
                    continue;
                }

                if (right > xi)
                    right = xi;
            }

            if (!c_up)
            {
                if (down > yi)
                {
                    cout << 0 << endl;
                    failed = true;
                    continue;
                }

                if (up > yi)
                    up = yi;
            }

            if (!c_down)
            {
                if (up < yi)
                {
                    cout << 0 << endl;
                    failed = true;
                    continue;
                }

                if (down < yi)
                    down = yi;
            }

            if (left > right || down > up)
            {
                cout << 0 << endl;
                failed = true;
                continue;
            }

            if (n == 0)
                cout << 1 << ' ' << left << ' ' << up << endl;
        }
    }

    return 0;
}