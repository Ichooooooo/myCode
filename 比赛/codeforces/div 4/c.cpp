#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    
    sort(a.begin() + 1, a.end());
    a.erase(unique(a.begin() + 1, a.end()), a.end());

    int mx = 1, cur = 1;
    for (int i = 2; i < a.size(); i ++) {
        // cout << a[i] << ' ';
        if (a[i] != (a[i - 1] + 1)) {
            // cout << cur << ' ';
            mx = max(mx, cur);cur = 1;
        } else {
            cur ++;
        }
    }
    mx = max(mx, cur);

    cout << mx << endl;
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