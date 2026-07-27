void countChild(int u, int par) {
	sz[u] = 1;
	for (int v: adj[u])
		if (v != par && !del[v]) {
			countChild(v, u);
			sz[u] += sz[v];
		}
}

int centroid(int u, int par, int n) {
	for (int v: adj[u]) {
		if (v == par || sz[v] <= n / 2 || del[v]) continue;
		return centroid(v, u, n);
	}
	return u;
}

long long solve(int u) {
	countChild(u, 0);

	int n = sz[u];
	int root = centroid(u, 0, n);

	updateAns(root, n);

	ans = 0; del[root] = 1;
	for (int v: adj[root])
		if (!del[v])
			ans += solve(v);

	return ans;
}