# include <bits/stdc++.h>

using namespace std;

template<typename T>
using m_t = vector<vector<T>>;
int R, C;

int best_fun(const m_t<int> &matrix, m_t<bool> &matrix_checks, int x, int y, int best, int current, int prev)
{
	if((x == R or x == -1) or (y == C or y == -1) or matrix_checks[x][y] or matrix[x][y] >= prev)
 		return max(current, best);

	matrix_checks[x][y] = true;

	++current;

	int current_left = best_fun(matrix, matrix_checks, x, y - 1, max(best, current), current, matrix[x][y]);
	int current_right = best_fun(matrix, matrix_checks, x, y + 1, current_left, current, matrix[x][y]);
	int current_up = best_fun(matrix, matrix_checks, x - 1, y, current_right, current, matrix[x][y]);
	int current_down = best_fun(matrix, matrix_checks, x + 1, y, current_up, current, matrix[x][y]);
	
	matrix_checks[x][y] = false;
	
	return current_down;
}

int main()
{
	size_t N;
	cin >> N;

	while(--N != -1)
	{
		string name;
		cin >> name >> R >> C;
		
		m_t<int> matrix(R, vector<int>(C));
		m_t<bool> matrix_checks(R, vector<bool>(C, false));
		int best = 0;

		for(auto &v : matrix)
			for(auto &value : v)
				cin >> value;
		
		int best_val { 0 };

		for(size_t i{ 0 }; i < R; ++i)
			for(size_t j { 0 }; j < C; ++j)
				best_val = max(best_val, best_fun(matrix, matrix_checks, i, j, best_val, 0, numeric_limits<int>::max()));
		cout << name << ": " << best_val << endl;
	}
	return 0;
}