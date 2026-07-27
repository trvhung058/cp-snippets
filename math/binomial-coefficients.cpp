const int N = 1e6 + 5;
int fac[N], ifac[N];

void precalc() {
    fac[0] = 1;
    for (int i = 1; i < maxn; ++i)
        fac[i] = 1LL * fac[i - 1] * i % MOD;

    ifac[maxn - 1] = binpow(fac[maxn - 1], MOD - 2);
    for (int i = maxn - 2; i >= 0; --i)
        ifac[i] = 1LL * ifac[i + 1] * (i + 1) % MOD;
}

int C(int n, int k) {
    if (n < k) return 0;
    return 1LL * fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}