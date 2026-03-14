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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    
    vector<int> fi(n + 1, 1), gi(n + 1, 1);
    for (int i = 1; i <= n; i ++) {
        for (int j = i; j >= 1; j --) {
            if(a[i] > a[j]) fi[i] = max(fi[i], fi[j] + 1);
        }
    }
    for (int i = n; i >= 1; i --) {
        for (int j = i + 1; j <= n; j ++) {
            if(a[i] > a[j]) gi[i] = max(gi[i], gi[j] + 1);
            // cout << gi[i] << ' ';
        }
    }
    
    // for(int & i : gi) cout << i << ' ';
    ll mx = 1;
    for (int i = 1; i <= n; i ++) {
        mx = max(mx, fi[i] + gi[i] - 1);
    }
    cout << n - mx << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}