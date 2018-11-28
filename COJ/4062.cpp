#include <iostream>
using namespace std;

int main()
{
    size_t t;
    cin >> t;

    while(--t != -1)
    {
        string s;
        cin >> s;

        if(s == "P=NP")
            cout << "skipped\n";
        else
        {
            string a;
            char operand;
            string b;

            string::iterator it { s.begin() };

            while(*it >= '0' and *it <= '9')
            {
                a.push_back(*it);
                ++it;
            }
            operand = *it;
            
            while(++it != s.end())
                b.push_back(*it);
            
            if(operand == '+')
                cout << stoi(a) + stoi(b) << "\n";
            else if(operand == '-')
                cout << stoi(a) - stoi(b) << "\n";
            else if(operand == '*')
                cout << stoi(a) * stoi(b) << "\n";
            else if(operand == '/')
                cout << stoi(a) / stoi(b) << "\n";
        }
    }

    return 0;
}