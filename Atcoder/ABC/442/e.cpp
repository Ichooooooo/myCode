#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, q;  cin >> n >> q;
    vector <int> fi, se, th, fo; fi.reserve(n); se.reserve(n); th.reserve(n); fo.reserve(n);

    int x, y, k;
    while (n --) {
        cin >> x >> y;
        if (x >= 0 && y >= 0) {
            if (x == 0) {
                k = LLONG_MAX;
            } else {
                k = y / x;
            }
        }
    }
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