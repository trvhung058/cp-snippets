class wavelet_tree {
public:
    int low, high;
 
    wavelet_tree *l, *r;
 
    vector<int> freq;
 
    wavelet_tree(int *from, int *to, int x, int y) {
        low = x; high = y;
 
        if (from >= to) return;
 
        if (high == low) {
            freq.reserve(to - from + 1);
            freq.pb(0);
            for (auto it = from; it != to; it++)
                freq.pb(freq.back() + 1);
            return;
        }
 
        int mid = (low + high) >> 1;
        auto lessThanMid
            = [mid](int x) { return x <= mid; };
 
        freq.reserve(to - from + 1); freq.pb(0);
        for (auto it = from; it != to; it++)
            freq.pb(freq.back() + lessThanMid(*it));
 
        auto pivot = stable_partition(from, to, lessThanMid);
 
        l = new wavelet_tree(from, pivot, low, mid);
        r = new wavelet_tree(pivot, to, mid + 1, high);
    }
 
    int kOrLess(int l, int r, int k) {
        if (l > r || k < low) return 0;
        if (high <= k) return r - l + 1;
 
        int LtCount = freq[l - 1], RtCount = freq[r];
 
        return this -> l -> kOrLess(LtCount + 1, RtCount, k) + this -> r -> kOrLess(l - LtCount, r - RtCount, k);
    }
    
    int kth(int l, int r, int k) {
        if (low == high) return low;

        int LtCound = freq[l - 1], RtCount = freq[r];

        if (RtCount - LtCount >= k) return this -> l -> kth(LtCount + 1, RtCount, k);
        else return this -> r -> kth(l - LtCount, r - RtCount, k - RtCount + LtCount);
    }
};


int high = 0;
for (int i = 0; i < n; ++i)
    maximize(high, a[i]);
 
wavelet_tree wt(a, a + n, 1, high);