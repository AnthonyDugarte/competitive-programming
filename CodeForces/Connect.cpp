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

constexpr char endl = '\n',
               land = '0',
               water = '1',
               null_c = '2';

constexpr type_t module{static_cast<type_t>(1e9 + 7)};

type_t n;
type_t x1, y11, x2, y2;
v_t<v_t<char>> world;
v_t<v_t<char>> sec_world;

v_t<p_t<type_t, type_t>> alice;
v_t<p_t<type_t, type_t>> target;

void getAliceLand(type_t x, type_t y)
{
    if (x == -1 || y == -1 || x == n || y == n)
        return;
    if (world[x][y] == water || sec_world[x][y] != null_c)
        return;

    sec_world[x][y] = world[x][y];
    alice.push_back({x, y});

    getAliceLand(x - 1, y);
    getAliceLand(x + 1, y);
    getAliceLand(x, y - 1);
    getAliceLand(x, y + 1);
}

void getTargetLand(type_t x, type_t y)
{
    if (x == -1 || y == -1 || x == n || y == n)
        return;
    if (world[x][y] == water || sec_world[x][y] != null_c)
        return;

    sec_world[x][y] = world[x][y];
    target.push_back({x, y});

    getTargetLand(x - 1, y);
    getTargetLand(x + 1, y);
    getTargetLand(x, y - 1);
    getTargetLand(x, y + 1);
}

int main()
{
    fastIO(/* false */);

    cin >> n >> x1 >> y11 >> x2 >> y2;

    world = v_t<v_t<char>>(n, v_t<char>(n));
    sec_world = v_t<v_t<char>>(n, v_t<char>(n, null_c));

    for (v_t<char> &x : world)
        for (char &y : x)
            cin >> y;

    --x1, --y11, --x2, --y2;
    getAliceLand(x1, y11);

    if (sec_world[x2][y2] != null_c)
    {
        cout << 0 << endl;
        return 0;
    }

    getTargetLand(x2, y2);

    type_t best{max_val<type_t>()};

    for (type_t i{0}; i < alice.size(); ++i)
        for (type_t j{0}; j < target.size(); ++j)
            best = std::min(best,
                            (alice[i].first - target[j].first) * (alice[i].first - target[j].first) + (alice[i].second - target[j].second) * (alice[i].second - target[j].second));

    cout << best << endl;
    return 0;
}