#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, s, x;
    cin >> n >> s >> x;
    vector <int> a (n + 1);

    for (int i = 1; i <= n; i ++) cin >> a[i];

    int sum = accumulate(a.begin() + 1, a.end(), 0LL);

    if (s - sum >= 0 && (s - sum) % x == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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