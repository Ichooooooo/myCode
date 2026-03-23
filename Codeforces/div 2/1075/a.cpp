#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, h, l;
    cin >> n >> h >> l;
    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];

    ranges :: sort (a | views :: drop(1));
    int mn = min(h, l), mx = max (h, l);
    auto pos1 = upper_bound(a.begin() + 1, a.end(), mn);
    auto pos2 = upper_bound(a.begin() + 1, a.end(), mx);
    if (pos1 == a.end()) {
        cout << n / 2 << endl;
    } else {
        int n1 = pos1 - a.begin() - 1, n2 = pos2 - a.begin() - 1;
        if (n2 >= 2 * n1) {
            cout << n1 << endl;
        } else {
            cout << n2 / 2 << endl;
        }
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