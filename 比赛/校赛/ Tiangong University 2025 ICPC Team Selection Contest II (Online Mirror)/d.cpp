
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

const int N = 5e5 + 10;
int tree[4 * N];
int a[N];

void sadd (int p, int l, int r, int x, int y, int z) {
    if (x > r || y < l) return;

    int mid = l + (r - l) / 2;
    if (l == r) {
        tree[p] = (tree[p] + z) % mod;
        return;
    }

    if (y <= mid) {
        sadd(2 * p, l, mid, x, y, z);
    } else if (x >= mid + 1) {
        sadd(2 * p + 1, mid + 1, r, x, y, z);
    } else {
        sadd(2 * p, l , mid, x, mid, z);
        sadd(2 * p + 1, mid + 1, r, mid + 1, y, z);
    }

    tree[p] = (tree[2 * p] + tree[2 * p + 1]) % mod;
}

int ssum (int p, int l, int r, int x, int y) {
    if (x <= l && y >= r) return tree[p];
    if (x > r || y < l) return 0;

    int mid = l + (r - l) / 2;
    if (y <= mid) {
        return ssum (2 * p, l, mid, x, y) % mod;
    } else if (x > mid) {
        return ssum (2 * p + 1, mid + 1, r, x, y) % mod;
    } else {
        return (ssum (2 * p, l, mid, x, mid) + ssum (2 * p + 1, mid +1, r, mid + 1, y)) % mod;
    }
}


void ovo(){   
    int n; cin >> n;
    vector <int> a (n +1), rk (n + 1);

    vector <int> b;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        b.push_back(a[i]);
    }

    ranges :: sort(b);
    b.erase(unique(b.begin(), b.end()), b.end());

    for (int i = 1; i <= n; i ++) {
        rk[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
    }

    int m = b.size();
    vector <int> dpl (n + 1);
    // 求dp和
    for (int i = 1; i <= n; i ++) {
        // 求和
        int pre = 0;
        if (rk[i] > 1) pre = ssum(1, 1, m, 1, rk[i] - 1);
        dpl[i] = (pre + 1) % mod;

        sadd (1, 1, m, rk[i], rk[i], dpl[i]);
    }

    vector <int> dpr (n + 1);
    memset(tree, 0, sizeof(tree));

    // 反向求和
    for (int i = n; i >= 1; i --) {
        
        int pre = 0;
        if (rk[i] < m) pre = ssum (1, 1, m, rk[i] + 1, m);

        dpr[i] = (pre + 1) % mod;

        sadd (1, 1, m, rk[i], rk[i], dpr[i]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans = (ans + ((dpl[i] * dpr[i]) % mod * a[i]) % mod) % mod;
    }

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}