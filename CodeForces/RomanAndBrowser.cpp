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

    int n, k, e { 0 }, s { 0 };
    cin >> n >> k;

    v_t<int> is(n);

    for (int &i : is) {
        cin >> i;
        ++(i == 1 ? e : s);
    }

    int max = 0;

    for (int i = 0; i < n; ++i) {
        int e_i { e }, s_i{ s };

        for (int jmp{ i - k }; jmp >= 0; jmp -= k)
            --(is[jmp] == 1 ? e_i : s_i);
        for (int jmp{ i }; jmp < n; jmp += k)
            --(is[jmp] == 1 ? e_i : s_i);

        max = std::max(max, std::abs(e_i - s_i));
    }

    cout << max << "\n";

    return 0;
}