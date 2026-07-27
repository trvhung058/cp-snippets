int query(int id, int l, int r, int u, int v, int x) {
    if (r < u || l > v) return -1;
    if (st[id] > x) return -1;
    if (l == r) return l;

    int mid = (l + r) >> 1; push(id);
    int res = -1;

    if (st[id << 1] <= x)
        res = query(id << 1, l, mid, u, v, x);

    if (res == -1) 
        res = query(id << 1 | 1, mid + 1, r, u, v, x);
        
    return res;
}