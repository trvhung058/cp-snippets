const int gssMod = 3;
bool gauss(vector<vector<int>> A, vector<int> &ans) {
	int n = (int) A.size(), m = (int) A[0].size() - 1;

	vector<int> p(m, -1);
	for (int row = 0, col = 0; row < n && col < m; ++col) {
		for (int i = row; i < n; ++i) {
			if (A[i][col]) {
				swap(A[row], A[i]);
				break;
			}
		}

		if (!A[row][col]) continue;

		p[col] = row;

		for (int i = 0; i < n; ++i) {
			if (i == row) continue;

			int c = (A[i][col] * A[row][col]) % gssMod;
			for (int j = col; j <= m; ++j) {
				A[i][j] -= (A[row][j] * c) % gssMod;
				if (A[i][j] < 0) A[i][j] += gssMod;
			}
		}

		row++;
	}

	ans.assign(m, 0);
	for (int i = 0; i < m; ++i)
		if (p[i] != -1)
			ans[i] = (A[p[i]][m] * A[p[i]][i]) % gssMod;

	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = 0; j < m; ++j)
			sum = (sum + ans[j] * A[i][j]) % gssMod;

		if (sum != A[i][m])
			return false;
	}

	return true;
}