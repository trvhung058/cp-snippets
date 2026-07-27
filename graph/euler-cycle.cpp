pair<list<int>, list<int>> euler_walk(int u) {
    vis[u] = true;

    list<int> ans, ids;
    ans.push_back(u);

    while (!adj[u].empty()) {
        int v = adj[u].back().target;
        int eid = adj[u].back().id;
        vis[v] = true;

        adj[u].pop_back();

        if (used_edge[eid]) continue;
        used_edge[eid] = true;

        u = v;
        ans.push_back(u);
        ids.push_back(eid);
    }

    auto jt = ids.begin(); jt++;
    for (auto it = ++ans.begin(); it != ans.end(); ++it, ++jt) {
        auto t = euler_walk(*it);

        t.F.pop_back();

        ans.splice(it, t.F);
        ids.splice(jt, t.S);
    }

    return make_pair(ans, ids);
}