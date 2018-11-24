#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int B, N, employees_power{ 0 }, counter{ -1 };
    cin >> B >> N;
    vector<int> employees(N);

    for(int & e : employees)
    {
        cin >> e;
        employees_power += e;
    }

    sort(employees.begin(), employees.end(), greater<int>());

    while(employees_power >= B)
    {
        B += employees[++counter];
        employees_power -= employees[counter];
    }
    cout << counter + 2 << "\n";

    return 0;
}