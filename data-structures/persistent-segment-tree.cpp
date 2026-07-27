#include <bits/stdc++.h>
// #include <ext/rope>
// #include <ext/pb_ds/assoc_container.hpp>

// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
using namespace std;

// #define   ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define            ll long long
#define           ull unsigned long long
#define            ld long double
#define            pb push_back
#define  bit(mask, i) ((mask >> i) & 1)
#define            el '\n'
#define             F first
#define             S second

template <class X, class Y> bool maximize(X &x, const Y &y) { return (x < y ? x = y, 1 : 0); }
template <class X, class Y> bool minimize(X &x, const Y &y) { return (x > y ? x = y, 1 : 0); }

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const int MULTI = 0;
const ld eps = 1e-9;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}; // R D L U
const int ddx[4] = {-1, 1, 1, -1}, ddy[4] = {1, 1, -1, -1}; // UR DR DL UL
const char cx[4] = {'R', 'D', 'L', 'U'};
const ll base = 31;
const int nMOD = 2;
const ll mods[] = {(ll)1e9 + 10777, (ll)1e9 + 19777, (ll)1e9 + 3, (ll)1e9 + 3777};

const int N = 5e5 + 5;
int n, m, a[N], pre[N], root[N], curNode;

void compress_value() {
	vector<int> comp;
	for (int i = 1; i <= n; ++i)
		comp.push_back(a[i]);

	sort(comp.begin(), comp.end());
	comp.resize(unique(comp.begin(), comp.end()) - comp.begin());

	for (int i = 1; i <= n; ++i)
		a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin() + 1;
}

struct node {
	int left, right, val;
	node() : left(-1), right(-1), val(INF) {}
} st[19000000];

struct PersistentIT {
	int build(int l, int r) {
		if (l == r) {
			int cur = ++curNode;
			return cur;
		}

		int mid = (l + r) >> 1;
		int cur = ++curNode;

		st[cur].left = build(l, mid);
		st[cur].right = build(mid + 1, r);

		return cur;
	}

	int update(int id, int l, int r, int u, int v) {
		if (l == r) {
			int cur = ++curNode;
			st[cur] = st[id];
			st[cur].val = v;
			return cur;
		}

		int cur = ++curNode;
		st[cur] = st[id];

		int mid = (l + r) >> 1;

		if (u <= mid)
			st[cur].left = update(st[cur].left, l, mid, u, v);
		else
			st[cur].right = update(st[cur].right, mid + 1, r, u, v);

		st[cur].val = min(st[st[cur].left].val, st[st[cur].right].val);
		return cur;
	}

	int get(int id, int l, int r, int u, int v) {
		if (l == u && r == v) return st[id].val;

		int mid = (l + r) >> 1;

		if (v <= mid) return get(st[id].left, l, mid, u, v);
		else if (u > mid) return get(st[id].right, mid + 1, r, u, v);
		else return min(get(st[id].left, l, mid, u, mid), get(st[id].right, mid + 1, r, mid + 1, v));
	}
} IT;

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	compress_value();

	root[0] = IT.build(1, n);
	for (int i = 1; i <= n; ++i) {
		if (pre[a[i]] > 0)
			root[i] = IT.update(root[i - 1], 1, n, pre[a[i]], i - pre[a[i]]);
		else
			root[i] = root[i - 1];

		pre[a[i]] = i;
	}

	while (m--) {
		int l, r;
		cin >> l >> r;

		int get = IT.get(root[r], 1, n, l, r);
		cout << (get == INF ? -1 : get) << '\n';
	}
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