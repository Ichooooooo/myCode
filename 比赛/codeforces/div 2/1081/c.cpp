
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, h, k; 
    cin >> n >> h >> k;

    vector <int> a (n + 6), pre (n + 6), premn(n + 6), aftmx(n + 6);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    premn[1] = a[1];
    for (int i = 2; i <= n; i ++) {
        premn[i] = min (premn[i - 1], a[i]);
    }
    aftmx[n] = a[n];
    for (int i = n - 1; i >= 1; i --) {
        aftmx[i] = max (aftmx[i + 1], a[i]);
    }

    int ans = 0, res = 0;
    ans = (h / pre[n]) * n + (h / pre[n] - 1) * k;
    res = h % pre[n];
    if (res == 0) {
        cout << ans << '\n';
        return;
    }

    ans += k;
    int mn = lower_bound(pre.begin(), pre.begin() + n + 1, res) - pre.begin();

    // cout <<  << '\n';

    for (int i = 1; i <= n; i ++) {
        if (premn[i] >= aftmx[i + 1]) continue;
        int ch = aftmx[i + 1] - premn[i];

        // cout << ch << ' ';

        if (pre[i] + ch >= res) {
            mn = min (mn, i);
            break;
        }
    }

    ans += mn;
    cout << ans << '\n';
    
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}