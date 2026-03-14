#### 最基础线段树
如题，已知一个数列 {a_i}，你需要进行下面两种操作：
1. 将某区间每一个数加上 k。
2. 求出某区间每一个数的和。

其中**求和**部分的执行逻辑

```kotlin
f(2)
 ├─ f(1)
 │   ├─ f(0) → return 1
 │   └─ f(0) → return 1
 │   f(1) return 1+1 = 2
 └─ f(1)
     ├─ f(0) → return 1
     └─ f(0) → return 1
     f(1) return 1+1 = 2

f(2) return 2+2 = 4
```

```cpp
#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;
const int N = 1e5;
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

// l, r代表当前线段树所在的区间, x, y引导线段树递归
void sadd (int p, int l, int r, int x, int y, int z) {
    // 判断是否无交集, 没有则不需要递归
    if (x > r || y < l) return;

    int mid = l + (r - l) / 2;
    if (l == r) {
        tree[p] += z;
        return;
    }
    if (y <= mid) {
        sadd(p * 2, l, mid, x, y, z);
    } else if (x >= mid + 1) {
        sadd(p * 2 + 1, mid + 1, r, x, y, z);
    } else {
        sadd(p * 2, l, mid, x, mid, z);
        sadd(p * 2 + 1, mid + 1, r, mid + 1, y, z);
    }
    tree[p] = tree[2 * p] + tree[2 * p + 1];
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
        tree[p] += k;
        return;
    }
    int mid = l + (r - l) / 2;
    if (pos <= mid) change (2 * p, l, mid, pos, k);
    else if(pos > mid) change (2 * p + 1, mid + 1, r, pos, k);
    tree[p] = tree[2 * p] + tree[2 * p + 1];
    //递归一直往下，直到return后开始回溯向上，所以修改成立
}

void solve(){   
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++) cin >> a[i];
    build(1, 1, n);
    // for (int & i : tree) cout << i << ' ';
    ll t, x, y, k;
    while (m --) {
        cin >> t;
        if (t == 1) {
            cin >> x >> y >> k;
            sadd(1, 1, n, x, y, k);
        } else if (t == 2) {
            cin >> x >> y;
            cout << ssum(1, 1, n, x, y) << endl;
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
```