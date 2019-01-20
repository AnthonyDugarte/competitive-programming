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

    type_t n, k;
    str_t s;
    cin >> n >> k >> s;

    um_t<char, utype_t> memo;
    size_t reps { 1 };
    utype_t lvl { 0 };
    char c { s[0] };

    for (size_t i{ 1 }; i < n; ++i) {
        if (reps == k) {
            lvl = std::max(lvl, ++memo[c]);
            reps = 0;
        }

        if (s[i] == c) {
            ++reps;
        } else {
            reps = 1;
            c = s[i];
        }
    }

    if (reps == k) {
        lvl = std::max(lvl, ++memo[c]);
        reps = 0;
    }

    cout << lvl << "\n";

    return 0;
}