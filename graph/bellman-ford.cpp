void BellmanFord() {
	fill(D + 1, D + 1 + n, -LINF); D[1] = 0;
	for (int T = 1; T < n; ++T)
		for (auto E: edges) {
			int u = E.S.F, v = E.S.S, w = E.F;
			if (D[u] != -LINF && D[v] < D[u] + w)
				D[v] = D[u] + w;
		}

	for (int T = 1; T <= n; ++T)
		for (auto E: edges) {
			int u = E.S.F, v = E.S.S, w = E.F;
			if (D[u] != -LINF && D[v] < D[u] + w) 
				D[v] = LINF;
		}
}