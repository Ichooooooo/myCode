
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, k, q;
    cin >> n >> k >> q;

    vector <int> ans (n + 1), vis (n + 1);

    vector <array<int, 2>> yh;

    int opt, l, r;
    for (int i = 0; i < q; i ++) {
        cin >> opt >> l >> r;
        if (opt == 1) {
            for (int i = l ; i <= r; i ++) {
                // min, unused target
                if (vis[i] != 1) vis[i] += 1;
            }
        } else if (opt == 2) {
            for (int i = l; i <= r; i ++) {
                if (vis[i] < 2) vis[i] += 2;
            }
            yh.push_back({l, r});
        }
    }

    for (int i = 1; i <= n; i ++) {
        if (!vis[i]) ans[i] = 1;
        else if (vis[i] == 1) ans[i] = k;
        else if (vis[i] == 3) ans[i] = k + 1;
    }

    ranges :: sort (yh);
    for (int i = 0; i < yh.size(); i ++) {
        auto [l, r] = yh[i];
        for (int i = l; i <= r; i ++) {
            if (!ans[i]) ans[i] = i % k;
        }
    }

    for (int i = 1; i <= n; i ++) cout << ans[i] << " \n"[i == n];
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}