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

type_t dp(vvv_t<type_t> &memo, type_t &n, type_t i = 0, bool b = true, bool c = true)
{
    if (i == n - 1)
        return 1;

    type_t &aux{memo[i][b][c]};

    if (aux)
        return aux;

    if (c)
        return aux = (dp(memo, n, i + 1, !b, c) +
                      dp(memo, n, i + 1, b, !c)) %
                     M;
    return aux = (dp(memo, n, i + 1, !b, !c)) % M;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    type_t n, m;
    cin >> n >> m;

    vvv_t<type_t> nn(n, vv_t<type_t>(2, v_t<type_t>(2, 0))), mm(m, vv_t<type_t>(2, v_t<type_t>(2, 0)));

    cout << ((dp(nn, n) << 1) + (dp(mm, m) << 1) - 2) % M << endl;

    return 0;
}