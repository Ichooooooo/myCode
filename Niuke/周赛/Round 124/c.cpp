#include<bits/stdc++.h>
#define pi acos(-1)
#define fi first 
#define se second 
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n;  i ++) cin >> a[i];
    
    if (m > n + 1) {
        cout << "NO" << endl;
        return;
    }

    ranges::sort(a);
    vector<pair<int, int>> b; b.reserve(n);
    int l = 1, r = 2;
    while (r <= n) {
        if (a[r] - a[r - 1] == 1) {
            r ++;
        } else {
            b.push_back({a[l], a[r - 1]});
            l = r;
            r ++;
        }
    }
    b.push_back({a[l], a[r - 1]});

    // for (auto &[a, b] : b) {
    //     cout << a << ' ' << b << endl;
    // }
    
    ll mx = -1, cur, len = b.size();
    for (int i = 1; i < b.size(); i ++) {
        if (b[i].fi - b[i - 1].se == 2) {
            cur = b[i].se - b[i - 1].fi + 1;
            mx = max(cur, mx);
        } else {
            cur = b[i - 1].se - b[i - 1].fi + 2;
            mx = max(mx, cur);
        }
        // cout << cur << ' ';
    }
    mx = max(b[len - 1].se - b[len - 1].fi + 2, mx);
    if (mx < m) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        solve();
    }
    return 0;
}