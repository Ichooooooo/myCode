#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;
const int N = 2 * 1e5;
int tree[4 * N];
int a[N];

void build (int p, int l, int r) {
    if (l == r) {
        tree[p] = a[l];
        return;
    }
    int mid = l + (r - l) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
}

ll ssum(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) return tree[p];
    //上面是完整包含的情况
    if (x > r || y < l) return 0;
    int mid = l + (r - l) / 2;
    if (y <= mid) return ssum(2 * p, l , mid, x, y);
    if (x > mid) return ssum(2 * p + 1, mid + 1, r, x, y);
    return ssum(2 * p, l, mid, x, mid) + ssum(2 * p + 1, mid + 1, r, mid + 1, y);
}

//修改某个数的值，加上k
void change (int p, int l, int r, int pos, int k) {
    if (l == r) {
        tree[p] += k; a[pos] += k;
        // cout << tree[p] << ' ';
        return;
    }
    int mid = l + (r - l) / 2;
    if (pos <= mid) change (2 * p, l, mid, pos, k);
    else if(pos > mid) change (2 * p + 1, mid + 1, r, pos, k);
    tree[p] = tree[2 * p] + tree[2 * p + 1];
    //递归一直往下，直到return后开始回溯向上，所以修改成立
}

void solve(){   
    int n, q;  cin >> n >> q;

    for (int i = 1; i <= n; i ++) cin >> a[i];

    build (1, 1, n);

    // for (int i = 1; i <= 4 * n; i ++ ) cout << tree[i] << ' ';
    int opt, x, l, r;
    while (q --) {
        cin >> opt;
        if (opt == 1) {
            cin >> x;
            int b = a[x + 1], c = a[x];
            change (1, 1, n, x, b - c);
            change (1, 1, n, x + 1, c - b);
            // cout << endl;
        } else {
            cin >> l >> r;
            cout << ssum(1, 1, n, l, r) << endl;
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