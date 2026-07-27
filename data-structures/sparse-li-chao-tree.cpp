struct line {
	ll a, b;
	line(ll a = 0, ll b = 0) : a(a), b(b) {}
	ll calc(ll x) {
		return a * x + b;
	}
};

struct LichaoTree {
	line tr;
	LichaoTree *L, *R;
	int l, r;

	LichaoTree(int l = 0, int r = 0) : tr(0, LLONG_MIN), L(nullptr), R(nullptr), l(l), r(r) {}

	void update(line f) {
		if (l == r) {
			tr = (f.calc(l) > tr.calc(l) ? f : tr);
			return;
		}

		int mid = (l + r) >> 1;

		if (f.calc(mid) > tr.calc(mid)) swap(tr, f);

		if (f.a < tr.a) {
			if (L == nullptr) L = new LichaoTree(l, mid);
			L -> update(f);
		}

		if (f.a > tr.a) {
			if (R == nullptr) R = new LichaoTree(mid + 1, r);
			R -> update(f);
		}
	}

	ll query(int pos) {
		ll cur = tr.calc(pos);
		int mid = (l + r) >> 1;
		if (l == r) return cur;

		if (pos <= mid)
			return max(cur, L == nullptr ? LLONG_MIN : L -> query(pos));
		else 
			return max(cur, R == nullptr ? LLONG_MIN : R -> query(pos));
	}
};