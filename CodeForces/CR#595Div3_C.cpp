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
using vv_t = v_t<v_t<T>>;
template <typename T>
using vvv_t = v_t<vv_t<T>>;

template <typename T, typename U>
using m_t = std::map<T, U>;
template <typename T, typename U>
using um_t = std::unordered_map<T, U>;

using utype_t = uint64_t;
using type_t = int64_t;
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

utype_t cstPow(utype_t n, utype_t e)
{
    utype_t res{1};

    while (e > 0)
    {
        if (e & 1)
            res *= n;
        e >>= 1;
        n *= n;
    }

    return res;
}

um_t<utype_t, utype_t> memo;

utype_t getR(utype_t n, int i)
{
    if (i == 0 && n > 1)
        return cstPow(3, 38);
    if (i == 0)
        return 1;

    utype_t &r{memo[n]};

    if (r)
        return r;

    utype_t c{cstPow(3, i)};
    if (c >= n)
        return r = std::min(c, getR(n, i - 1));

    return r = std::min(c + getR(n - c, i - 1), getR(n, i - 1));
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    size_t q;
    utype_t n;
    cin >> q;

    while (q--)
    {
        cin >> n;
        memo.clear();
        cout << getR(n, static_cast<int>(std::ceil(std::log(n) / std::log(3))))
             << endl;
    }

    return 0;
}