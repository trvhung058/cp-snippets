int S = sqrt(n);
bool cmp(query A, query B) {
    if (A.l / S != B.l / S) return A.l / S < B.l / S;
    return A.r < B.r;
}