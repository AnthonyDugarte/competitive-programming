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

constexpr type_t m_val{ static_cast<type_t>(1e9 + 7) };

void fastIO() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

v_t<type_t> vals(3);
v_t<type_t> res;

type_t mul(type_t res_i, type_t vals_i) {
    return (res[res_i] * vals[vals_i]) % m_val;
}

int main() {
    // fastIO();

    type_t n, l, r;
    cin >> n >> l >> r;


    type_t reps{ (r - l) / 3 };
    type_t diff{ reps * 3 };

    for (size_t i { 0 }, tmp_l { l }; i < 3; ++i, ++tmp_l)
        vals[tmp_l % 3] = 1 + reps - (tmp_l + diff > r ? 1 : 0);
    res = vals;

    for (size_t i{ 1 }; i < n; ++i) {
        v_t<type_t> temp_res(3);

        temp_res[0] = (mul(0, 0) + mul(1, 2) + mul(2, 1)) % m_val;
        temp_res[1] = (mul(0, 1) + mul(1, 0) + mul(2, 2)) % m_val;
        temp_res[2] = (mul(0, 2) + mul(2, 0) + mul(1, 1)) % m_val;

        res = temp_res;
    }

    cout << res[0] << "\n";

    return 0;
}



/*
int main() {
    // fastIO();

    size_t n, l, r;
    cin >> n >> l >> r;

    v_t<size_t> vals(3);

    size_t d{ (r - l) / 3 };
    size_t tmp{ d * 3 };

    for (size_t i { 0 }; i < 3; ++i)
        vals[(l + i) % 3] = 1 + ((r - (l + i)) / 3);

    for (size_t i { 0 }; i < 3; ++i) {
        cout << vals[i] << " ";
    }
    cout << "\n";

    // for (size_t i{ 0 }; i < n; ++i) {
        //
    // }

    return 0;
}
*/