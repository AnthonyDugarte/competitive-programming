// Codeforces Round #530 (Div. 2) 

#include <bits/stdc++.h>

using namespace std;

int main() {
    size_t n;

    cin >> n;

    int segs{ 2 };
    int sqrs{ 1 };

    for (size_t i{ 1 }, c{ 1 }; sqrs < n; ++i, ++segs) {
        sqrs += c;

        if (i & 1)
            ++c;
    }

    cout << segs << "\n";

    return 0;
}