// Codeforces Round #543 (Div. 2, based on Technocup 2019 Final Round)
#include <bits/stdc++.h>

template <typename T, typename U>
using p_t = std::pair<T, U>;

template <typename... T>
using s_t = std::set<T...>;
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

constexpr bool MULT_TESTS = false,
               UNTIE_IO = false;

constexpr char endl = '\n';
constexpr type_t M{static_cast<type_t>(1e9 + 7)};

void fastIO(bool = false);
template <typename T>
void debug(T val) { cout << val << endl; }
template <typename T, typename... TT>
void debug(T val, TT... tail) { cout << val << " : ", debug(tail...); }

template <typename T>
T min_val() { return std::numeric_limits<T>::min(); }
template <typename T>
T max_val() { return std::numeric_limits<T>::max(); }

type_t gcd(type_t a, type_t b) { return a == 0 ? b : gcd(b % a, a); }

void code(size_t t)
{
    size_t n, m, k;
    cin >> n >> m >> k;

    vt students(n);
    vt std_school(n);

    m_t<type_t, s_t<type_t, std::greater<type_t>>> schools;
    vt specials(k);

    for (type_t &i : students)
        cin >> i;

    for (size_t i{0}; i < n; ++i)
    {
        size_t school;
        cin >> school;
        schools[school].insert(students[i]);
        std_school[i] = school;
    }

    for (type_t &i : specials)
    {
        cin >> i;
        --i;
    }

    std::sort(specials.begin(), specials.end(), [&](type_t &a, type_t &b) {
        return students[a] >= students[b];
    });

    size_t newSchools{0};

    // debug("schools");
    // for (auto &p : schools)
    // {
    //     for (type_t i : p.second)
    //         cout << i << " ";
    //     cout << endl;
    // }

    for (type_t &i : specials)
    {
        s_t<type_t, std::greater<type_t>> &ss{schools[std_school[i]]};
        type_t &pwr{students[i]};

        if (std::distance(ss.begin(), ss.find(pwr)) >= 1)
        {
            ++newSchools;
            ss.erase(pwr);
        }
    }

    debug(newSchools);
}

void use_tests(size_t t)
{
    cin >> t;
    for (size_t i{0}; i < t; ++i)
        code(i);
}

int main()
{
    fastIO(UNTIE_IO);
    (MULT_TESTS ? use_tests : code)(0);
    return 0;
}

void fastIO(bool untie)
{
    std::ios_base::sync_with_stdio(false);
    if (untie)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
}