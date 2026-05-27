#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;  cin >> n;

    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];

    if (n == 1) {
        cout << -1 << endl;
        return;
    }

    vector <int> b = a;
    ranges :: sort (b | views :: drop(1));
    // ranges :: reverse (b | views :: drop(1));

    int ans = LLONG_MAX, x = b[1], y = b[n];
    for (int i = 1; i <= n; i ++) {
        if (a[i] != b[i]) {
            ans = min (ans, max (a[i] - x, y - a[i]));
        }
    }

    if (ans == LLONG_MAX)  {
        cout << -1 << endl;
        return;
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