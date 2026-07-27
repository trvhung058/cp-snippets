void dfs(int u, int p, bool keep) {
	int mx = -1, bigChild = -1;
	for (int v: adj[u])
		if (v != p && sz[v] > mx)
			mx = sz[v], bigChild = v;

	for (int v: adj[u])
		if (v != p && v != bigChild)
			dfs(v, u, 0);

	if (bigChild != -1) dfs(bigChild, u, 1), swap(vec[u], vec[bigChild]);
	vec[u].push_back(u); cnt[col[u]]++;

	for (int v: adj[u])
		if (v != p && v != bigChild)
			for (auto x: vec[v]) {
				vec[u].push_back(x);
				cnt[col[x]]++;
			}

	// answer queries at u

	if (!keep)
		for (auto x: vec[u])
			cnt[col[x]]--;
}