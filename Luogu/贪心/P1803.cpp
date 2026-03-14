#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;
    cin >> n;
    PII bs[n + 1];
    for (int i = 1; i <= n ; i ++) {
        cin >> bs[i].first >> bs[i].second;
    }

    sort(bs + 1, bs + n + 1, [](PII a, PII b){
        return a.second < b.second;
    });

    ll r = bs[1].second, ans = 1;
    for (int i = 2; i <= n; i ++) {
        auto [a, b] = bs[i];    
        if (a >= r) {
            r = b;
            ans ++;
        }
    }

    cout << ans << endl;
}

void solve2() {
    int n;
    cin >> n;
    vector<array<ll, 2>> seg(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> seg[i][0] >> seg[i][1];
    }

    vector<int> a(2 * n + 1);
    for (int i = 1; i <= n; i ++) {
        a[i * 2 - 1] = seg[i][0];
        a[i* 2] = seg[i][1];
    }

    sort(a.begin() + 1, a.end());
    a.erase(unique(a.begin() + 1, a.end()), a.end());

    auto id = [&] (int x) {
        return lower_bound(a.begin() + 1, a.end(), x) - a.begin();
    };
    vector<int> diff(a.size());
    for (int i = 1; i <= n; i ++) {
        int x = seg[i][0];
        int y = seg[i][1];
        diff[id(x)] ++;
        diff[id(y)] --;   // 半开区间 [l, r)
    }

    ll cur = 0, ans = 0;
    for (int i = 1; i + 1 < a.size(); i ++) {
        cur += diff[i];
        if (cur > 0)
            ans += a[i + 1] - a[i];  
    }

    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve2();
    }
    return 0;
}