void dfs(int u) {
	st[u] = 1;
	for (int v: adj[u]) {
		if (t != 0) return;
		if (!st[v])
			par[v] = u, dfs(v);
		else if (st[v] == 1) {
			t = u;
			s = v;
			return;
		}
	}

	st[u] = 2;
}

for (int i = 1; i <= n; ++i)
	if (!st[i]) {
		dfs(i);
		if (t != 0) trace t -> s
	}