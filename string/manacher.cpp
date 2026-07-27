const int N = 5e5 + 5;
int n, D_odd[N], D_even[N];
string s;

void calcManacher() {
	int L = 1, R = 0;
	for (int i = 1; i <= n; ++i) {
		if (i > R) D_odd[i] = 0;
		else D_odd[i] = min(R - i, D_odd[L + R - i]);

		while (i - D_odd[i] - 1 > 0 && i + D_odd[i] + 1 <= n && s[i - D_odd[i] - 1] == s[i + D_odd[i] + 1])
			D_odd[i]++;

		if (i + D_odd[i] > R) {
			R = i + D_odd[i];
			L = i - D_odd[i];
		}
	}

	L = 1, R = 0;
	for (int i = 1; i < n; ++i) {
		int j = i + 1;
		if (j > R) D_even[i] = 0;
		else D_even[i] = min(R - j + 1, D_even[L + R - j]);

		while (i - D_even[i] > 0 && j + D_even[i] <= n && s[i - D_even[i]] == s[j + D_even[i]])
			D_even[i]++;

		if (i + D_even[i] > R) {
			R = i + D_even[i];
			L = j - D_even[i];
		}
	}
}

void solve() {
	cin >> s;

	n = (int) s.size(); s = ' ' + s;

	calcManacher();

	for (int i = 1; i < n; ++i)
		cout << D_odd[i] * 2 + 1 << ' ' << D_even[i] * 2 << ' ';
	cout << D_odd[n] * 2 + 1;
}