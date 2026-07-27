#include <bits/stdc++.h>
// #include <ext/rope>
// #include <ext/pb_ds/assoc_container.hpp>

// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
using namespace std;

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

//-----------------------
// #define   ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define            ll long long
#define           ull unsigned long long
#define            db double
#define            ld long double
#define            pb push_back
#define            pf push_front
#define            mp make_pair
#define      mem(f,x) memset(f, x, sizeof(f))
#define   __lcm(a, b) (1ll * a * b) / __gcd(a, b)
#define  bit(mask, i) ((mask >> i) & 1)
#define           pii pair<int, int>
#define           pll pair<ll, ll>
#define            el '\n'
#define             F first
#define             S second
#define         io(x) freopen(x".inp","r",stdin),freopen(x".out","w",stdout)

template <class X, class Y> bool maximize(X &x, const Y &y) { return (x < y ? x = y, 1 : 0); }
template <class X, class Y> bool minimize(X &x, const Y &y) { return (x > y ? x = y, 1 : 0); }

//-----------------------
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const int MULTI = 0;
const ld eps = 1e-9;
const int dx[4]{0, 1, 0, -1}, dy[4]{1, 0, -1, 0}; // R D L U
const int ddx[4]{-1, 1, 1, -1}, ddy[4]{1, 1, -1, -1}; // UR DR DL UL
const char cx[4]{'R', 'D', 'L', 'U'};
const ll base = 31;
const int nMOD = 2;
const ll mods[] = {(ll)1e9 + 10777, (ll)1e9 + 19777, (ll)1e9 + 3, (ll)1e9 + 3777};

const int maxn = 1e5 + 5;
int n, m, q, ans[2 * maxn];

struct dsu {

	vector<int> root, sz;
	vector<pair<int &, int>> history;

	dsu(int n) : root(n), sz(n, 1) { iota(root.begin(), root.end(), 0); }

	int find(int x) {
		return (root[x] == x) ? x : find(root[x]);
	}

	void unite(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return;
		if (sz[u] < sz[v]) swap(u, v);

		history.pb({root[v], root[v]});
		history.pb({sz[u], sz[u]});

		root[v] = u; sz[u] += sz[v];
	}	

	int snapshot() {
		return history.size();
	}

	void rollback(int until) {
		while (snapshot() > until) {
			history.back().F = history.back().S;
			history.pop_back();
		}
	} 

} dsu(maxn);

struct Query {
	int t, u, v;
};

vector<Query> st[4 * maxn];

void update(Query &q, int id, int l, int r, int u, int v) {
	if (l == u && r == v) {
		st[id].pb(q);
		return;
	}

	int mid = (l + r) >> 1;
	if (v <= mid) update(q, id << 1, l, mid, u, v);
	else if (u > mid) update(q, id << 1 | 1, mid + 1, r, u, v);
	else {
		update(q, id << 1, l, mid, u, mid);
		update(q, id << 1 | 1, mid + 1, r, mid + 1, v);
	}
}

int cnt = 0;

void dfs(int id, int l, int r) {
	int snapshot = dsu.snapshot();

	for (Query &q: st[id])
		if (q.t == 1)
			dsu.unite(q.u, q.v);

	if (l == r) {
		for (Query &q: st[id])
			if (q.t == 2) 
				ans[l] = dsu.find(q.u) == dsu.find(q.v);
	} else {
		int mid = (l + r) >> 1;
		dfs(id << 1, l, mid);
		dfs(id << 1 | 1, mid + 1, r);
	}

	dsu.rollback(snapshot);
}

void solve() {
	cin >> n >> m >> q;

	map<pair<int, int>, int> index_added; 
	
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;

		u--; v--;
		if (u > v) swap(u, v);
		index_added[make_pair(u, v)] = i;
	}

	for (int i = 0; i < q; ++i) {
		string type; int u, v;
		cin >> type >> u >> v;

		u--; v--;
		if (u > v) swap(u, v);
		if (type[0] == 'A' && type[1] == 'd') index_added[make_pair(u, v)] = m + i;
		else if (type[0] == 'R') {

			Query cur_q = {1, u, v};
			update(cur_q, 1, 0, m + q - 1, index_added[make_pair(u, v)], m + i - 1);
			index_added[make_pair(u, v)] = -1; 
		
		} else {

			Query cur_q = {2, u, v};
			update(cur_q, 1, 0, m + q - 1, m + i, m + i);

		}
	}

	for (auto Q: index_added)
		if (Q.S != -1) {
			Query cur_q = {1, Q.F.F, Q.F.S};
			update(cur_q, 1, 0, m + q - 1, Q.S, m + q - 1);
		}

	fill(ans, ans + m + q, -1); dfs(1, 0, m + q - 1);
	for (int i = 0; i < q; ++i)
		if (ans[m + i] != -1)
			cout << (ans[m + i] ? "YES" : "NO") << el;
} 

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif

    if (!MULTI) solve();
    else {
        int test; cin >> test;
        while (test--) solve();
    }
    
    return 0;
}


