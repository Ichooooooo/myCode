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
    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    auto dg = [&] (int m) -> int {
        for (int i = 1; i <= m - 1; i ++) {
            a[i] = abs (a[i] - a[i + 1]);
        }
        return m - 1;
    };

    int ans = n;
    while (ans != 1) {
        ans = dg(ans);
    }

    cout << a[1] << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}