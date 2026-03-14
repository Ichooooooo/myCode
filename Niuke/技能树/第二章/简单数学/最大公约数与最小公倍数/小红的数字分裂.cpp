#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n; cin >> n;
    vector <int> a (n + 1);
    int gc = 0, sum = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i]; gc = gcd (gc, a[i]);
    }

    sum = accumulate(a.begin() + 1, a.end(), 0LL);
    cout << sum / gc - n << endl;
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