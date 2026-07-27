vector<vector<int>> ident(int n) {
    vector<vector<int>> res;
    res.resize(n);
    for (int i = 0; i < n; ++i)
        res[i].resize(n);

    int i = n;
    while (i > 0) {
        i--;
        res[i][i] = 1;
    }

    return res;
}

vector<vector<int>> mul(vector<vector<int>> &a, vector<vector<int>> &b) {
    vector<vector<int>> res;
    res.resize(a.size());
    for (int i = 0; i < res.size(); ++i)
        res[i].resize(b[0].size());

    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < b[0].size(); ++j)
            for (int k = 0; k < a[0].size(); ++k)
                res[i][j] = (1LL * res[i][j] + 1LL * a[i][k] * b[k][j] % MOD) % MOD;

    return res;
}   

vector<vector<int>> pw(vector<vector<int>> &a, long long exp) {
    vector<vector<int>> base = a;
    vector<vector<int>> res = ident(a.size());
    for (; exp > 0; exp >>= 1, base = mul(base, base))
        if (exp & 1)
            res = mul(res, base);
    return res;
}