struct TWO_SAT {
    int n;
    vector<vector<int>> g, gr; 
    vector<int> comp, topo, ans; 
    vector<bool> vis;

    TWO_SAT () {}

    TWO_SAT (int _n) : n(_n), g(2 * n + 1), gr(2 * n + 1), comp(2 * n + 1), vis(2 * n + 1), ans(2 * n + 1) {}

    void add_edge(int u, int v) {
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    void add_or(int i, bool f, int j, bool g) {
        add_edge(i + (f ? n : 0), j + (g ? 0 : n));
        add_edge(j + (g ? n : 0), i + (f ? 0 : n));
    }

    void add_xor(int i, bool f, int j, bool g) {
        add_or(i, f, j, g);
        add_or(i, !f, j, !g);
    }

    void add_and(int i, bool f, int j, bool g) {
        add_xor(i, !f, j, g);
    }

    void dfs(int u) {
        vis[u] = true;

        for (const auto &v : g[u])
            if (!vis[v]) dfs(v);

        topo.push_back(u);
    }

    void scc(int u, int id) {
        vis[u] = true;
        comp[u] = id;

        for (const auto &v : gr[u])
            if (!vis[v]) scc(v, id);
    }

    bool check() {
        fill(vis.begin(), vis.end(), false);

        for (int i = 1; i <= 2 * n; i++)
            if (!vis[i]) 
                dfs(i);

        fill(vis.begin(), vis.end(), false);
        reverse(topo.begin(), topo.end());

        int id = 0;
        for (const auto &v : topo)
            if (!vis[v]) 
                scc(v, id++);

        for (int i = 1; i <= n; i++){
            if (comp[i] == comp[i + n]) 
                return false;

            ans[i] = (comp[i] > comp[i + n] ? 1 : 0);
        }

        return true;
    }
};