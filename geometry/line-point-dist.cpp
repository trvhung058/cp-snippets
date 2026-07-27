ld linePointDist(const point &A, const point &B, const point &C, bool isSegment) {
	ld dist = abs((B - A).cross(C - A)) / (A - B).length();
	if (isSegment) {
		ld dot1 = (A - B).dot(C - B);
		if (dot1 < 0) return (B - C).length();
		ld dot2 = (B - A).dot(C - A);
		if (dot2 < 0) return (A - C).length();
	}
	return dist;
}