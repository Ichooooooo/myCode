#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, m; cin >> n >> m;
    vector <int> vis (n + 1);

    int a, b;
    while (m --) {
        cin >> a >> b;
        vis[a] ++; vis[b] ++;
    }

    auto zhs = [] (int x) -> int {
        if (x < 3) return 0;
        return (x * (x - 1) * (x - 2)) / 6;
    };

    for (int i = 1; i <= n; i ++) {
        cout << zhs (n - vis[i] - 1) << ' ';
    }
    
    cout << endl;
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