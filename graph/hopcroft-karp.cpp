struct Matching {
	int n;
	vector<int> matchX, matchY, dist;
	vector<vector<int>> adj;

	Matching(int n): n(n), matchX(n + 1), matchY(n + 1), dist(n + 1), adj(n + 1) {}

	void addEdge(int u, int v) {
		adj[u].push_back(v);
	}

	bool bfs() {
		queue<int> q;
		for (int u = 1; u <= n; ++u)
			if (!matchX[u]) {
				dist[u] = 0;
				q.push(u);
			} else 
				dist[u] = INF;

		dist[0] = INF;
		while (q.size()) {
			int u = q.front(); q.pop();
			for (int v: adj[u])
				if (dist[matchY[v]] == INF) {
					dist[matchY[v]] = dist[u] + 1;
					q.push(matchY[v]);
				}
		}

		return dist[0] != INF;
	}

	bool dfs(int u) {
		if (u) {
			for (int v: adj[u])
				if (dist[matchY[v]] == dist[u] + 1 && dfs(matchY[v])) {
					matchX[u] = v;
					matchY[v] = u;
					return true;
				}
			dist[u] = INF;
			return false;
		}
		return true;
	}

	int match() {
		int res = 0;
		while (bfs()) {
			for (int u = 1; u <= n; ++u)
				if (!matchX[u])
					if (dfs(u))
						res++;
		}
		return res;
	}
};