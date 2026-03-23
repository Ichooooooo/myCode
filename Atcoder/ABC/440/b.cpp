#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n; cin >> n;
    vector<PII> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i].first; 
        a[i].second = i;
    }
    sort(a.begin() + 1, a.end(), [](PII x, PII y) {
        return x.first < y.first;
    });
    cout << a[1].second << ' ' << a[2].second << ' ' << a[3].second << a[4].second <<  endl;
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