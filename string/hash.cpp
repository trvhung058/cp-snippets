const int nMOD = 2;
const ll base = 31;
const ll mods[] = {(ll) 1e9 + 10777, (ll) 1e9 + 19777};

const int N = 1e5 + 5;
string a;
ll pw[nMOD][N], len;

void preprocess() {
	for (int j = 0; j < nMOD; ++j) {
		pw[j][0] = 1;
		for (int i = 1; i < N; ++i)
			pw[j][i] = (1ll * pw[j][i - 1] * base) % mods[j];
	}
}

struct Hash {
	ll val[nMOD];

	Hash() {
		memset(val, 0, sizeof(val));
	}

	bool operator == (const Hash &x) const {
		for (int i = 0; i < nMOD; ++i)
			if (val[i] != x.val[i])
				return false;
		return true;
	}
} hashA[N];

Hash get(ll l, ll r) {
	Hash ret;
	for (int j = 0; j < nMOD; ++j)
		ret.val[j] = (hashA[r].val[j] - hashA[l - 1].val[j] * pw[j][r - l + 1] + mods[j] * mods[j]) % mods[j];
	return ret; 
}

void solve() {
	cin >> a;

	len = a.size(); a = ' ' + a;
	for (int j = 0; j < nMOD; ++j)
		for (int i = 1; i <= len; ++i)
			hashA[i].val[j] = (hashA[i - 1].val[j] * base + a[i] - 'a' + 1) % mods[j];
}