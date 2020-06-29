#include <bits/stdc++.h>

using namespace std;

template <typename T>
void f_cout(T val) { cout << val << endl; }
template <typename T, typename... TT>
void f_cout(T val, TT... tail) { cout << val << " : ", f_cout(tail...); }

const int64_t ARR_SIZE = (int64_t)1e5 << 1 + 1;

int64_t t, n, k, ai, bi, abi, auxa, auxb, acc, aux, it, ab_acc;
int64_t a[ARR_SIZE], b[ARR_SIZE], ab[ARR_SIZE];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    for (int i{0}; i < n; ++i)
    {
        cin >> aux >> auxa >> auxb;

        if (auxa && !auxb)
            a[ai++] = aux;
        if (!auxa && auxb)
            b[bi++] = aux;
        if (auxa && auxb)
            ab[abi++] = aux;
    }

    if (ai + abi < k || bi + abi < k)
    {
        cout << -1 << "\n";
        return 0;
    }

    sort(a, a + ai);
    sort(b, b + bi);
    sort(ab, ab + abi);

    for (int i{0}; i < k; ++i)
    {
        if (i >= ai)
            a[i] = (int64_t)1 << 33;
        a[i + 1] += a[i];
        if (i >= bi)
            b[i] = (int64_t)1 << 33;
        b[i + 1] += b[i];
        if (i >= abi)
            ab[i] = (int64_t)1 << 33;
        ab[i + 1] += ab[i];
    }

    acc = ab[k - 1], ab_acc = 0;

    for (int i{k - 1}; i >= 0; --i)
    {
        acc = min(acc, ab_acc + a[i] + b[i]);
        ab_acc = ab[k - i - 1];
    }

    cout << acc << "\n";

    return 0;
}
