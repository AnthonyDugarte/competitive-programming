/*
 *
 * Copyright: Anthony Dugarte
 * Contest: Educational Codeforces Round 58 
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
using v_t = std::vector<T>;

template<typename T, typename U>
using m_t = std::map<T, U>;

using type_t = int64_t;
using utype_t = uint64_t;


void fastIO() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

utype_t t, l, r, d;


int main() {
    fastIO();
    cin >> t;

    while (--t != -1) {
        cin >> l >> r >> d;

        if (d < l || d > r) {
            cout << d << "\n";
            continue;
        }

        cout << d * (r / d + 1) << "\n";
    }

    return 0;
}
