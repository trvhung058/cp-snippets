const int N = 1e6 + 5;
vector<int> prime;
bool is_prime[N];

void sieve(int n) {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) prime.push_back(i);
        for (int p: prime) {
            if (i * p > n) break;
            is_prime[i * p] = false;
            if (i % p == 0) break;
        }
    }
}