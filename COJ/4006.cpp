#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> frenchNumbers{
        "un",
        "deux",
        "trois",
        "quatre",
        "cinq",
        "six",
        "sept",
        "huit",
        "neuf",
        "dix",
        "onze",
        "douze",
        "treize",
        "quatorze",
        "quinze",
        "seize",
        "dix-sept",
        "dix-huit",
        "dix-neuf",
        "vingt"
    };


    size_t M;
    cin >> M;

    while(--M != -1)
    {
        size_t N;
        cin >> N;
        cout << frenchNumbers[N - 1] << endl;
    }


    return 0;
}