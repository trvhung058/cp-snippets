struct node {
    vector<int> vec;
    vector<int> freq = {0};
    int idLeft, idRight;
} st[4 * N];

void build(int id, int l, int r) {
    if (l == r) return;

    int mid = (l + r) >> 1;
    vector<int> left, right;

    for (int x: st[id].vec)
        if (x <= mid) {
            left.push_back(x);
            st[id].freq.push_back(st[id].freq.back() + 1);
        } else {
            right.push_back(x);
            st[id].freq.push_back(st[id].freq.back());
        }

    st[id].idLeft = ++curId;
    st[curId].vec = left;
    build(curId, l, mid);

    st[id].idRight = ++curId;
    st[curId].vec = right;
    build(curId, mid + 1, r);
}

int kOrLess(int id, int l, int r, int u, int v, int k) {
    if (u > v || k < l) return 0;
    if (r <= k) return v - u + 1;

    int LtCount = st[id].freq[u - 1], RtCount = st[id].freq[v];
    int mid = (l + r) >> 1;

    return kOrLess(st[id].idLeft, l, mid, LtCount + 1, RtCount, k) + kOrLess(st[id].idRight, mid + 1, r, u - LtCount, v - RtCount, k);
}

int kth(int id, int l, int r, int u, int v, int k) {
    if (l == r) return l;

    int LtCount = st[id].freq[u - 1], RtCount = st[id].freq[v];
    int mid = (l + r) >> 1;

    if (RtCount - LtCount >= k) return kth(st[id].idLeft, l, mid, LtCount + 1, RtCount, k);
    else return kth(st[id].idRight, mid + 1, r, u - LtCount, v - RtCount, k - RtCount + LtCount);
}