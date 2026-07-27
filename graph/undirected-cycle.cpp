bool dfs(int u) {
	vis[u] = true;
	for (int v: adj[u]) 
		if (!vis[v]) {
			par[v] = u;
			if (dfs(v)) return true;
		} else if (v != par[u]) {
			s = v; t = u;
			return true;
		}
	return false;
}

for (int i = 1; i <= n; ++i)
	if (!vis[i])
		if (dfs(i))
			trace t -> s;