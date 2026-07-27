struct vec {
	ld x, y;

	vec(ld _x = 0, ld _y = 0) : x(_x), y(_y) {}

	ld dot(const vec &other) {
		return x * other.x + y * other.y;
	}

	ld cross(const vec &other) {
		return x * other.y - y * other.x;
	}

	ld length() const {
		return sqrt(x * x + y * y);
	}
};

using point = vec;
vec operator - (const point &B, const point &A) {
	return vec(B.x - A.x, B.y - A.y);
}