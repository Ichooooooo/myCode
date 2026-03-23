#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    ll n, q; cin >> n >> q;
    vector <ll> v(n + 2);
    for (int i = 1; i <= n; i++) cin >> v[i];

    vector <ll> s(n + 2), pre(n + 2), suf(n + 2);
    pre[1] = v[1];
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + v[i];
        if (i != 1) pre[i] = min(pre[i - 1], v[i]);
    }

    suf[n] = v[n];
    for (int i = n - 1; i >= 1; i--) {
        suf[i] = min(suf[i + 1], v[i]);
    }

    ll l = 0, r = n + 1;
    ll lmn = v[1], rmn = v[n];
    ll sl = 0, sr = 0;
    while (q--) {
        ll a; cin >> a;
        if (a == 1) {
            ll t; cin >> t;
            if (t > l) {
                lmn = min(lmn, pre[t]);
                sl = lmn * t;
                l = t;
            }
            if (l >= r) {
                r = l + 1;
                lmn = min(lmn, rmn);
                sl = l * lmn;
                sr = (n - r + 1) * rmn;
            }
        }else if (a == 2) {
            ll t; cin >> t;
            if (t < r) {
                rmn = min(rmn, suf[t]);
                sr = rmn * (n - t + 1);
                r = t;
            }
            if (r <= l) {
                l = r - 1;
                rmn = min(rmn, lmn);
                sr = (n - r + 1) * rmn;
                sl = l * lmn;
            }
        }else if (a == 3) {
            cout << sl + sr + s[r - 1] - s[l] << '\n';
        }
    }   
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        solve();
    }
    return 0;
} 