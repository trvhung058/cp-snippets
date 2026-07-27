// LOG = log of 2 * n
int ti[N], et[2 * N], h[N], timeDfs = 1;
pair<int, int> st[LOG + 1][2 * N];

void dfs(int u, int p) {
	ti[u] = timeDfs;
	et[timeDfs++] = u;
	for (int v: adj[u])
		if (v != p) {
			h[v] = h[u] + 1;
			dfs(v, u);
			et[timeDfs++] = u;
		}
}

void preprocess() {
	for (int i = 1; i <= 2 * n; ++i) st[0][i] = make_pair(h[et[i]], et[i]);
	for (int j = 1; j <= LOG; ++j)
		for (int i = 1; i + (1 << j) - 1 <= 2 * n; ++i)
			st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}

pair<int, int> query(int l, int r) {
	int k = __lg(r - l + 1);
	return min(st[k][l], st[k][r - (1 << k) + 1]);
}

int lca(int u, int v) {
	if (ti[u] > ti[v]) swap(u, v);
	return query(ti[u], ti[v]).S;
}