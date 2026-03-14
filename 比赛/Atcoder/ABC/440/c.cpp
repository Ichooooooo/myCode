#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, w;
    cin >> n >> w;
    vector <int> a(n + 1);
    vector <int> b(2 * w);
    int m = 2 * w;

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        b[i % m] += a[i];
    }

    // for (int & i : b) cout << i << ' ';
    int mn, cur, pas;
    mn = accumulate(b.begin(),b.begin() + w, 0LL);  
    pas = mn;
    
    // cout << mn << endl; 

    for (int i = 1; i < 2 * w; i ++) {  
        cur = pas - b[i - 1] + b[(i + w - 1) % m];
        // cout << (i + w - 1) % m << ' ' << b[i - 1] << ' ' << b[(i + w - 1) % m] << ' ' << cur << endl;
        mn = min (cur, mn);
        pas = cur;
    }

    cout << mn << endl;
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