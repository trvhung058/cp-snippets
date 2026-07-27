// Required: opt(i, j - 1) <= opt(i, j) <= opt(i + 1, j)
// Property: C(b, c) <= C(a, d)
//           C(a, c) + C(b, d) <= C(a, d) + C(b, c) with a <= b <= c <= d

auto C = [&](int i, int j) {
    ... // Implement cost function C.
};

for (int i = 1; i <= N; i++) {
    opt[i][i] = i;
    ... // Initialize dp[i][i] according to the problem
}

for (int i = N - 1; i >= 1; i--) {
    for (int j = i + 1; j <= N; j++) {
        int mn = INT_MAX;
        int cost = C(i, j);
        for (int k = opt[i][j-1]; k <= min(j-1, opt[i+1][j]); k++) {
            if (mn >= dp[i][k] + dp[k+1][j] + cost) {
                opt[i][j] = k; 
                mn = dp[i][k] + dp[k+1][j] + cost; 
            }
        }
        dp[i][j] = mn; 
    }
}