int countDiv(int n) {
    if (n == 1) return 1;
    vector<int> powV;

    int lastDiv = 0, cnt = 0;
    while (n != 1) {
        if (minPrime[n] != lastDiv) {
            if (cnt) powV.push_back(cnt);
            cnt = 0;
        }
        ++cnt;
        lastDiv = minPrime[n];
        n /= minPrime[n];
    }

    if (cnt) powV.push_back(cnt);
    int res = 1;
    for (int x: powV) res *= (x + 1);

    return res;
}