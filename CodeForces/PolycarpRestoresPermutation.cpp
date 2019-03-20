// Codeforces Round #547 (Div. 3)

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

void fastIO_n_untie(bool = false);

template <bool jmp = true, typename T>
void debug(T &&val) { cout << val << (jmp ? endl : ' '); }
template <bool jmp = true, typename T, typename... TT>
void debug(T val, TT &&... tail) { cout << val << " : ", debug(tail...); }

template <typename T>
T min_val() { return std::numeric_limits<T>::min(); }
template <typename T>
T max_val() { return std::numeric_limits<T>::max(); }

type_t gcd(type_t a, type_t b) { return a == 0 ? b : gcd(b % a, a); }

size_t n;
type_t min{1};
vt q, p;

int main()
{
    fastIO_n_untie(true);

    cin >> n;
    q = vt(n - 1);
    p = vt(n);
    p[0] = 1;

    for (type_t &i : q)
        cin >> i;

    us_t<type_t> checks;
    checks.insert(p[0]);

    for (size_t i{1}; i < n; ++i)
    {
        p[i] = q[i - 1] + p[i - 1];

        if (checks.find(p[i]) == checks.end())
            checks.insert(p[i]);
        else
        {
            cout << -1 << endl;
            return 0;
        }

        min = std::min(min, p[i]);
    }

    if (min < 1)
        min = 1 - min;
    else
        min = 0;

    for (size_t i{0}; i < n; ++i)
    {
        p[i] = p[i] + min;
        if (p[i] > n || p[i] < 1)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    for (size_t i{0}; i < n; ++i)
        cout << p[i] << " ";
    cout << endl;

    return 0;
}

void fastIO_n_untie(bool untie)
{
    std::ios_base::sync_with_stdio(false);
    if (untie)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
}