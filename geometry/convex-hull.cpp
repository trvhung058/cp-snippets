bool ccw(point A, point B, point C) {
	ld orientation = (B - A).cross(C - A);
	return orientation > 0 || abs(orientation) < eps;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> p[i].x >> p[i].y;

	sort(p + 1, p + 1 + n, [&](point A, point B){
		if (A.x != B.x) return A.x < B.x;
		return A.y < B.y;
	});

	vector<point> hullA, hullB;
	for (int i = 1; i <= n; ++i) {
		if (hullA.empty()) {
			hullA.push_back(p[i]);
			continue;
		}

		while (hullA.size() > 1 && ccw(hullA[hullA.size() - 2], hullA.back(), p[i]))
			hullA.pop_back();

		hullA.push_back(p[i]);
	}

	for (int i = n; i >= 1; --i) {
		if (hullB.empty()) {
			hullB.push_back(p[i]);
			continue;
		}

		while (hullB.size() > 1 && ccw(hullB[hullB.size() - 2], hullB.back(), p[i]))
			hullB.pop_back();

		hullB.push_back(p[i]);
	}

	for (int i = 1; i < hullB.size() - 1; ++i)
		hullA.push_back(hullB[i]);
}