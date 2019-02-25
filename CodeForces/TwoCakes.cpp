// Codeforces Round #542 [Alex Lopashev Thanks-Round] (Div. 2)
#include <bits/stdc++.h>

using std::cin;
using std::cout;

void fastIO(bool tie = true)
{
    std::ios_base::sync_with_stdio(false);

    if (!tie)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
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

using pair = p_t<type_t, type_t>;

int main()
{
    fastIO(/* false */);

    type_t n, st1{0}, st2{0}, i1{0}, i2{0};
    cin >> n;
    n <<= 1;

    v_t<pair> v(n);
    for (size_t i{0}; i < n; ++i)
    {
        cin >> v[i].first;
        v[i].second = i;
    }

    std::sort(v.begin(), v.end(), [](pair &a, pair &b) {
        return a.first < b.first;
    });

    for (size_t i{0}; i < n; i += 2)
    {
        type_t aux1{v[i].second}, aux2{v[i + 1].second};

        bool cond = std::abs(i1 - aux1) + std::abs(i2 - aux2) <
                    std::abs(i1 - aux2) + std::abs(i2 - aux1);

        st1 += std::abs(i1 - (cond ? aux1 : aux2));
        st2 += std::abs(i2 - (cond ? aux2 : aux1));

        i1 = cond ? aux1 : aux2;
        i2 = cond ? aux2 : aux1;
    }

    cout << st1 + st2;
    cout << endl;

    return 0;
}