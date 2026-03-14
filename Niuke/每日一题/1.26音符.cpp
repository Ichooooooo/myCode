#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, q;  cin >> n >> q;
    vector <int> b (n + 1), pre(n + 1);

    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
        if (i == 1) pre[i] = b[i] - 1;
        else pre[i] = pre[i - 1] + b[i];
    }

    int t;
    while (q --) {
        cin >> t;
        int p = lower_bound(pre.begin() + 1, pre.end(), t) - pre.begin();
        cout << p << endl;
    }
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