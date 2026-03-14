#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int n; cin >> n;
    
    int u, v; 
    vector <int> cnt (n + 1);
    for (int i = 0; i < n - 1; i ++) {
        cin >> u >> v;
        cnt[u] ++;
        cnt[v] ++;
    }

    ranges :: sort (cnt);
    // for (int & I : cnt) cout << I << ' ';
    if (lower_bound(cnt.begin() + 1, cnt.end(), 4) != cnt.end()) {
        cout << 0 << '\n';
    } else {
        int pos = lower_bound(cnt.begin() + 1, cnt.end(), 3) - cnt.begin();
        cout << pos - 1 << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}