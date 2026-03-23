#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n; cin >> n;

    vector <PII> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    ranges :: sort (a | views :: drop(1));

    int cnt = (n + 1) / 2;
    
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