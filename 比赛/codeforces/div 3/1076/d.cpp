#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n; cin >> n;
    
    vector <int> a (n + 1), b(n + 1), pre (n + 1);
    for (int i = 1; i <= n; i ++)  cin >> a[i];
    for (int i = 1; i <= n; i ++)  {
        cin >> b[i];
        pre[i] = pre[i - 1] + b[i];
    }

    int mx = upper_bound(pre.begin() + 1, pre.end(), n) - pre.begin() - 1;
    // cout <<  'o' << mx << endl;

    ranges :: sort (a | views :: drop(1));
    reverse (a.begin() + 1, a.end());

    int ans = LLONG_MIN;
    for (int i = 1; i <= mx; i ++) {
        ans = max (i * a[pre[i]], ans);
        // cout << i * a[pre[i]] << ' ';
    }

    cout << ans << endl;
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