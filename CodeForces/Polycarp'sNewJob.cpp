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
using m_t = std::unordered_map<T, U>;

using type_t = int64_t;
using utype_t = uint64_t;
using str_t = std::string;


void fastIO() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

using pair_t = p_t<size_t, size_t>;
size_t q;
char op;
pair_t pi;

s_t<pair_t> bills;

bool contains (const pair_t &a, const pair_t &b) {
    return
        (a.first <= b.first && a.second <= b.second) ||
        (a.second <= b.first && a.first <= b.second);
}

void add() {
    for (const pair_t &p : bills)
        if (contains(pi, p))
            return;

    bills.insert(pi);
}

void process() {
    for (const pair_t &p : bills) {
        if (!contains(p, pi)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

void solve() {
    if (op == '+')
        add();
    else
        process();
}

int main() {
    fastIO();

    cin >> q;
    while (--q != -1) {
        cin >> op >> pi.first >> pi.second;
        solve();
    }

    return 0;
}