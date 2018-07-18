# include <iostream>
# include <iomanip>
# include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    size_t t;
    cin >> t;

    vector<float> outs(t);

    for(size_t i{}; i < t; ++i)
        cin >> outs[i];

    cout << setprecision(2) << fixed;
    for(size_t i{}; i < t; ++i)
        cout << 3.0 * outs[i] * outs[i] * 1.732050807568877193176604123437 / 2.0 << "\n";
}
