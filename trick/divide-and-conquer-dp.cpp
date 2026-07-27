// Required: opt(i, j) <= opt(i, j + 1)
// Property: C(a, c) + C(b, d) <= C(a, d) + C(b, c), with a < b <= c < d

void compute(int l, int r, int optl, int optr) {
    if (l > r) return;

    int mid = (l + r) >> 1;
    pair<int, int> best = {INT_MAX, -1};

    for (int k = optl; k <= min(mid, optr); ++k) 
        best = min(best, {dp_before[k] + C(k, mid), k});

    dp_cur[mid] = best.first;
    int opt = best.second;

    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}