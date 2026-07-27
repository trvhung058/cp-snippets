struct Segment {
	point A, B;
} S[maxn];

bool checkPerpendicular(Segment X, Segment Y) {
	vec L1 = X.B - X.A, L2 = Y.B - Y.A;
	return L1.dot(L2) == 0;
}

bool checkParallel(Segment X, Segment Y) {
	ll A1 = X.B.y - X.A.y, B1 = X.A.x - X.B.x;
	ll A2 = Y.B.y - Y.A.y, B2 = Y.A.x - Y.B.x;
	return A1 * B2 == A2 * B1;
}