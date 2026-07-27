// n choose r, with mini mod
int lucas(int n, int r) {
  if (r > n) return 0;
  if (n < mod) return ncr(n, r);
  return 1LL * lucas(n / mod, r / mod) * lucas(n % mod, r % mod) % mod;
}