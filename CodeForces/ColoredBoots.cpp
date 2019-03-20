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

template <typename T>
void debug(T val) { cout << val << endl; }
template <typename T, typename... TT>
void debug(T val, TT... tail) { cout << val << " : ", debug(tail...); }

template <typename T>
T min_val() { return std::numeric_limits<T>::min(); }
template <typename T>
T max_val() { return std::numeric_limits<T>::max(); }

type_t gcd(type_t a, type_t b) { return a == 0 ? b : gcd(b % a, a); }

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n;
    char c;

    um_t<char, type_t> a;
    um_t<char, v_t<type_t>> a_pos;
    v_t<type_t> b_marks;

    v_t<p_t<type_t, type_t>> res;

    cin >> n;
    for (size_t i{0}; i < n; ++i)
        cin >> c, ++a[c], a_pos[c].push_back(i);

    for (size_t i{0}; i < n; ++i)
    {
        cin >> c;

        if (c == '?')
            b_marks.push_back(i);
        else if (a.find(c) != a.end() && a[c] > 0)
        {
            res.push_back({a_pos[c][--a[c]] + 1, i + 1});
            if (a[c] == 0)
                a.erase(c);
        }
        else if (a.find('?') != a.end() && a['?'] > 0)
        {
            res.push_back({a_pos['?'][--a['?']] + 1, i + 1});
            if (a['?'] == 0)
                a.erase('?');
        }
    }

    for (auto &p : a)
    {
        if (p.first == '?' || p.second == 0)
            continue;
        if (b_marks.empty())
            break;

        while (!b_marks.empty() && p.second > 0)
        {
            res.push_back({a_pos[p.first][--p.second] + 1, b_marks.back() + 1});
            b_marks.pop_back();
        }
    }

    if (a.find('?') != a.end())
    {
        while (!b_marks.empty())
        {
            if (a['?'] == 0)
                break;
            res.push_back({a_pos['?'][--a['?']] + 1, b_marks.back() + 1});
            b_marks.pop_back();
        }
    }

    cout << res.size() << endl;

    for (auto &p : res)
        cout << p.first << " " << p.second << endl;

    return 0;
}