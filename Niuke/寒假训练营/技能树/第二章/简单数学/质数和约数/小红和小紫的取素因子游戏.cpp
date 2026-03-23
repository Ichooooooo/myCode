#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int x; cin >> x;
    if (x == 1) {
        cout << "yukari" << endl;
        return;
    }
    int cnt = 0, ok = 0;
    
    for (int i = 2; i * i <= x; i ++) {
        if (x % i == 0) {
            ok = 1;
            break;
        }
    }
    if (!ok) {
        cout << "kou" << endl;
        return;
    }
    int y = x;
    for (int i = 2; i <= x; i ++) {
        while (y % i == 0) {
            y /= i;
            cnt ++;
            // cout << i << ' ';
        }
        if (y == 1) break;
    } 
    if (cnt & 1) cout << "kou" << endl;
    else cout << "yukari" << endl;
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