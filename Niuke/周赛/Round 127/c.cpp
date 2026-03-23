#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    string n, ans;
    cin >> n;
    size_t mn = LLONG_MAX;
    for (int i = 5; i <= 9; i ++) {
        char j = i + '0';
        // cout << i << ' ';
        size_t pos = n.find(j);
        if (pos != string :: npos) {
            // cout << pos << endl;
            mn = min(mn, pos);
        }
    }
    // cout << mn << endl;
    if (mn == LLONG_MAX) {
        ans = n;
        ans[n.size() - 1] = '0';
        cout << ans << endl;
    } else if (mn == 0) {
        cout << '1';
        for (int i = 0; i < n.size(); i ++) cout << '0';
        cout << endl;
    } else {
        ans += n.substr(0, mn);
        ans[mn - 1] = ans[mn - 1] + 1;
        cout << ans;
        for (int i = mn; i < n.size(); i ++) {
            cout << '0';
        }
        cout << endl;
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