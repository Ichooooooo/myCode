#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;
const int N = 1e5;
int a[N];
int tree[4 * N];
int lazy[4 * N];

void build (int p, int l, int r) {
    if (l == r) {
        tree[p] = a[l];
        return;
    }

    int mid = l + (r - l) / 2;
    build (2 * p, l , mid);
    build (2 * p + 1, mid + 1, r);
    tree[p] = tree[2 * p] + tree[2 * p + 1];
}

void pushdown(int p, int l, int r) {
    if (l == r) return;
    int mid = l + (r - l) / 2;
    lazy[2 * p] += lazy[p];
    lazy[2 * p + 1] += lazy[p];
    tree[2 * p] += (mid - l + 1) * lazy[p];
    tree[2 * p + 1] += (r - (mid + 1) + 1) * lazy[p];
    lazy[p] = 0;
}

void change (int p, int l, int r, int x, int y, int z)  {
    //
    if (x <= l && r <= y) {
        tree[p] += z * (r - l + 1);
        lazy[p] += z;
        return;
    }

    int mid = l + (r - l) / 2;
    if (lazy[p] != 0) {
        pushdown(p, l, r);
    }
    
    if (x <= mid) change (2 * p, l, mid, x, y, z);
    if (y > mid) change (2 * p + 1, mid + 1, r, x, y, z);
    tree[p] = tree[2 * p] + tree[2 * p + 1];
}

ll check(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) return tree[p];

    int mid = l + (r - l) / 2;
    if (lazy[p] != 0) {
        pushdown(p, l, r);
    }
    
    if (y <= mid) return check(2 * p, l, mid, x, y);
    if (x > mid) return check(2 * p + 1, mid + 1, r, x, y);
    return check (2 * p, l, mid, x, mid) + check(2 * p + 1, mid + 1, r, mid + 1, y);
}
void solve(){   
    int n, m;
    cin >> n >> m;
    
    memset(lazy, 0, sizeof lazy);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    build(1, 1, n);

    int t;
    int x, y, z;
    while (m --) {
        cin >> t;
        if (t == 1) {
            cin >> x >> y >> z;
            change(1, 1, n, x, y, z);
        } else if (t == 2) {
            cin >> x >> y;
            cout << check(1, 1, n, x, y) << endl;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}