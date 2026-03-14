
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, m, l;  cin >> n >> m >> l;
    vector <int> a (n + 1), pre (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    vector <int> b (m + 1);
    for (int i = 1; i <= m; i ++) cin >> b[i];
    int now = 0;
    for (int i = 0; i <= m; i ++) {
        now += b[i];
        int p1 = upper_bound(pre.begin(), pre.end(), now) - pre.begin();
        int p2 = upper_bound(pre.begin(), pre.end(), now + l) - pre.begin();
        // cout << now << ' ' << p1 << ' ' << p2 << '\n';
        if (p2 - p1 == 1 && pre[p1] == (now + l)) {
            continue;
        } else if (p1 != p2) {
            cout << "YES" << '\n';
            return;
        }
    }

    cout << "NO" << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}