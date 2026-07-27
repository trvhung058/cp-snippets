void dfs(int u) {
	sz[u] = 1;
	for (int v: adj[u]) {
		if (v == par[u]) continue;
		par[v] = u; h[v] = h[u] + 1;
		dfs(v);
		sz[u] += sz[v];
	}
}

void hld(int u) {
	if (!chainHead[curChain]) chainHead[curChain] = u;
	pos[u] = curPos; chainID[u] = curChain; arr[curPos++] = u;

	int nxt = 0;
	for (int v: adj[u])
		if (v != par[u] && sz[v] > sz[nxt])
			nxt = v;

	if (nxt) hld(nxt);
	for (int v: adj[u])
		if (v != par[u] && v != nxt) {
			curChain++;
			hld(v);
		}
}

int LCA(int u, int v) {
	while (chainID[u] != chainID[v])
		if (chainID[u] > chainID[v])
			u = par[chainHead[chainID[u]]];
		else 
			v = par[chainHead[chainID[v]]];
	return h[u] < h[v] ? u : v;
}