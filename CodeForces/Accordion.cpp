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
using str_t = std::string;


void fastIO() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

str_t s;

int main() {
    fastIO();

    cin >> s;

    type_t op_l{ -1 }, op_r{ -1 }, col_l{ -1 }, col_r{ -1 };

    for (size_t i{ 0 }, e{ s.size() - 1 }; i <= e; ++i) {
        if (op_l == -1) {
            if (s[i] == '[')
                op_l = i;
        } else if (col_l == -1) {
            if (s[i] == ':')
                col_l = i;
        }

        if (op_r == -1) {
            if (s[e - i] == ']')
                op_r = e - i;
        } else if (col_r == -1) {
            if (s[e - i] == ':')
                col_r = e - i;
        }

        if (col_r != -1 && col_l != -1)
            break;
    }

    if (col_l == -1 || col_r == -1 || col_l >= col_r) {
        cout << "-1\n";
        return 0;
    }

    size_t count{ 4 };

    while (++col_l != col_r)
        if (s[col_l] == '|')
            ++count;

    cout << count << "\n";
    return 0;
}