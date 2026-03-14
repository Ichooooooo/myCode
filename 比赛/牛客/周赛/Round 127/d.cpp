#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

int zhs (int k) {
    return (k * (k - 1) / 2) % mod;
}

void solve(){   
    int n;
    cin >> n;
    vector <int> a (n + 1);
    int t;
    for (int i = 1; i <= n; i ++) {
        cin >> t;
        if (t <= n)  a[t] ++;
    }
    
    int ans = 0, pos = 0, dt = 1;
    for (int i = 1; i <= n; i ++) {
        if (a[i] < 2) {
            
            pos = i;
            // cout << "pos : " << pos << endl;
            break;
        } else {
            // cout << a[i] << ' ';
            a[i] = zhs(a[i]);
            // cout << a[i] << ' ';
        }
    }

    for (int i = 1; i < pos; i ++) {
        dt = dt * a[i] % mod;
        ans = (ans + dt) % mod;
        // cout << dt << ' ' << ans << ' ';
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