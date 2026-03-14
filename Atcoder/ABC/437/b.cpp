#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, m, k;
    cin >> n >> m >> k;
    unordered_map<int, int> mp;
    
    int t;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> t;
            mp[t] = i;
        }
    }

    vector<int> cnt(n + 1, 0);
    while (k --) {
        cin >> t;
        cnt[mp[t]] ++;
    }

    cout << *max_element(cnt.begin() + 1, cnt.end()) << endl;
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