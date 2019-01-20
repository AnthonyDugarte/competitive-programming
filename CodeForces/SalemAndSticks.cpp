/*
 * Codeforces Round #533 (Div. 2)
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

int main() {
    fastIO();

    size_t n;
    cin >> n;

    v_t<int> v(n);
    int l{ 1 }, r{ 100 };

    for (int &i : v) {
        cin >> i;
        l = std::min(i, l);
        r = std::max(i, r);
    }

    int best{ std::numeric_limits<int>::max() };
    int val { -1 };

    while (l <= r) {
        int tmp_b { 0 };
        for (size_t i{ 0 }; i < n; ++i) {
            if (v[i] != l)
                tmp_b += std::abs(v[i] - l) - 1;
        }

        if (tmp_b < best) {
            val = l;
            best = tmp_b;
        }
        ++l;
    }

    cout << val << " " << best << "\n";


    return 0;
}