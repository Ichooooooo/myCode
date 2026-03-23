#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;
const int MAX = 3000;

ll check(int n) {
    ll m = 0;
    while(n) {
        m += (n % 10) * (n % 10);
        n /= 10;
    }
    return m;
}

void solve(){   
    int n;
    cin >> n;
    
    vector<int> vis(MAX, 1);
    while (vis[n] && n != 1) {
        vis[n] = 0;
        n = check(n);
        // cout << n << ' ';
    }
    // cout << endl;    
    if (n == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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