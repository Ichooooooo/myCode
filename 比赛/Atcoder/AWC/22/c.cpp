
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, m, k, t;
    cin >> n >> m >> k >> t;

    vector <int> vis (n + 1);
    int x;
    for (int i = 0; i < m; i ++) {
        cin >> x;
        vis[x] = 1;
    }

    vector <int> pre (n + 1);
    for (int i = 1; i <= n; i ++) {
        pre[i] = pre[i - 1] + vis[i];
        // cout << pre[i] << '\n';
    }

    int l, r;
    while (k --) {
        cin >> l >> r;
        int ch = pre[r] - pre[l - 1];
        if (ch >= t) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}