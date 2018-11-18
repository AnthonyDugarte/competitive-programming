#include<bits/stdc++.h>
using namespace std;

int main()
{   
    string op;
    op.resize(2);

    int X{ 0 };

    while(getline(cin, op, ';'))
    {
        if(op == "++X" or op == "X++")
            ++X;
        else if(op == "--X" or op == "X--")
            --X;
    }

    cout << X << "\n";

    return 0;
}