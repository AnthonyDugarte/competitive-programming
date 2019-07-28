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

v_t<char> RGB{{'R', 'G', 'B'}};

int main()
{
    std::ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    type_t t;
    cin >> t;

    while (--t != -1)
    {
        size_t n, k;
        str_t s;
        cin >> n >> k >> s;

        size_t rM{0}, gM{0}, bM{0}, maxVal{0};

        for (size_t i{0}; i < n; ++i)
        {
            rM += (s[i] == RGB[i % 3]);
            gM += (s[i] == RGB[(i + 1) % 3]);
            bM += (s[i] == RGB[(i + 2) % 3]);

            if (i >= k)
            {
                rM -= (s[(i - k)] == RGB[(i - k) % 3]);
                gM -= (s[(i - k)] == RGB[((i - k) + 1) % 3]);
                bM -= (s[(i - k)] == RGB[((i - k) + 2) % 3]);
            }

            maxVal = std::max({rM, gM, bM, maxVal});

            if (maxVal == k)
                break;
        }

        cout << k - maxVal << endl;
    }

    return 0;
}