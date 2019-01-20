/*
 * Codeforces Round #532 (Div. 2) 
 * Copyright: Anthony Dugarte
 * 
 */

#include <bits/stdc++.h>

using std::cin;
using std::cout;

template<typename T, typename U>
using p_t = std::pair<T, U>;

template<typename T>
using s_t = std::set<T>;
template<typename T>
using us_t = std::unordered_set<T>;

template<typename T>
using v_t = std::vector<T>;

template<typename T, typename U>
using m_t = std::map<T, U>;
template<typename T, typename U>
using um_t = std::unordered_map<T, U>;

using type_t = int64_t;
using utype_t = uint64_t;
using str_t = std::string;

void fastIO() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

size_t n, m;

int i, curr{ 1 }, counter{ 0 };
v_t<int> tests;

int solve() {
    if (n == 1)
        return 1;

    if (++tests[i] == curr)
        ++counter;

    if (counter == n) {
        ++curr;
        counter = 0;
        for (int & v : tests) {
            if (v >= curr)
                ++counter;
        }

        return 1;
    }

    return 0;
}

int main() {
    fastIO();

    cin >> n >> m;
    tests = v_t<int>(n + 1, 0);

    while (--m != -1) {
        cin >> i;
        cout << solve();
    }

    cout << "\n";
    return 0;
}
