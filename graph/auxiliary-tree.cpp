int build_auxiliary_tree(vector<int> &vers) {
	int sz = (int) vers.size();

	sort(vers.begin(), vers.end(), [&](int A, int B){
		return ti[A] < ti[B];
	});

	for (int i = 0; i < sz - 1; ++i) {
		int lca = LCA(vers[i], vers[i + 1]);
		vers.push_back(lca);
	}

	sort(vers.begin(), vers.end(), [&](int A, int B){
		return ti[A] < ti[B];
	});

	vers.resize(unique(vers.begin(), vers.end()) - vers.begin());

	vector<int> stack;
	int aux_root = vers[0];

	stack.push_back(aux_root);
	for (int i = 1; i < (int) vers.size(); ++i) {
		int u = vers[i];
		while (!stack.empty() && !is_ancestor(stack.back(), u))
			stack.pop_back();

		assert(!stack.empty());
		int last = stack.back();
		aux_adj[last].push_back(u);
		stack.push_back(u);
	}

	return aux_root;
}