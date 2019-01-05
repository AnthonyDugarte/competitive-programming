// Codeforces Round #530 (Div. 2) 
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    size_t k;

    cin >> s >> k;

    size_t s_size{ 0 };

    vector<pair<size_t, bool>> tools;
    bool snowflake{ false };

    for (size_t i{ 0 }; i < s.size(); ++i) {
        if (s[i] == '*' || s[i] == '?') {
            tools.push_back({i, s[i] == '*'});

            if (s[i] == '*')
                snowflake = true;
        } else {
            ++s_size;
        }
    }


    if (s_size - tools.size() > k || !snowflake && s_size < k) {
        cout << "Impossible\n";
        return 0;
    }

    if (tools.size() == 0) {
        cout << s << "\n";
        return 0;
    }

    for (size_t i{ 0 }, t_i{ 0 }; i < s.size(); ++i) {
        if (s[i] == '*' || s[i] == '?')
            continue;

        if (s_size == k || t_i >= tools.size() || i != tools[t_i].first - 1) {
            cout << s[i];
        } else if (k < s_size) {
                --s_size;
                ++t_i;
        } else if (k > s_size && tools[t_i].second) {
            cout << string(k - s_size + 1, s[i]);
            s_size += k - s_size;
            ++t_i;
        } else {
            ++t_i;
            cout << s[i];
        }
    }

    cout << "\n";

    return 0;
}