void dfs(int u, int par) {
	num[u] = low[u] = ++timeDfs;

	bool isJoint = false;
	int child = 0;

	for (int v: adj[u]) {
		if (v == par) continue;
		if (num[v])
			low[u] = min(low[u], num[v]);
		else {
			dfs(v, u);
			low[u] = min(low[u], low[v]);				

			child++;
			if (u == par && child > 1) isJoint = true;
			else if (u != par && low[v] >= num[u]) isJoint = true;

			if (num[v] == low[v]) bridges.push_back(make_pair(u, v));
		}
	}

	if (isJoint) joints.push_back(u);
}