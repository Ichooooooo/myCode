#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

bool cmp (pair<string, int> a, pair<string, int> b) {
    if(a.second != b.second) return a.second > b.second;
    return 0;
}

void solve(){   
    int n, m;
    cin >> n >> m;
    ll cnt = 0; string s;
    
    vector<pair<string, int>> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i].first >> a[i].second;
        if(a[i].second >= m) cnt ++;
    }
    sort(a.begin() + 1, a.end(), cmp);
    cout << cnt << endl;
    cout << a[1].first << endl;
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