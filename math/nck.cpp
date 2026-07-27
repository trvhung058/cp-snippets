const int N = 5e3 + 5;
ll ncr[N][N];

void precalc() {
    for (int i = 0; i < N; ++i) {
        ncr[i][0] = ncr[i][i] = 1;
        for (int j = 1; j <= i / 2; ++j)
            ncr[i][j] = ncr[i][i - j] = 1LL * ncr[i - 1][j] + ncr[i - 1][j - 1];
    }
}