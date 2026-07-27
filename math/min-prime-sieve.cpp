const int N = 1e6 + 5;
int minPrime[N];

void sieveMinPrime(int n) {
    for (int i = 2; i <= n; ++i) {
        if (minPrime[i]) continue;
        minPrime[i] = i;
        for (int j = i + i; j <= n; j += i)
            minPrime[j] = i;
    }
}