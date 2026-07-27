#include <bits/stdc++.h>
// #include <ext/rope>
// #include <ext/pb_ds/assoc_container.hpp>

// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
using namespace std;

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

//-----------------------
// #define   ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define            ll long long
#define           ull unsigned long long
#define            db double
#define            ld long double
#define            pb push_back
#define            pf push_front
#define            mp make_pair
#define      mem(f,x) memset(f, x, sizeof(f))
#define   __lcm(a, b) (1ll * a * b) / __gcd(a, b)
#define  bit(mask, i) ((mask >> i) & 1)
#define           pii pair<int, int>
#define           pll pair<ll, ll>
#define            el '\n'
#define             F first
#define             S second
#define         io(x) freopen(x".inp","r",stdin),freopen(x".out","w",stdout)
//-----------------------
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const int MULTI = 0;
const int dx[4]{0, 1, 0, -1}, dy[4]{1, 0, -1, 0}; // R D L U
const int ddx[4]{-1, 1, 1, -1}, ddy[4]{1, 1, -1, -1}; // UR DR DL UL
const char cx[4]{'R', 'D', 'L', 'U'};
const ll base = 31;
const int nMOD = 2;
const ll mods[] = {(ll)1e9 + 3, (ll)1e9 + 3777, (ll)1e9 + 10777, (ll)1e9 + 19777};

const int maxn = 1e5 + 5;
int n, m, k, req[maxn], showers[maxn][3], ans[maxn], l[maxn], r[maxn];
vector<int> stations[maxn], queries[maxn];

struct BIT {
    ll bit[maxn];

    void init() {
        for (int i = 1; i <= m; ++i)
            bit[i] = 0;
    }

    void upd(int id, ll val) {
        for (; id <= m; id += id & -id)
            bit[id] += val;
    }

    void update(int l, int r, ll val) {
        if (r < l) {
            update(1, r, val);
            r = m;
        }

        upd(l, val); upd(r + 1, -val);
    }

    ll get(int id) {
        ll ret = 0;
        for (; id > 0; id -= id & -id)
            ret += bit[id];
        return ret;
    }

    ll range(int l, int r) {
        return get(r) - get(l - 1);
    }
};

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x; cin >> x;
        stations[x].pb(i);
    }
    for (int i = 1; i <= n; ++i)
        cin >> req[i];
    cin >> k;           
    for (int i = 1; i <= k; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> showers[i][j];

    for (int i = 1; i <= n; ++i) {
        ans[i] = INF;
        l[i] = 1; r[i] = k;
    }

    while (true) {
        for (int i = 1; i <= k; ++i)
            queries[i].clear();

        bool all_answered = true;

        for (int i = 1; i <= n; ++i) {
            if (l[i] > r[i]) continue;
            all_answered = false;
            queries[l[i] + r[i] >> 1].pb(i);
        }

        if (all_answered) break;

        BIT meteors; meteors.init();

        for (int mid = 1; mid <= k; ++mid) {
            meteors.update(showers[mid][0], showers[mid][1], showers[mid][2]);

            for (auto &state: queries[mid]) {
                ll gathered = 0;

                for (auto &station: stations[state]) {
                    gathered += meteors.get(station);
                    if (gathered >= LINF) break;
                }

                if (gathered >= req[state]) {
                    ans[state] = min(ans[state], mid);
                    r[state] = mid - 1;
                } else l[state] = mid + 1;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << (ans[i] == INF ? -1 : ans[i]) << el;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif

    if (!MULTI) solve();
    else {
        int test; cin >> test;
        while (test--) solve();
    }
    
    return 0;
}