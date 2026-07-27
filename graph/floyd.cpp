for (int i = 1; i <= n; ++i) {
	for (int j = i + 1; j <= n; ++j) {
		dist[i][j] = dist[j][i] = INF;
		nxt[i][j] = j; nxt[j][i] = i;
	}
	nxt[i][i] = i;
}

for (int i = 1; i <= m; ++i) {
	int u, v, c;
	cin >> u >> v >> c;
	dist[u][v] = min(dist[u][v], c);
	dist[v][u] = min(dist[v][u], c);
}

for (int k = 1; k <= n; ++k)
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (dist[i][j] > dist[i][k] + dist[k][j]) {
				dist[i][j] = dist[i][k] + dist[k][j];
				nxt[i][j] = nxt[i][k];
			}

trace u -> v: while (u != v) push(u), u = nxt[u][v]