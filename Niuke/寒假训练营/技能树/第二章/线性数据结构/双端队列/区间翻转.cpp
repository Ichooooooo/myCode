#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, k; cin >> n >> k;

    deque <int> dq;
    
    for (int i = 1; i <= n; i ++) {
        dq.push_back(i);
    }

    int l, r, ok = 0, pas = 1;
    while (k --) {
        cin >> l >> r;
        if (!ok) {
            for (int i = pas; i < l; i ++) cout << i << ' ';
        } else {
            for (int i = l - 1; i >= pas; i --) cout << i << ' ';
        }
        pas = l;
        ok ^= 1;
    }

    if (!ok) {
        for (int i = pas; i <= n; i ++) cout << i << ' '; 
    } else {
        for (int i = n; i >= pas; i --) cout << i << ' ';
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