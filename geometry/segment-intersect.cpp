int sign(double x) {
	if (x > eps) return 1;
	if (x < -eps) return -1;
	return 0;
}

bool intersect(point A, point B, point C, point D) {
	int ABxAC = sign((B - A).cross(C - A));
	int ABxAD = sign((B - A).cross(D - A));
	int CDxCA = sign((D - C).cross(A - C));
	int CDxCB = sign((D - C).cross(B - C));
	if (ABxAC == 0 || ABxAD == 0 || CDxCA == 0 || CDxCB == 0) {
		if (onSegment(A, B, C) || onSegment(A, B, D) || onSegment(C, D, A) || onSegment(C, D, B))
			return true;
		return false;
	}
	return (ABxAC * ABxAD < 0 && CDxCA * CDxCB < 0);
}