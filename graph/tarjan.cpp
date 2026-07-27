stack<int> s;

void dfs(int u) {
	num[u] = low[u] = ++timeDfs;
	s.push(u);

	for (int v: adj[u])
		if (!del[v]) {
			if (num[v] > 0)
				low[u] = min(low[u], num[v]);
			else {
				dfs(v);
				low[u] = min(low[u], low[v]);
			}
		}

	if (low[u] == num[u]) {
		ans++; int v;
		do {
			v = s.top(); s.pop();
			del[v] = true;
		} while (v != u);
	}
}