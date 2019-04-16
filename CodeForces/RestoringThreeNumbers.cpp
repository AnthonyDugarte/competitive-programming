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

v_t<type_t> res(3, 0);
v_t<type_t> vals(4);

constexpr size_t a_p = 0, b_p = 1, c_p = 2;

bool get_it(type_t x1, type_t x2, type_t x3, type_t x4)
{
    res[c_p] = x4 - x1;
    res[a_p] = x2 - res[c_p];
    res[b_p] = x3 - res[c_p];

    return res[a_p] >= 0 && res[b_p] >= 0 && res[c_p] >= 0 && res[a_p] + res[b_p] == x1 && res[a_p] + res[c_p] == x2 && res[b_p] + res[c_p] == x3 && res[a_p] + res[b_p] + res[c_p] == x4;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (type_t &i : vals)
        cin >> i;

    std::string s;
    for (size_t i{0}; i < 4; ++i)
        s += i;

    while (!get_it(vals[s[0]], vals[s[1]], vals[s[2]], vals[s[3]]))
        std::next_permutation(s.begin(), s.end());

    for (type_t r : res)
        cout << r << " ";
    cout << endl;

    return 0;
}